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


ES_t Switch_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* I only have 4 error states that can be represented in 2 bits, here we choose the 16 bit data type just incase we
	 * have more cases. We wil get the error states of the two functions and put it in this new u16 local variable which if
	 * true must return the value 5,0000000000000101    */
	u16 Local_u16ErrorState = 0;

	Local_u16ErrorState = DIO_enuSetPinDirection(SWITCH_u8GROUP,SWITCH_u8PIN,DIO_u8INPUT);
	Local_u16ErrorState |= (DIO_enuSetPinValue(SWITCH_u8GROUP,SWITCH_u8PIN,SWITCH_u8STATE)) << 2;

	if(Local_u16ErrorState == 5)
	{
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

ES_t Switch_enuGetSwitchState(u8 * Copy_u8pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = DIO_enuSetPinValue(SWITCH_u8GROUP,SWITCH_u8PIN,Copy_u8pu8Value);

	return Local_enuErrorState;
}

