/**************************************************************  
 * I2C driver for stm8l051 that is part of the sensor board project
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

#ifndef __I2C_H__
#define __I2C_H__

void i2c_init();
uint8_t i2c_ping (uint8_t addr);
uint8_t i2c_read_addr8_data8(uint8_t addr, uint8_t reg_addr);
uint16_t i2c_read_addr8_data16(uint8_t addr, uint8_t reg_addr);
uint8_t i2c_read_data(uint8_t addr, uint8_t *data, uint8_t size);
void i2c_write_addr8_data8(uint8_t addr, uint8_t reg_addr, uint8_t data);
void i2c_write_addr8_data(uint8_t addr, uint8_t reg_addr, uint8_t *data, uint8_t size);
void i2c_write_data(uint8_t addr, uint8_t *data, uint8_t size);

#endif /* __I2C_H__ */

