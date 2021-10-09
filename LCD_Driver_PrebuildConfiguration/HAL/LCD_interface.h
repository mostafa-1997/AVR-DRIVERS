/*
 * LCD_interface.h
 *
 *  Created on: Oct 3, 2021
 *      Author: sa7er
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Data);

ES_t LCD_enuSendString(const char * Copy_pcString);

#endif /* HAL_LCD_INTERFACE_H_ */
