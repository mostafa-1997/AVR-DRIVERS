/*
 * LED_config.h
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_u8NUM			3

typedef struct
{

	u8 LED_u8Port;
	u8 LED_u8Pin;
	u8 LED_u8Value;

}LED_t;

#endif /* LED_CONFIG_H_ */
