/**
 * @file MSTK_program.c
 * @authors Hossam Elzhar , Mohammed Akram
 * @brief MSTK_Program.c -> Functions Implementation
 * @version 1.1
 * @date 2023-06-26
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSTK_interface.h"
#include "MSTK_private.h"


static void (*MSTK_CallBack)(void)  ;

// calling by Hardware if interrupt happens
void SysTick_Handler(void)
{
	// Execute CallBack Function
	MSTK_CallBack() ;
}


/**
 * @brief this functions is used to initialize systick
 * @param void
 * @return void
 */
void MSTK_voidInit(void)
{
	/* [Enable Systick Interrupt - clock = AHB/8 - Stop Systick]*/

	CLR_BIT(MSTK -> CTRL ,0);
	SET_BIT(MSTK -> CTRL ,1);
	CLR_BIT(MSTK -> CTRL ,2);

}

/**
 * @brief this function is used to start systick with a preloaded value
 * 
 * @param Copy_u32PreloadValue 
 * @return void
 */
void MSTK_voidStart(u32 Copy_u32PreloadValue)
{
	//if F_CPU -> HSI = 16MHz , AHB = 16 MHz , F_Timer = AHB/8 = 2 MHz
	// 0.5 us for each count

	//Step 1: Load Value

	MSTK -> LOAD = Copy_u32PreloadValue;

	//Step 2: Clear Val Reg

	MSTK -> VAL = 0;

	//Step 3: Enable Systick

	SET_BIT(MSTK -> CTRL ,0);

}

/**
 * @brief this function is used to read the flag of systick to make sure it is started
 * 
 * @param void
 * @return u8 
 */
u8 MSTK_u8ReadFlag(void)
{
	//Step 1 : Get Count Flag

	return GET_BIT(MSTK -> CTRL , 16);

}

/**
 * @brief this function is used to enable or disable interrupts
 * 
 * @param Copy_u8INTStatus 
 * @return void
 */
void MSTK_voidINTStatus(u8 Copy_u8INTStatus)
{
	switch (Copy_u8INTStatus)
	{
	case EN :
		// Set the Bit of interrupt with the input
		SET_BIT(MSTK -> CTRL ,1); break;
	case DIS :
		// Clear Bit of Interrupt
		CLR_BIT(MSTK -> CTRL,1); break;
	}

}

/**
 * @brief this function is used to perform a delay by a specific time
 * 
 * @param Copy_u3Time time for delay by milliseconds
 * @return void
 */
void MSTK_voidDelay_ms(u32 Copy_u3Time)
{
	//Step 1 : Init Systick

	MSTK_voidInit();

	//Step 2 : Disable INT

	MSTK_voidINTStatus(DIS);

	//Step 3 : Start Systick( Copy_u32Time )

	MSTK_voidStart(Copy_u3Time * 2000);

	//Step 4 : Wait Flag Polling */

	while(MSTK_u8ReadFlag() == 0);



}


/**
 * @brief this function is used to perform a delay by a specific time
 * 
 * @param Copy_u3Time time for delay by microseconds
 * @return void
 */
void MSTK_voidDelay_us(u32 Copy_u3Time)
{
	//Step 1 : Init Systick

	MSTK_voidInit();

	//Step 2 : Disable INT

	MSTK_voidINTStatus(DIS);

	//Step 3 : Start Systick( Copy_u32Time )

	MSTK_voidStart(Copy_u3Time * 2);

	//Step 4 : Wait Flag Polling */

	while(MSTK_u8ReadFlag() == 0);

}


void MSTK_voidSetCallBack(void (*ptr) (void))
{
	MSTK_CallBack = ptr ;

}






























