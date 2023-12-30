/**
 * @file  FWC_program_c
 * @authors Hossam Elzhar , Mohammed Akram
 * @brief FWC_program_c --> implementations
 * @version 0.6
 * @date 2023-06-22 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MSTK_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "TMR_interface.h"
#include "MUSART_interface.h"
#include "Ultrasonic_interface.h"

#include "FWC_interface.h"
#include "FWC_private.h"


volatile u8  FWC_speed_level;
volatile u32 FWC_Distance;
volatile u16 FWC_speed;


//Converted Speed value array
u8 S[3];
//Converted Distance value array
u8 D[3];

/**
 * @brief initialize all the peripherals that is used in the system
 * @param void
 * @return void
 */
void FWC_voidSystemInit(void)
{
	/*System Clock initialization*/
	MRCC_voidInitSystemClock();
	/*--------------------------------------- Timer 3 ----------------------------------------------------*/
	/*GPIO pins initialization*/
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERIAL_EN_GPIOA);
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERIAL_EN_GPIOB);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN6, MGPIO_PIN_ALTF);
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN6, AF2);//Timer3 ch1
	MRCC_voidEnablePeripheralClock(APB1, MRCC_PERIPHERIAL_EN_TIM3);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN5, MGPIO_PIN_OUTPUT);// UltrasonicTrigger pin

	/*Interrupt initialization*/
	MNVIC_voidEnableInterrupt(MNVIC_TIM3_NUM); // Enable Timer3 Global Interrupt

	/*Timer initialization*/
	Timer3_voidCapture_Compare_Init();
	TMR_voidStart(TMR3);

	/*------------------------------------ Timer 2 ------------------------------------------------------ */

	/* GPIO pins initialization for DC motor PWM Timer 2*/
	MRCC_voidEnablePeripheralClock(APB1, MRCC_PERIPHERIAL_EN_TIM2);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN0, MGPIO_PIN_ALTF);
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN0, AF1);//Timer2 ch1

	/* Speed Init */
	TMR_voidSetPrescaler(TMR2, 64);
	TMR_voidSetARR(TMR2, 10000 - 1);
	TMR_voidSetChannelOutput(TMR2, PWM_MODE1, CH1);

	/*--------------------------------- Motors -----------------------------------------------------------*/

	/* Set Mode for Motor Input Pins */
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN1, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN2, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN3, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN4, MGPIO_PIN_OUTPUT);

	/*----------------------------------------- UART ----------------------------------------------------- */

	/*Enable RCC For USART1*/
	MRCC_voidEnablePeripheralClock(APB2, MRCC_PERIPHERIAL_EN_USART1); // Enable CLK Of UART1   At APB2

	/*Configure UART1 ,UART2  Pins*/
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN9, MGPIO_PIN_ALTF);  // TX-->UART1
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN10, MGPIO_PIN_ALTF); // RX-->UART1
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN9, AF7);	  // TX-->UART1
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN10, AF7);	  // RX-->UART1


	/*Initialize USART1*/
	MSUART_voidInit();

	/*initialize system Peripherials*/
	MUSART_voidEnable(1); // Enable UART 1

	/*------------------------------------------- LEDS ---------------------------------------------- */
	/* Buzzer */
	MGPIO_voidSetPinMode(MGPIO_PortB, PIN6, MGPIO_PIN_OUTPUT);

}


/**
 * @brief used to start the motors and enable it to speed up by the PWM signal
 * @param void
 * @return void
 */
static void start_motor(void)
{
	/* Set Value for Motor Input Pins to START MOTOR */
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN1, MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN2, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN3, MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN4, MGPIO_PIN_LOW);
}

/**
 * @brief used to stop the motors completely by giving it zero voltage on all its pins
 * @param void
 * @return void
 */
static void stop_motor(void)
{
	/* Set Value for Motor Input Pins to START MOTOR */
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN1, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN2, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN3, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortA, PIN4, MGPIO_PIN_LOW);
}

void FWC_voidGetDistance(void)
{
	Ultrasonic_voidTrigger();
}

