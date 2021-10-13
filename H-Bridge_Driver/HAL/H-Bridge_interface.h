/*
 * H-Bridge_interface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: sa7er
 */

#ifndef HAL_H_BRIDGE_INTERFACE_H_
#define HAL_H_BRIDGE_INTERFACE_H_

ES_t HAL_Bridge_enuInit(void);

ES_t HAL_Bridge_enuDirection(u8 Copy_u8Direction);

#define HAL_BRIDGE_u8CW			98
#define HAL_BRIDGE_u8CW			105


#endif /* HAL_H_BRIDGE_INTERFACE_H_ */
