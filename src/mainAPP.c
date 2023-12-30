/**
 * @file main.c
 * @authors Hossam Elzhar , Mohammed Akram
 * @brief the main application of the project
 * @version 1.2
 * @date 2023-06-22
 * 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FWC_interface.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MNVIC_interface.h"
#include "MUSART_interface.h"
#include "TMR_interface.h"




/**
 * @brief the main entry point of the program
 * @param void
 * @return void
 */
void main (void)
{
	FWC_voidSystemInit();
	TMR_voidStart(TMR3);

	while(1)
	{

		FWC_voidGetDistance();

		FWC_voidSystemStart();

		FWC_voidGetCarSpeed();

		FWC_voidSendDataToGUI();
	}
}











