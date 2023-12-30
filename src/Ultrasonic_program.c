/**
 * @file Ultrasonic_program.c
 * @authors Hossam Elzhar , Mohammed Akram
 * @brief functions implementations for ultrasonic
 * @version 1.0
 * @date 2023-02-10
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "TMR_interface.h"

#include "Ultrasonic_interface.h"
#include "Ultrasonic_config.h"



extern volatile u32 FWC_Distance;
u32 Ultrasonic_Capture1;
u32 Ultrasonic_Capture2;
u32 Ultrasonic_Time;
u8 Ultrasonic_flag;




/**
 * @brief trigger function for ultrasonic
 * @param void
 * @return void
 *
 */
void Ultrasonic_voidTrigger(void)
{
	TMR_voidClearCount(TMR3);
	MGPIO_voidSetPinValue(UltraPort, Trigger_Pin, MGPIO_PIN_HIGH);
	MSTK_voidDelay_us(15);
	MGPIO_voidSetPinValue(UltraPort, Trigger_Pin, MGPIO_PIN_LOW);
}


/**
 * @brief interrupt function for ultrasonic
 * @param void
 * @return void
 */
void TIM3_IRQHandler(void)
{

	if (Ultrasonic_flag == 0)
	{
		Ultrasonic_Capture1 = TMR_voidReadCapture(TMR3, CH1);
		Ultrasonic_flag = 1;
	}
	else if (Ultrasonic_flag == 1)
	{
		Ultrasonic_Capture2 = TMR_voidReadCapture(TMR3, CH1);
		TMR_voidClearCount(TMR3);
		Ultrasonic_flag = 0;
		Ultrasonic_Time = Ultrasonic_Capture2 - Ultrasonic_Capture1;		
		FWC_Distance = Ultrasonic_Time * 0.068; //Distance = (time * sound speed) / 2  
								  				//Distance = (Counts * tick time) * 0.034cm/u)/2
												//tick time = prescaler/timer freq.
												//tick time = 64 / 16 = 4
								  				// Distance = (counts*4 *0.034)/2

	}
}