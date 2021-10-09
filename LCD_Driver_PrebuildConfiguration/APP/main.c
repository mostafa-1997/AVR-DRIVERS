/*
 * main.c
 *
 *  Created on: Oct 3, 2021
 *      Author: sa7er
 */
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/stdTypes.h"

#include "../HAL/LCD_interface.h"

int main()
{

	u8 arr[] = {0x00,0x00, 0x00,0x06,0x09,0x09,0x1F,0x00,
			  	0x04,0x15,0x15,0x15,0x0A,0x15,0x15,0x15};

	LCD_enuInit();

	//LCD_enuGoToPosition(LCD_u8TWO,LCD_u8TEN);
	//LCD_enuSendString("SOLOMATE");

	//LCD_enuSendExtraCharacter(arr,LCD_u8ZERO,LCD_u8TWO,LCD_u8TWO,LCD_u8SIXTEEN,LCD_u8DECREMENT);

	//LCD_enuDisplayInt(-300);

	while(1); //super loop system
	return 0;
}
