/*
 * LCD_program.c
 *
 *  Created on: Oct 3, 2021
 *      Author: sa7er
 */
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/stdTypes.h"

#include "util/delay.h"

#include "../MCAL/DIO_interface.h"

#include "LCD_config.h"
#include "LCD_private.h"

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32ErrorState = 0;

	//control lines
	Local_u32ErrorState = DIO_enuSetPinDirection(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8OUTPUT);
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8RW_GROUP,LCD_u8RW_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;

	//data lines
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D7_GROUP,LCD_u8D7_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D6_GROUP,LCD_u8D6_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D5_GROUP,LCD_u8D5_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D4_GROUP,LCD_u8D4_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;


	_delay_ms(35);
#if LCD_u8BIT_MODE == LCD_u8FOUR_BIT_MODE
	Local_u32ErrorState |= (DIO_enuSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (LCD_enuWriteNLatch(LCD_u8FOUR_BIT_FUNCTION_SET))<<LCD_u8ERROR_STATE_SHIFT_BIT;
#elif LCD_u8BIT_MODE == LCD_u8EIGHT_BIT_MODE
	Local_u32ErrorState |= (DIO_enuSetPinValue(LCD_u8RS_GROUP,LCD_u8RW_PIN,DIO_u8LOW))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (LCD_enuWriteNLatch(LCD_u8EIGHT_BIT_FUNCTION_SET))<<LCD_u8ERROR_STATE_SHIFT_BIT;

	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D3_GROUP,LCD_u8D3_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D2_GROUP,LCD_u8D2_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D1_GROUP,LCD_u8D1_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (DIO_enuSetPinDirection(LCD_u8D0_GROUP,LCD_u8D0_PIN,DIO_u8OUTPUT))<<LCD_u8ERROR_STATE_SHIFT_BIT;
#else
#error"LCD mode is wrong"
#endif

	_delay_ms(2);
	Local_u32ErrorState |= (DIO_enuSetPinValue(LCD_u8RS_GROUP,LCD_u8RW_PIN,DIO_u8LOW))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (LCD_enuWriteNLatch(LCD_u8DISPLAY_CONTROL))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	_delay_ms(2);
	Local_u32ErrorState |= (DIO_enuSetPinValue(LCD_u8RS_GROUP,LCD_u8RW_PIN,DIO_u8LOW))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (LCD_enuWriteNLatch(LCD_u8DISPLAY_CLEAR))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	_delay_ms(3);
	Local_u32ErrorState |= (DIO_enuSetPinValue(LCD_u8RS_GROUP,LCD_u8RW_PIN,DIO_u8LOW))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	Local_u32ErrorState |= (LCD_enuWriteNLatch(LCD_u8ENTRY_MODE_SET))<<LCD_u8ERROR_STATE_SHIFT_BIT;

	if(Local_u32ErrorState == 0)
	{
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

ES_t LCD_enuSendData(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8ErrorState = 0;

	Local_u8ErrorState = DIO_enuSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8HIGH);
	Local_u8ErrorState |= (LCD_enuWriteNLatch(Copy_u8Data))<<LCD_u8ERROR_STATE_SHIFT_BIT;

	if(Local_u8ErrorState == 0)
	{
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8ErrorState = 0;

	Local_u8ErrorState = DIO_enuSetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,DIO_u8LOW);
	Local_u8ErrorState |= (LCD_enuWriteNLatch(Copy_u8Data))<<LCD_u8ERROR_STATE_SHIFT_BIT;

	if(Local_u8ErrorState == 0)
	{
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

static ES_t LCD_enuWriteNLatch(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8LOW);
	DIO_enuSetPinValue(LCD_u8RW_GROUP,LCD_u8RW_PIN,DIO_u8LOW);

#if LCD_u8BIT_MODE == LCD_u8FOUR_BIT_MODE

	u8 Local_u8RSValue;

	if(Copy_u8Data == LCD_u8FOUR_BIT_FUNCTION_SET)
	{
		DIO_enuGetPinValue(LCD_u8RS_GROUP,LCD_u8RS_PIN,&Local_u8RSValue);
		if(Local_u8RSValue == DIO_u8LOW)
		{
			DIO_enuSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,(Copy_u8Data>>DIO_u8PIN7)&1);
			DIO_enuSetPinValue(LCD_u8D6_GROUP,LCD_u8D6_PIN,(Copy_u8Data>>DIO_u8PIN6)&1);
			DIO_enuSetPinValue(LCD_u8D5_GROUP,LCD_u8D5_PIN,(Copy_u8Data>>DIO_u8PIN5)&1);
			DIO_enuSetPinValue(LCD_u8D4_GROUP,LCD_u8D4_PIN,(Copy_u8Data>>DIO_u8PIN4)&1);
			LCD_enuLatch();
		}
	}

	DIO_enuSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,(Copy_u8Data>>DIO_u8PIN7)&1);
	DIO_enuSetPinValue(LCD_u8D6_GROUP,LCD_u8D6_PIN,(Copy_u8Data>>DIO_u8PIN6)&1);
	DIO_enuSetPinValue(LCD_u8D5_GROUP,LCD_u8D5_PIN,(Copy_u8Data>>DIO_u8PIN5)&1);
	DIO_enuSetPinValue(LCD_u8D4_GROUP,LCD_u8D4_PIN,(Copy_u8Data>>DIO_u8PIN4)&1);
	LCD_enuLatch();

	DIO_enuSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,(Copy_u8Data>>DIO_u8PIN3)&1);
	DIO_enuSetPinValue(LCD_u8D6_GROUP,LCD_u8D6_PIN,(Copy_u8Data>>DIO_u8PIN2)&1);
	DIO_enuSetPinValue(LCD_u8D5_GROUP,LCD_u8D5_PIN,(Copy_u8Data>>DIO_u8PIN1)&1);
	DIO_enuSetPinValue(LCD_u8D4_GROUP,LCD_u8D4_PIN,(Copy_u8Data>>DIO_u8PIN0)&1);
	LCD_enuLatch();

