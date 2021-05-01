/**************************************************************  
 * Frequently used functions
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
#include "utils.h"

inline void tsleep (uint16_t tick)
{
    while (tick--)  __asm__("nop");
}

void bzero (uint8_t *dst, uint16_t size)
{
	while (size--)
		dst[size] = 0;
}

void umemcpy(uint8_t *dst, uint8_t *src, uint8_t size)
{
	while (size--)
	    *dst++ = *src++;
}