/*
 * main.c
 *
 *  Created on: Oct 3, 2021
 *      Author: sa7er
 */
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/stdTypes.h"

#include "../HAL/StepperMotor_interface.h"
int main()
{

	StepperMotor_enuInit();

	StepperMotor_enuFullCycle(STEPPER_MOTER_u8CW);
	//StepperMotot_enuFullCycle(STEPPER_MOTER_u8CCW);

	StepperMotor_enuAngleMotion(90,STEPPER_MOTER_u8CW);
	while(1);//Super Loop System
	return 0;
}
