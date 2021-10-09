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

	LCD_enuInit();
	LCD_enuGoToPosition(LCD_u8TWO,LCD_u8TEN);
	LCD_enuSendString("SOLOMATE");

	while(1); //super loop system
	return 0;
}
