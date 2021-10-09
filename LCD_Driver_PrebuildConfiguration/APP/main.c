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
	LCD_enuSendString("SOLOMATE");

	while(1); //super loop system
	return 0;
}
