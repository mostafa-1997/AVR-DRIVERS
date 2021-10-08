/*
 * Switch_config.c
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "Switch_config.h"
#include "Switch_private.h"

#include "DIO_interface.h"

u8 Switch_u8SwCounts = SWITCH_u8NUM;


SW_t Switch_AstrSwitchConfig[ SWITCH_u8NUM ] =
{
		{DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8FLOAT},
		{DIO_u8GROUP_B,DIO_u8PIN3,DIO_u8PULL_UP},
		{DIO_u8GROUP_C,DIO_u8PIN5,DIO_u8PULL_UP}
};
