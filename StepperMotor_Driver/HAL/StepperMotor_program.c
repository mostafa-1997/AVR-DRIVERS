/*
 * StepperMotor_program.c
 *
 *  Created on: Oct 16, 2021
 *      Author: sa7er
 */
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/stdTypes.h"
#include "util/delay.h"

#include "../MCAL/DIO_interface.h"

#include "StepperMotor_config.h"
#include "StepperMotor_private.h"

ES_t StepperMotor_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(STEPPER_MOTOR_u8BLUE_PORT,STEPPER_MOTOR_u8BLUE_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(STEPPER_MOTOR_u8PINK_PORT,STEPPER_MOTOR_u8PINK_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(STEPPER_MOTOR_u8YELLOW_PORT,STEPPER_MOTOR_u8YELLOW_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(STEPPER_MOTOR_u8ORANGE_PORT,STEPPER_MOTOR_u8ORANGE_PIN,DIO_u8OUTPUT);

	return Local_enuErrorState;
}

ES_t StepperMotor_enuFullCycle(u8 Copy_u8Direction)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8State = 0x0f;
	u16 Local_u16Iterator;
	if( Copy_u8Direction == STEPPER_MOTER_u8CW)
	{
		for(Local_u16Iterator = 0;Local_u16Iterator<STEPPER_MOTOR_u8NUM_STEPS;Local_u16Iterator++)
		{
			Local_u8State &= ~(1<<(Local_u16Iterator%STEPPER_MOTOR_u8FOUR));//1111 -> 1110 -> 1101 -> 1011 -> 0111

			DIO_enuSetPinValue(STEPPER_MOTOR_u8BLUE_PORT, STEPPER_MOTOR_u8BLUE_PIN,((Local_u8State>>STEPPER_MOTOR_u8ZERO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8ORANGE_PORT, STEPPER_MOTOR_u8ORANGE_PIN,((Local_u8State>>STEPPER_MOTOR_u8ONE)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8YELLOW_PORT, STEPPER_MOTOR_u8YELLOW_PIN,((Local_u8State>>STEPPER_MOTOR_u8TWO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8PINK_PORT, STEPPER_MOTOR_u8PINK_PIN,((Local_u8State>>STEPPER_MOTOR_u8THREE)&STEPPER_MOTOR_u8ONE));

			_delay_ms(6);
			Local_u8State = 0x0f;
		}

	}

	else if( Copy_u8Direction == STEPPER_MOTER_u8CCW)
	{
		for(Local_u16Iterator = 0;Local_u16Iterator<STEPPER_MOTOR_u8NUM_STEPS;Local_u16Iterator++)
		{
			Local_u8State &= ~(1<<(Local_u16Iterator%STEPPER_MOTOR_u8FOUR));//1111 -> 1110 -> 1101 -> 1011 -> 0111

			DIO_enuSetPinValue(STEPPER_MOTOR_u8BLUE_PORT, STEPPER_MOTOR_u8BLUE_PIN,((Local_u8State>>STEPPER_MOTOR_u8ZERO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8PINK_PORT, STEPPER_MOTOR_u8PINK_PIN,((Local_u8State>>STEPPER_MOTOR_u8ONE)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8YELLOW_PORT, STEPPER_MOTOR_u8YELLOW_PIN,((Local_u8State>>STEPPER_MOTOR_u8TWO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8ORANGE_PORT, STEPPER_MOTOR_u8ORANGE_PIN,((Local_u8State>>STEPPER_MOTOR_u8THREE)&STEPPER_MOTOR_u8ONE));

			_delay_ms(6);
			Local_u8State = 0x0f;
		}
	}


	return Local_enuErrorState;
}

ES_t StepperMotor_enuAngleMotion(u8 Copy_u8Angle,u8 Copy_u8Direction)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8State = 0x0f;
	u16 Local_u16Iterator;
	u16 Local_u16NumSteps = ((u32)Copy_u8Angle * STEPPER_MOTOR_u8NUM_STEPS)/360;
	if( Copy_u8Direction == STEPPER_MOTER_u8CW)
	{
		for(Local_u16Iterator = 0;Local_u16Iterator<Local_u16NumSteps;Local_u16Iterator++)
		{
			Local_u8State &= ~(1<<(Local_u16Iterator%STEPPER_MOTOR_u8FOUR));//1111 -> 1110 -> 1101 -> 1011 -> 0111

			DIO_enuSetPinValue(STEPPER_MOTOR_u8BLUE_PORT, STEPPER_MOTOR_u8BLUE_PIN,((Local_u8State>>STEPPER_MOTOR_u8ZERO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8ORANGE_PORT, STEPPER_MOTOR_u8ORANGE_PIN,((Local_u8State>>STEPPER_MOTOR_u8ONE)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8YELLOW_PORT, STEPPER_MOTOR_u8YELLOW_PIN,((Local_u8State>>STEPPER_MOTOR_u8TWO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8PINK_PORT, STEPPER_MOTOR_u8PINK_PIN,((Local_u8State>>STEPPER_MOTOR_u8THREE)&STEPPER_MOTOR_u8ONE));

			_delay_ms(6);
			Local_u8State = 0x0f;
		}

	}

	else if( Copy_u8Direction == STEPPER_MOTER_u8CCW)
	{
		for(Local_u16Iterator = 0;Local_u16Iterator<Local_u16NumSteps;Local_u16Iterator++)
		{
			Local_u8State &= ~(1<<(Local_u16Iterator%STEPPER_MOTOR_u8FOUR));//1111 -> 1110 -> 1101 -> 1011 -> 0111

			DIO_enuSetPinValue(STEPPER_MOTOR_u8BLUE_PORT, STEPPER_MOTOR_u8BLUE_PIN,((Local_u8State>>STEPPER_MOTOR_u8ZERO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8PINK_PORT, STEPPER_MOTOR_u8PINK_PIN,((Local_u8State>>STEPPER_MOTOR_u8ONE)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8YELLOW_PORT, STEPPER_MOTOR_u8YELLOW_PIN,((Local_u8State>>STEPPER_MOTOR_u8TWO)&STEPPER_MOTOR_u8ONE));
			DIO_enuSetPinValue(STEPPER_MOTOR_u8ORANGE_PORT, STEPPER_MOTOR_u8ORANGE_PIN,((Local_u8State>>STEPPER_MOTOR_u8THREE)&STEPPER_MOTOR_u8ONE));

			_delay_ms(6);
			Local_u8State = 0x0f;
		}
	}


	return Local_enuErrorState;
}
