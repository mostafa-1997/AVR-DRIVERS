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
	LCD_enuSendData('M');
	LCD_enuSendData('O');
	LCD_enuSendData('S');
	LCD_enuSendData('T');
	LCD_enuSendData('A');
	LCD_enuSendData('F');
	LCD_enuSendData('A');

	while(1); //super loop system
	return 0;
}
