/*
 * Switch_interface.h
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

ES_t Switch_enuInit(SW_t * Copy_pAstrSwitchConfig);

ES_t Switch_enuGetSwitchValue(SW_t * Copy_pstrSwitchInfo,u8 * Copy_u8pu8Value);

#endif /* SWITCH_INTERFACE_H_ */
