/**************************************************************  
 * RTC driver for stm8l051 that is of the sensor board project
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
#include "utils.h"
#include "rtc.h"

static void rtc_unlock()
{
	RTC_WPR = 0xCA;
	RTC_WPR = 0x53;
}

static void rtc_lock()
{
	RTC_WPR = 0x00;
}

void rtc_set_unlock()
{
	rtc_unlock(); // Disable write protection of RTC registers
	set_bit(RTC_ISR1, RTC_ISR1_INIT); // Enter initialization mode
	// Poll INITF flag until it is set in RTC_ISR1.
	while (!(check_bit(RTC_ISR1, RTC_ISR1_INITF)));
}

void rtc_set_lock()
{
	clear_bit(RTC_ISR1, RTC_ISR1_INIT); // Exit initialization mode
	rtc_lock(); // Enable write protection of RTC registers	
}

// RTC initialization
int8_t rtc_init(void)
{
	uint8_t timeout = 0xff;

	while (check_bit(CLK_CRTCR, CLK_CRTCR_RTCSWBSY)); // Wait for RTCSWBSY flag to clear
	CLK_CRTCR = 0x10; // RTC clock: source LSE

	while (!(check_bit(CLK_ECKCR, CLK_ECKCR_LSERDY)) && timeout--); // Wait for LSE stabilization
	if (timeout == 0) {
		CLK_CRTCR = 04; // Enable LSI
	}
	set_bit(CLK_PCKENR2, CLK_PCKENR2_RTC); // Enable RTC peripherial (PCKEN22)

	rtc_set_unlock();
	RTC_SPRERH = 0x00;
	RTC_SPRERL = 0xFF;
	RTC_APRER = 0x7F;

	RTC_TR1 = 0x0;
	RTC_TR2 = 0x0;
	RTC_TR3 = 0x0;
	RTC_DR1 = 0x0;
	RTC_DR2 = 0x0;
	RTC_DR3 = 0x0;

	RTC_CR1 = 0x14;
	RTC_CR2 = 0x00;
	RTC_CR3 = 0x00;
	rtc_set_lock();

	return 0;
}

uint8_t bin2dec(uint8_t value)
{
	return((value / 10) << 4) | (value % 10);
}

uint8_t dec2bin(uint8_t value)
{
	return(((value >> 4) * 10) + (value & 0x0F));
}

void rtc_settime(uint8_t hour, uint8_t min, uint8_t sec)
{
	RTC_TR1 = bin2dec(sec);
	RTC_TR2 = bin2dec(min);
	RTC_TR3 = bin2dec(hour);
}

void rtc_setdate(uint8_t day, uint8_t mon, uint8_t year)
{
	RTC_DR1 = bin2dec(day);
	RTC_DR2 = bin2dec(mon);
	RTC_DR3 = bin2dec(year);
}

// Get the RTC current time
void rtc_gettime(uint8_t *hour, uint8_t *min, uint8_t *sec)
{
	*sec = dec2bin(RTC_TR1);
	*min = dec2bin(RTC_TR2);
	*hour = dec2bin(RTC_TR3 & 0x3f);
}

// Get the RTC current date
void rtc_getdate(uint8_t *day, uint8_t *mon, uint8_t *year)
{
	*day = dec2bin(RTC_DR1);
	;
	*mon = dec2bin(RTC_DR2 & 0x1F);
	*year = dec2bin(RTC_DR3);
}

uint8_t rtc_gethour()
{
	return dec2bin(RTC_TR3 & 0x3f);
}

#ifdef LINK_UNUSED
void rtc_set_alarm(uint8_t hour, uint8_t min, uint8_t sec)
{
	rtc_unlock();
	clear_bit(RTC_CR2, RTC_CR2_ALRAE);
	while (!check_bit(RTC_ISR1, RTC_ISR1_ALRAWF));
	RTC_ALRMAR1 = 0x80 | bin2dec(sec);
	RTC_ALRMAR2 = 0x80 | bin2dec(min);
	RTC_ALRMAR3 = 0x80 | bin2dec(hour);
	set_mask(RTC_CR2, mask(RTC_CR2_ALRAE) | mask(RTC_CR2_ALRAIE));
	rtc_lock();
}
#endif

void rtc_set_hour_alarm(uint8_t min, uint8_t sec)
{
	rtc_unlock();
	clear_bit(RTC_CR2, RTC_CR2_ALRAE);
	while (!check_bit(RTC_ISR1, RTC_ISR1_ALRAWF));
	RTC_ALRMAR1 = 0x0 | bin2dec(sec);
	RTC_ALRMAR2 = 0x0 | bin2dec(min);
	RTC_ALRMAR3 = 0x80;
	RTC_ALRMAR4 = 0xC0;
	set_mask(RTC_CR2, mask(RTC_CR2_ALRAE) | mask(RTC_CR2_ALRAIE));
	rtc_lock();
}

void rtc_alarm_start()
{
	rtc_unlock();
	set_mask(RTC_CR2, mask(RTC_CR2_ALRAE) | mask(RTC_CR2_ALRAIE));
	rtc_lock();
}


#ifdef LINK_UNUSED
void rtc_alarm_set_period(uint16_t sec)
{
	rtc_unlock();
	clear_bit(RTC_CR2, RTC_CR2_WUTE);
	while (!check_bit(RTC_ISR1, RTC_ISR1_WUTWF));
	RTC_WUTRH = (uint8_t) (sec >> 8);
	RTC_WUTRL = (uint8_t) sec;
	set_mask(RTC_CR2, mask(RTC_CR2_WUTE) | mask(RTC_CR2_WUTIE));
	rtc_lock();
}

void rtc_alarm_period_start()
{
	rtc_unlock();
	set_mask(RTC_CR2, mask(RTC_CR2_WUTE) | mask(RTC_CR2_WUTIE));
	rtc_lock();
}

void rtc_alarm_period_off()
{
	rtc_unlock();
	clear_mask(RTC_CR2, mask(RTC_CR2_WUTE) | mask(RTC_CR2_WUTIE));
	rtc_lock();
}

void rtc_alarm_off()
{
	rtc_unlock();
	clear_mask(RTC_CR2, mask(RTC_CR2_ALRAE) | mask(RTC_CR2_ALRAIE));
	rtc_lock();
}
#endif