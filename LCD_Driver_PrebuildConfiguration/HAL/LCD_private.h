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


#define LCD_u8FIRST_LINE_STARTING_ADDRESS	0x80
#define LCD_u8SECOND_LINE_STARTING_ADDRESS	0xC0

#define LCD_u8ZERO						0
#define LCD_u8ONE						1
#define LCD_u8TWO						2
#define LCD_u8THRE						3
#define LCD_u8FOUR						4
#define LCD_u8FIVE						5
#define LCD_u8SIX						6
#define LCD_u8SEVEN						7
#define LCD_u8EIGHT						8
#define LCD_u8NINE						9
#define LCD_u8TEN						10
#define LCD_u8ELEVEN					11
#define LCD_u8TWELVE					12
#define LCD_u8THIRTEEN					13
#define LCD_u8FOURTEEN					14
#define LCD_u8FIFTEEN					15
#define LCD_u8SIXTEEN					16


#endif /* HAL_LCD_PRIVATE_H_ */
