/*
 * SevenSegment_program.c
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_interface.h"

#include "SevenSegment_private.h"
#include "SevenSegment_config.h"

ES_t SevenSegment_enuInit(SSG_t * SevenSegment_pAstrSSGConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iterator;
	for(Local_u8Iterator = 0;Local_u8Iterator<SEVENSEGMENT_u8NUM;Local_u8Iterator++)
	{
		DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].A_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].A_Pin,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].B_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].B_Pin,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].C_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].C_Pin,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].D_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].D_Pin,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].E_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].E_Pin,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].F_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].F_Pin,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].G_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].G_Pin,DIO_u8OUTPUT);

		if(SevenSegment_pAstrSSGConfig[Local_u8Iterator].CMN_Port != NOT_CONNECTED &&
				SevenSegment_pAstrSSGConfig[Local_u8Iterator].CMN_Pin != NOT_CONNECTED)
		{
			DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].CMN_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].CMN_Pin,DIO_u8OUTPUT);
		}

		if(SevenSegment_pAstrSSGConfig[Local_u8Iterator].Dot_Port != NOT_CONNECTED &&
						SevenSegment_pAstrSSGConfig[Local_u8Iterator].Dot_Pin != NOT_CONNECTED)
				{
					DIO_enuSetPinDirection(SevenSegment_pAstrSSGConfig[Local_u8Iterator].Dot_Port,SevenSegment_pAstrSSGConfig[Local_u8Iterator].Dot_Pin,DIO_u8OUTPUT);
				}


	}

	return Local_enuErrorState;
}

ES_t SevenSegment_enuDisplay(SSG_t * SevenSegment_pstrSSGInfo,u8 Copy_u8Number)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_ANODE)
	{
		Copy_u8Number = ~SevenSegment_Au8CMN_CTH_Values[Copy_u8Number];
	}
	else if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_CATHODE)
	{
		Copy_u8Number = SevenSegment_Au8CMN_CTH_Values[Copy_u8Number];
	}

	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->A_Port,SevenSegment_pstrSSGInfo->A_Pin,(Copy_u8Number>>0)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->B_Port,SevenSegment_pstrSSGInfo->B_Pin,(Copy_u8Number>>1)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->C_Port,SevenSegment_pstrSSGInfo->C_Pin,(Copy_u8Number>>2)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->D_Port,SevenSegment_pstrSSGInfo->D_Pin,(Copy_u8Number>>3)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->E_Port,SevenSegment_pstrSSGInfo->E_Pin,(Copy_u8Number>>4)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->F_Port,SevenSegment_pstrSSGInfo->F_Pin,(Copy_u8Number>>5)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->G_Port,SevenSegment_pstrSSGInfo->G_Pin,(Copy_u8Number>>6)&1);

	return Local_enuErrorState;
}

ES_t SevenSegment_enuEnableCommon(SSG_t * SevenSegment_pstrSSGInfo)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(SevenSegment_pstrSSGInfo->CMN_Port != NOT_CONNECTED &&
			SevenSegment_pstrSSGInfo->CMN_Pin != NOT_CONNECTED)
	{
		if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_ANODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->CMN_Port,SevenSegment_pstrSSGInfo->CMN_Pin,DIO_u8HIGH);
		}
		else if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->CMN_Port,SevenSegment_pstrSSGInfo->CMN_Pin,DIO_u8LOW);
		}
	}


	return Local_enuErrorState;
}

ES_t SevenSegment_enuDisableCommon(SSG_t * SevenSegment_pstrSSGInfo)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(SevenSegment_pstrSSGInfo->CMN_Port != NOT_CONNECTED &&
			SevenSegment_pstrSSGInfo->CMN_Pin != NOT_CONNECTED)
	{
		if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_ANODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->CMN_Port,SevenSegment_pstrSSGInfo->CMN_Pin,DIO_u8LOW);
		}
		else if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->CMN_Port,SevenSegment_pstrSSGInfo->CMN_Pin,DIO_u8HIGH);
		}
	}

	return Local_enuErrorState;
}

ES_t SevenSegment_enuEnableDot(SSG_t * SevenSegment_pstrSSGInfo)
{
	ES_t Local_enuErrorState = ES_NOK;


	if(SevenSegment_pstrSSGInfo->Dot_Port != NOT_CONNECTED &&
			SevenSegment_pstrSSGInfo->Dot_Pin != NOT_CONNECTED)
	{
		if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_ANODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->Dot_Port,SevenSegment_pstrSSGInfo->Dot_Pin,DIO_u8LOW);
		}
		else if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->Dot_Port,SevenSegment_pstrSSGInfo->Dot_Pin,DIO_u8HIGH);
		}
	}

	return Local_enuErrorState;
}

ES_t SevenSegment_enuDisableDot(SSG_t * SevenSegment_pstrSSGInfo)
{
	ES_t Local_enuErrorState = ES_NOK;


	if(SevenSegment_pstrSSGInfo->Dot_Port != NOT_CONNECTED &&
			SevenSegment_pstrSSGInfo->Dot_Pin != NOT_CONNECTED)
	{
		if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_ANODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->Dot_Port,SevenSegment_pstrSSGInfo->Dot_Pin,DIO_u8HIGH);
		}
		else if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->Dot_Port,SevenSegment_pstrSSGInfo->Dot_Pin,DIO_u8LOW);
		}
	}

	return Local_enuErrorState;
}

ES_t SevenSegment_enuStopDisplay(SSG_t * SevenSegment_pstrSSGInfo)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Value = 0;

	if(SevenSegment_pstrSSGInfo->SSG_Type == COMMON_ANODE)
	{
		Local_u8Value = ~Local_u8Value;//255
	}

	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->A_Port,SevenSegment_pstrSSGInfo->A_Pin,(Local_u8Value>>0)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->B_Port,SevenSegment_pstrSSGInfo->B_Pin,(Local_u8Value>>1)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->C_Port,SevenSegment_pstrSSGInfo->C_Pin,(Local_u8Value>>2)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->D_Port,SevenSegment_pstrSSGInfo->D_Pin,(Local_u8Value>>3)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->E_Port,SevenSegment_pstrSSGInfo->E_Pin,(Local_u8Value>>4)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->F_Port,SevenSegment_pstrSSGInfo->F_Pin,(Local_u8Value>>5)&1);
	DIO_enuSetPinValue(SevenSegment_pstrSSGInfo->G_Port,SevenSegment_pstrSSGInfo->G_Pin,(Local_u8Value>>6)&1);


	return Local_enuErrorState;
}
