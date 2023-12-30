/**
 * @file MNVIC_program.c
 * @authors Hossam Elzhar , Mohammed Akram
 * @brief NVIC_Program.c --> implementations
 * @version 1.1
 * @date 2023-01-23
 * @details 01- MNVIC_voidEnableInterrupt
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MNVIC_interface.h"
#include "MNVIC_private.h"


/**
 * @brief this function is used to enable interrupts
 * 
 * @param Copy_u8IntNum the number of interrupt at the Interrupts Vector Table
 * @return void
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum)
{
	MNVIC -> ISER[Copy_u8IntNum / 32] = (1U << (Copy_u8IntNum) % 32 );
}


