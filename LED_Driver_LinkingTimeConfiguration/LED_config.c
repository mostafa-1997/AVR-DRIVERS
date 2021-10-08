/*
 * LED_config.c
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_interface.h"

#include "LED_config.h"
#include "LED_private.h"

u8 LED_u8LEDCount = LED_u8NUM;

LED_t LED_AstrLEDConfig[ LED_u8NUM ] =
{
		{DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8HIGH},
		{DIO_u8GROUP_A,DIO_u8PIN1,DIO_u8HIGH},
		{DIO_u8GROUP_A,DIO_u8PIN2,DIO_u8LOW}
};
