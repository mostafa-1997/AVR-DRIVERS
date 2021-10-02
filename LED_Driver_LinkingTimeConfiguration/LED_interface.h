/*
 * LED_interface.h
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

ES_t LED_enuInit(LED_t * Copy_pAstrLED_AstrLEDConfig);

ES_t LED_enuSetLEDValue(LED_t * Copy_ptrLED_AstrLEDInfo,u8 Copy_u8Value);

ES_t LED_enuToggleLEDValue(LED_t * Copy_ptrLED_AstrLEDInfo);

#endif /* LED_INTERFACE_H_ */