#elif LCD_u8BIT_MODE == LCD_u8EIGHT_BIT_MODE

	DIO_enuSetPinValue(LCD_u8D7_GROUP,LCD_u8D7_PIN,(Copy_u8Data>>DIO_u8PIN7)&1);
	DIO_enuSetPinValue(LCD_u8D6_GROUP,LCD_u8D6_PIN,(Copy_u8Data>>DIO_u8PIN6)&1);
	DIO_enuSetPinValue(LCD_u8D5_GROUP,LCD_u8D5_PIN,(Copy_u8Data>>DIO_u8PIN5)&1);
	DIO_enuSetPinValue(LCD_u8D4_GROUP,LCD_u8D4_PIN,(Copy_u8Data>>DIO_u8PIN4)&1);
	DIO_enuSetPinValue(LCD_u8D3_GROUP,LCD_u8D3_PIN,(Copy_u8Data>>DIO_u8PIN3)&1);
	DIO_enuSetPinValue(LCD_u8D2_GROUP,LCD_u8D2_PIN,(Copy_u8Data>>DIO_u8PIN2)&1);
	DIO_enuSetPinValue(LCD_u8D1_GROUP,LCD_u8D1_PIN,(Copy_u8Data>>DIO_u8PIN1)&1);
	DIO_enuSetPinValue(LCD_u8D0_GROUP,LCD_u8D0_PIN,(Copy_u8Data>>DIO_u8PIN0)&1);
	LCD_enuLatch();


#else
#error"LCD mode is wrong"
#endif


	return Local_enuErrorState;
}

static ES_t LCD_enuLatch(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8ErrorState = 0;

	Local_u8ErrorState = DIO_enuSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8HIGH);
	_delay_ms(5);
	Local_u8ErrorState |= (DIO_enuSetPinValue(LCD_u8EN_GROUP,LCD_u8EN_PIN,DIO_u8LOW))<<LCD_u8ERROR_STATE_SHIFT_BIT;
	_delay_ms(5);

	if(Local_u8ErrorState == 0)
	{
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}
