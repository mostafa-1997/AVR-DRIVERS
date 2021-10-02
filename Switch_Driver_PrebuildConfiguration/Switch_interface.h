/*
 * Switch_interface.h
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

ES_t Switch_enuInit(void);

ES_t Switch_enuGetSwitchValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 * Copy_u8pu8Value);

#endif /* SWITCH_INTERFACE_H_ */
