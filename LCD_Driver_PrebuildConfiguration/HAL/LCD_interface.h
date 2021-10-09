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

ES_t LCD_enuGoToPosition(u8 Copy_u8Line,u8 Copy_u8Column);

enum
{
	LCD_u8ZERO,
	LCD_u8ONE,
	LCD_u8TWO,
	LCD_u8THREE,
	LCD_u8FOUR,
	LCD_u8FIVE,
	LCD_u8SIX,
	LCD_u8SEVEN,
	LCD_u8EIGHT,
	LCD_u8NINE,
	LCD_u8TEN,
	LCD_u8ELEVEN,
	LCD_u8TWELVE,
	LCD_u8THIRTEEN,
	LCD_u8FOURTEEN,
	LCD_u8FIFTEEN,
	LCD_u8SIXTEEN,
};

#endif /* HAL_LCD_INTERFACE_H_ */
