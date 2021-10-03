/*
 * LCD_private.h
 *
 *  Created on: Oct 3, 2021
 *      Author: sa7er
 */

#ifndef HAL_LCD_PRIVATE_H_
#define HAL_LCD_PRIVATE_H_

#define LCD_u8FOUR_BIT_MODE				40
#define LCD_u8EIGHT_BIT_MODE			80

/*                                 LCD INITIALIZATION                    */
#define LCD_u8EIGHT_BIT_FUNCTION_SET	0x38
#define LCD_u8FOUR_BIT_FUNCTION_SET		0x28
#define LCD_u8DISPLAY_CONTROL			0X0F
#define LCD_u8DISPLAY_CLEAR				0X01
#define LCD_u8ENTRY_MODE_SET			0x06

static ES_t LCD_enuWriteNLatch(u8 Copy_u8Value);
static ES_t LCD_enuLatch(void);

#define LCD_u8ERROR_STATE_SHIFT_BIT		2


#endif /* HAL_LCD_PRIVATE_H_ */
