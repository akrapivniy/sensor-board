/**************************************************************  
 * SHTC3 driver that is of the sensor board project
 * Copyright (c) 2020 Alexander Krapivniy (a.krapivniy@gmail.com)
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************/
#include "stm8l.h"
#include "board.h"
#include "i2c.h"
#include "utils.h"
#include "shtc3.h"


void shtc3_request()
{
	i2c_write_addr8_data8(SHTC3_ADDR, 0x35, 0x17); //Wakeup the sensor
	tsleep(10000);
	i2c_write_addr8_data8(SHTC3_ADDR, 0x7C, 0xA2); //Just request the data
	return;
}

void shtc3_read(int8_t *temp, int8_t *hum)
{
	uint8_t data[6];
	int16_t raw_temp = 0;
	uint16_t raw_hum = 0;

	//Read temperature and humidity from the sensor
	i2c_read_data(SHTC3_ADDR, data, 6);
	raw_temp = ((uint16_t)data[0] << 8) | (uint16_t)data[1];
	raw_hum = ((uint16_t)data[3] << 8) | (uint16_t)data[4];

	//Convert temperature
	raw_temp = (((((((raw_temp / 8) * 7) / 8) * 5) / 8) * 5) / 16) - 360;
#ifdef SHTC3_TEMP_PREC
	*temp = (int16_t)((raw_temp + 2) / 4 - 40); 
#else
	*temp = (int16_t)((raw_temp + 4) / 8);      //change to higher accuracy
#endif
	//Convert humidity
	raw_hum = ((((((raw_hum / 8) * 5) / 8 ) * 5) + 128) / 256);
	*hum = raw_hum;
	i2c_write_addr8_data8((0x70 << 1), 0xb0, 0x98); //Send the command to sleep

	return;
}


#ifdef LINK_UNUSED
// Request, wait and read temperature and humidity from the sensor
void shtc3_get(int8_t *temp, int8_t *hum)
{
	shtc3_request ();
	tsleep(19000);	
	return shtc3_read (temp, hum);
}
#endif