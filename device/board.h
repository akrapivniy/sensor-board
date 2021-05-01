#ifndef __BOARD_H__
#define __BOARD_H__

#include "uuid.h"

//PIR sensor is connected
#define TM_PIR

//Needs to send a message if the PIR sensor status is HI
//#define TM_SEND_PIR  1

//Needs to send temperature multiplay by 4
//#define SHTC3_TEMP_PREC

//The SSD1306 display is connected
#define SSD1306  1

//The display has 32 lines instead 64
//#define SSD1306_TYPE32

//The display switch off after 
#define SSD1306_ACTIVE_SEC 60

//Up-side-down the display
#define SSD1306_ROTATE180 1

//The display contrast value
#define SSD1306_CONTRAST 255

//The device can be gateway to anther SMESH network
//#define GATEWAY  1

//Low power device, doesn't need to have network address, doesn't retranslate the messages
//#define LOWPOWER  1

//Skip to wake up each network sessions
#define SMESH_DEVICE_ACTIVE_FACTOR 2

//Include a garbage schedule information
//#define MULL_STATIC  1

//Enable debug information
//#define TM_DEBUG


#ifdef SHTC3_TEMP_PREC
#undef TM_DEBUG
#endif

#endif /* __BOARD_H__ */

