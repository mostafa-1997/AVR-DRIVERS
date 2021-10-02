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

#include "SevenSegment_config.h"
#include "SevenSegment_interface.h"


extern SSG_t SevenSegment_AstrSSGConfig[ SEVENSEGMENT_u8NUM ];

int main()
{

	SevenSegment_enuInit(SevenSegment_AstrSSGConfig);

	while(1)//super loop system
	{
		SevenSegment_enuDisplay(&SevenSegment_AstrSSGConfig[1],5);

		SevenSegment_enuDisplay(&SevenSegment_AstrSSGConfig[0],8);
	}

	return 0;
}
