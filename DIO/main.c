/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: sa7er
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_interface.h"

#include "util/delay.h"


int main()
{

	DIO_enuInit();

	while(1)//super loop system
	{
		DIO_enuTogglePinValue(DIO_u8GROUP_A,DIO_u8PIN0);
		_delay_ms(250);
	}

	return 0;
}
