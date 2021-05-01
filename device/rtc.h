/**************************************************************  
 * Configuration file of the sensor board project
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
#ifndef __RTC_H__
#define __RTC_H__

#include "stm8l.h"

int8_t rtc_init(void);

void rtc_set_unlock();
void rtc_set_lock();

uint8_t rtc_getday();
uint8_t rtc_gethour();
uint8_t rtc_getmonth();
void rtc_gettime(uint8_t *hour, uint8_t *min, uint8_t *sec);
void rtc_getdate(uint8_t *day, uint8_t *mon, uint8_t *year);

void rtc_setdate(uint8_t day, uint8_t mon, uint8_t year);
void rtc_settime(uint8_t hour, uint8_t min, uint8_t sec);

void rtc_set_alarm(uint8_t hour, uint8_t min, uint8_t sec);
void rtc_set_hour_alarm(uint8_t min, uint8_t sec);

void rtc_alarm_start ();
void rtc_alarm_set_period(uint16_t sec);
void rtc_alarm_period_start ();
void rtc_alarm_period_off();
void rtc_alarm_off();

#endif /*__RTC_H__*/