/**
 * @brief used to turn on the Adaptive Cruise Control Mode ON and set the required range according to the range selected by the user
 * @param void
 * @return void
 */
void FWC_voidSystemStart(void)
{
	// checking distance
	if(FWC_Distance >= 100)
	{
		FWC_speed_level++;
		MGPIO_voidSetPinValue(MGPIO_PortB, PIN6, MGPIO_PIN_LOW);//buzzer

		if((FWC_speed_level <= 125) && (FWC_speed_level >= 120))
		{
			FWC_speed_level = 120;
		}else{}
	}
	else if ((FWC_Distance < 100) && (FWC_Distance >= 75))
	{
		//Warning Using Buzzer
		MGPIO_voidSetPinValue(MGPIO_PortB, PIN6, MGPIO_PIN_HIGH);
		FWC_speed_level++;
		if((FWC_speed_level <= 125) && (FWC_speed_level >= 120))
		{
			FWC_speed_level = 120;
		}else{}
	}
	else if ((FWC_Distance < 75) && (FWC_Distance > 50))
	{
		if (FWC_speed_level > 45)
		{
			MGPIO_voidSetPinValue(MGPIO_PortB, PIN6, MGPIO_PIN_HIGH);
			//Take Action, Slow Down the car speed
			FWC_speed_level -= 2;
		}
		else if(FWC_speed_level < 40)
		{
			//when starting to move again after stopping
			MGPIO_voidSetPinValue(MGPIO_PortB, PIN6, MGPIO_PIN_HIGH);
			FWC_speed_level++;
		}
		else
		{
			FWC_speed_level = 45;
		}
	}
	else if ((FWC_Distance < 50) && (FWC_Distance > 25))
	{
		if (FWC_speed_level > 30)
		{
			MGPIO_voidSetPinValue(MGPIO_PortB, PIN6, MGPIO_PIN_HIGH);
			//Take Action, Slow Down the car speed
			FWC_speed_level -= 2;
		}
		else if(FWC_speed_level < 28)
		{
			//when starting to move again after stopping
			MGPIO_voidSetPinValue(MGPIO_PortB, PIN6, MGPIO_PIN_HIGH);
			FWC_speed_level++;
		}
		else
		{
			FWC_speed_level = 30;
		}
	}
	else if (FWC_Distance <= 25)
	{
		FWC_speed_level = 0;
		MGPIO_voidSetPinValue(MGPIO_PortB, PIN6,MGPIO_PIN_LOW);//buzzer
	}
	else{}

}


void FWC_voidGetCarSpeed(void)
{
	u32 Local_u32PMWValue;
	// calculating speed
	FWC_speed = FWC_speed_level;
	// generating PWM signal with the required duty cycle
	Local_u32PMWValue = 100 * FWC_speed_level;
	TMR_voidSetCMPVal(TMR2, CH1, Local_u32PMWValue);
	TMR_voidStart(TMR2);
	MSTK_voidDelay_ms(35);
}

/**
 * @brief this function is used to send distance & speed to raspberry pi
 * @param void
 * @return void
 */
void FWC_voidSendDataToGUI(void)
{

	S[0] = ((FWC_speed%10) + 48);
	FWC_speed /= 10;
	S[1] = ((FWC_speed%10) + 48);
	FWC_speed /= 10;
	S[2] = ((FWC_speed%10) + 48);
	FWC_speed /= 10;

	MUSART_voidSendData(1, S[2]);
	MUSART_voidSendData(1, S[1]);
	MUSART_voidSendData(1, S[0]);

	u16 TempDist = FWC_Distance;

	D[0] = ((TempDist%10) + 48);
	TempDist /= 10;
	D[1] = ((TempDist%10) + 48);
	TempDist /= 10;
	D[2] = ((TempDist%10) + 48);
	TempDist /= 10;

	MUSART_voidSendData(1, ' ');
	MUSART_voidSendData(1, D[2]);
	MUSART_voidSendData(1, D[1]);
	MUSART_voidSendData(1, D[0]);
	MUSART_voidSendData(1, '\r');
	MUSART_voidSendData(1, '\n');

}
