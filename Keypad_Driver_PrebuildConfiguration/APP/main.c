/*
 * main.c
 *
 *  Created on: Oct 3, 2021
 *      Author: sa7er
 */
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/stdTypes.h"

#include "../HAL/LCD_interface.h"
#include "../HAL/Keypad_interface.h"

int main()
{
	u8 Local_u8Key;
	LCD_enuInit();
	Keypad_enuInit();


	while(1)//super loop system
	{
		Keypad_enuGetPressedKey(&Local_u8Key);
		if(Local_u8Key != KEYPAD_u8KEY_NOT_PRESSED)
		{
			LCD_enuSendData(Local_u8Key);
		}
	}
	return 0;
}
