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

#ifndef __SHTC3_H__
#define __SHTC3_H__

#define SHTC3_ADDR (0x70 << 1)


void shtc3_request();
void shtc3_read(int8_t *temp, int8_t *hum);
// Request, wait and read temperature and humidity from the sensor
void shtc3_get(int8_t *temp, int8_t *hum);

#endif /* __SHTC3_H__ */

