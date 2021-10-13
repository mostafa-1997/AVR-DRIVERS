/*
 * main.c
 *
 *  Created on: Oct 3, 2021
 *      Author: sa7er
 */
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/stdTypes.h"

#include "../HAL/H-Bridge_interface.h"
int main()
{
	HAL_Bridge_enuInit();

	while(1);
	return 0;
}
