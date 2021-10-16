/*
 * StepperMotor_interface.h
 *
 *  Created on: Oct 16, 2021
 *      Author: sa7er
 */

#ifndef HAL_STEPPERMOTOR_INTERFACE_H_
#define HAL_STEPPERMOTOR_INTERFACE_H_

#define STEPPER_MOTER_u8CW					80
#define STEPPER_MOTER_u8CCW					90

ES_t StepperMotor_enuInit(void);

ES_t StepperMotor_enuFullCycle(u8 Copy_u8Direction);

ES_t StepperMotor_enuAngleMotion(u8 Copy_u8Angle,u8 Copy_u8Direction);

#endif /* HAL_STEPPERMOTOR_INTERFACE_H_ */
