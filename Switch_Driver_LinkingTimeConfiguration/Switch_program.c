/*
 * Switch_program.c
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "Switch_config.h"
#include "Switch_private.h"

#include "DIO_interface.h"


ES_t Switch_enuInit(SW_t * Copy_pAstrSwitchConfig)
{
	ES_t Local_enuErrorState = ES_NOK;


	u8 Local_u8Iterator;
	for(Local_u8Iterator = 0;Local_u8Iterator<3;Local_u8Iterator++)
	{
		DIO_enuSetPinDirection(Copy_pAstrSwitchConfig[Local_u8Iterator].Switch_u8Group,Copy_pAstrSwitchConfig[Local_u8Iterator].Switch_u8Pin,DIO_u8INPUT);
		DIO_enuSetPinValue((Copy_pAstrSwitchConfig + Local_u8Iterator)->Switch_u8Group,(Copy_pAstrSwitchConfig + Local_u8Iterator)->Switch_u8Pin,(Copy_pAstrSwitchConfig + Local_u8Iterator)->Switch_u8State);
	}

	return Local_enuErrorState;
}

ES_t Switch_enuGetSwitchValue(SW_t * Copy_pstrSwitchInfo,u8 * Copy_u8pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = DIO_enuGetPinValue(Copy_pstrSwitchInfo->Switch_u8Group,Copy_pstrSwitchInfo->Switch_u8Pin,Copy_u8pu8Value);

	return Local_enuErrorState;
}

