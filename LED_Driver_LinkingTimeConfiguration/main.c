/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_interface.h"

#include "util/delay.h"

#include "LED_config.h"
#include "LED_interface.h"

extern LED_t LED_AstrLEDConfig[ LED_u8NUM ];


int main()
{

	LED_enuInit(LED_AstrLEDConfig);

	while(1)//super loop system
	{
		LED_enuSetLEDValue(&LED_AstrLEDConfig[0],DIO_u8HIGH);

		LED_enuSetLEDValue(&LED_AstrLEDConfig[1],DIO_u8LOW);

		LED_enuSetLEDValue(&LED_AstrLEDConfig[2],DIO_u8HIGH);
	}

	return 0;
}
