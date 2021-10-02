/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_interface.h" //open layer cuz this makes me able to  access the MCAL layer directly

#include "util/delay.h"

#include "Switch_config.h"
#include "Switch_interface.h"

extern SW_t Switch_AstrSwitchConfig[SWITCH_u8NUM];

int main()
{

	u8 Local_u8Value;

	Switch_enuInit(Switch_AstrSwitchConfig);

	while(1)//super loop system
	{
		Switch_enuGetSwitchValue(&Switch_AstrSwitchConfig[0],&Local_u8Value);

		Switch_enuGetSwitchValue(&Switch_AstrSwitchConfig[1],&Local_u8Value);

		Switch_enuGetSwitchValue(&Switch_AstrSwitchConfig[2],&Local_u8Value);
	}

	return 0;
}
