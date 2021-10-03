/*
 * LED_program.c
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_interface.h"

#include "LED_config.h"
#include "LED_private.h"

ES_t LED_enuInit(LED_t * Copy_pAstrLED_AstrLEDConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pAstrLED_AstrLEDConfig != NULL)
	{

		u16 Local_u16ErrorStates = 0;

		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0;Local_u8Iterator<LED_u8NUM;Local_u8Iterator++)
		{
			if(Local_u8Iterator == 0)
			{
				Local_u16ErrorStates = DIO_enuSetPinDirection(Copy_pAstrLED_AstrLEDConfig[Local_u8Iterator].LED_u8Port,Copy_pAstrLED_AstrLEDConfig[Local_u8Iterator].LED_u8Pin,DIO_u8OUTPUT);
			}
			else
			{
				Local_u16ErrorStates |= (DIO_enuSetPinDirection(Copy_pAstrLED_AstrLEDConfig[Local_u8Iterator].LED_u8Port,Copy_pAstrLED_AstrLEDConfig[Local_u8Iterator].LED_u8Pin,DIO_u8OUTPUT))<<(2*Local_u8Iterator);
			}

		}

		if(Local_u16ErrorStates == 21)
		{
			Local_enuErrorState = ES_OK;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}

ES_t LED_enuSetLEDValue(LED_t * Copy_ptrLED_AstrLEDInfo,u8 Copy_u8Value)
{

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_ptrLED_AstrLEDInfo != NULL)
	{
		Local_enuErrorState = DIO_enuSetPinValue(Copy_ptrLED_AstrLEDInfo->LED_u8Port,Copy_ptrLED_AstrLEDInfo->LED_u8Pin,Copy_u8Value);
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LED_enuToggleLEDValue(LED_t * Copy_ptrLED_AstrLEDInfo)
{

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_ptrLED_AstrLEDInfo != NULL)
	{
		Local_enuErrorState = DIO_enuTogglePinValue(Copy_ptrLED_AstrLEDInfo->LED_u8Port,Copy_ptrLED_AstrLEDInfo->LED_u8Pin);
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

