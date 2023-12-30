/**
 * @file TMR_program.c
 * @authors Hossam Elzhar , Mohammed Akram
 * @brief  functions implementations
 * @version 1.0
 * @date 2023-02-07
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR_interface.h"
#include "TMR_private.h"



/**
 * @brief this function is used to start the timer
 * 
 * @param Copy_uddtTMR_no [TMR2 - TMR3 - TMR4 - TMR5]
 * @return void
 */
void TMR_voidStart(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		SET_BIT(TMR2_ADD -> CR1, CEN_BIT); break;
	case TMR3:
		SET_BIT(TMR3_ADD -> CR1, CEN_BIT); break;
	case TMR4:
		SET_BIT(TMR4_ADD -> CR1, CEN_BIT); break;
	case TMR5:
		SET_BIT(TMR5_ADD -> CR1, CEN_BIT); break;

	default:                               break;
	}
}

/**
 * @brief this function is used to stop the timer
 * 
 * @param Copy_uddtTMR_no [TMR2 - TMR3 - TMR4 - TMR5]
 * @return void
 */
void TMR_voidStop(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		CLR_BIT(TMR2_ADD -> CR1, CEN_BIT); break;
	case TMR3:
		CLR_BIT(TMR3_ADD -> CR1, CEN_BIT); break;
	case TMR4:
		SET_BIT(TMR4_ADD -> CR1, CEN_BIT); break;
	case TMR5:
		CLR_BIT(TMR5_ADD -> CR1, CEN_BIT); break;

	default:                               break;
	}
}

/**
 * @brief this function is used to set the prescaler
 * 
 * @param Copy_uddtTMR_no [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_u16Value value from 1 to 65536
 * @return void
 */
void TMR_voidSetPrescaler(TMRN_t Copy_uddtTMR_no, u16 Copy_u16Value)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		Clr_ALL_BITS(TMR2_ADD -> PSC);
		TMR2_ADD -> PSC |= Copy_u16Value - 1;
		break;
	case TMR3:
		Clr_ALL_BITS(TMR3_ADD -> PSC);
		TMR3_ADD -> PSC |= Copy_u16Value - 1;
		break;
	case TMR5:
		Clr_ALL_BITS(TMR5_ADD -> PSC);
		TMR5_ADD -> PSC |= Copy_u16Value - 1;
		break;
	default:                               break;
	}
}


void TMR_voidEnableOPM(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		SET_BIT(TMR2_ADD -> CR1, OPM_BIT);
		break;
	default:                               break;
	}
}

/**
 * @brief this function is used to set the timer mode when generating a signal
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_uddtFn timer mode [FROZEN - ACTIVE - INACTIVE - TOGGLE - INACTIVE_FORCE - ACTIVE_FORCE - PWM_MODE1 - PWM_MODE2]
 * @param Copy_uddtChNo Channel number [CH1 ~ CH4]
 * @return void
 */
void TMR_voidSetChannelOutput(TMRN_t Copy_uddtTMR_no, CMPFn_t Copy_uddtFn, CHN_t Copy_uddtChNo)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		switch(Copy_uddtChNo)
		{
		case CH1:
			Clr_BITS(TMR2_ADD -> CCMR1, 0x00000073);
			TMR2_ADD -> CCMR1 |= (Copy_uddtFn << OC1M_SHIFT);
			SET_BIT(TMR2_ADD -> CCER, CC1EN_BIT);
			break;
		case CH2:	break;
		case CH3:
			Clr_BITS(TMR2_ADD -> CCMR2, 0x00000073);
			TMR2_ADD -> CCMR2 |= (Copy_uddtFn << OC1M_SHIFT);
			SET_BIT(TMR2_ADD -> CCER, 8);
			break;
		case CH4:	break;
		}
		break;
		default:                               break;
	}
}

/**
 * @brief this function is used to set the compare value at the CCR_REG
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_uddtChNo Channel number [CH1 ~ CH4]
 * @param cmpValue compare value [0 ~ 65536]
 * @return void
 */
void TMR_voidSetCMPVal(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo, u32 cmpValue)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		switch(Copy_uddtChNo)
		{
		case CH1:
			TMR2_ADD -> CCR1 = cmpValue;
			break;
		case CH2:
			TMR2_ADD -> CCR2 = cmpValue;
			break;
		case CH3:
			TMR2_ADD -> CCR3 = cmpValue;
			break;
		case CH4:
			TMR2_ADD -> CCR4 = cmpValue;
			break;
		}
		break;
		default:                               break;
	}
}

/**
 * @brief this function is used to set the Auto Reload Preload Value - ARR
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_u32Value value [0 ~ 65536]
 * @return void
 */
void TMR_voidSetARR(TMRN_t Copy_uddtTMR_no, u32 Copy_u32Value)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		TMR2_ADD -> ARR = Copy_u32Value;
		break;
	case TMR3:
		TMR3_ADD -> ARR = Copy_u32Value;
		break;
	case TMR5:
		TMR5_ADD -> ARR = Copy_u32Value;
		break;
	default:                               break;
	}
}

/**
 * @brief this function is used to reset count (clear the CNT_REG)
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @return void
 */
void TMR_voidClearCount(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		TMR2_ADD -> CNT = 0;
		break;
	case TMR3:
		TMR3_ADD -> CNT = 0;
		break;
	case TMR5:
		TMR5_ADD -> CNT = 0;
		break;
	default:                               break;
	}
}

/**
 * @brief this function is used to enable the input capture unit - ICU
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 */
void TMR_voidEnableICUInt(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		SET_BIT(TMR2_ADD -> DIER, 1);
		break;
	case TMR3:
		SET_BIT(TMR3_ADD -> DIER, 1);
		break;
	case TMR4:
		break;
	case TMR5:
		SET_BIT(TMR5_ADD -> DIER, 1);
		break;
	}
}

/**
 * @brief this function is used to select the channel to use as input
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_uddtCH_no Channel number [CH1 ~ CH4]
 */
void TMR_voidSetChannelInput(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtCH_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:

		break;
	case TMR3:
		switch(Copy_uddtCH_no)
		{
		case CH1:
			Clr_BITS(TMR3_ADD -> CCMR1, 0x00000003);
			SET_BIT(TMR3_ADD -> CCMR1, CC1S_SHIFT);

			SET_BIT(TMR3_ADD -> CCER, CC1P_BIT);
			SET_BIT(TMR3_ADD -> CCER, CC1NP_BIT);

			SET_BIT(TMR3_ADD -> CCER, CC1EN_BIT);
			break;
		case CH2:
			break;
		case CH3:
			break;
		case CH4:
			break;
		}
		break;
		case TMR4:
			break;
		case TMR5:
			switch(Copy_uddtCH_no)
			{
			case CH1:
				Clr_BITS(TMR5_ADD -> CCMR1, 0x00000003);
				SET_BIT(TMR5_ADD -> CCMR1, CC1S_SHIFT);

				SET_BIT(TMR5_ADD -> CCER, CC1P_BIT);
				SET_BIT(TMR5_ADD -> CCER, CC1NP_BIT);

				SET_BIT(TMR5_ADD -> CCER, CC1EN_BIT);
				break;
			case CH2:
				break;
			case CH3:
				Clr_BITS(TMR5_ADD -> CCMR2, 0x00000003);
				SET_BIT(TMR5_ADD -> CCMR2, CC1S_SHIFT);

				SET_BIT(TMR5_ADD -> CCER, CC3P_BIT);
				SET_BIT(TMR5_ADD -> CCER, CC3NP_BIT);

				SET_BIT(TMR5_ADD -> CCER, CC3EN_BIT);
				break;
			case CH4:
				break;
			}
			break;
	}
}

/**
 * @brief this function is used to get the value of timer
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_uddtChNo Channel number [CH1 ~ CH4]
 * @return u32  value of timer count
 */
u32 TMR_voidReadCapture(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo)
{
	u32 reading = 0;
	switch(Copy_uddtTMR_no)
	{
	case TMR2:


		break;
	case TMR3:
		switch(Copy_uddtChNo)
		{
		case CH1:
			reading = TMR3_ADD -> CCR1;
			break;
		case CH2:
			reading = TMR3_ADD -> CCR2;
			break;
		case CH3:
			reading = TMR3_ADD -> CCR3;
			break;
		case CH4:
			reading = TMR3_ADD -> CCR4;
			break;
		}
		break;
		case TMR5:
			switch(Copy_uddtChNo)
			{
			case CH1:
				reading = TMR5_ADD -> CCR1;
				break;
			case CH2:
				reading = TMR5_ADD -> CCR2;
				break;
			case CH3:
				reading = TMR5_ADD -> CCR3;
				break;
			case CH4:
				reading = TMR5_ADD -> CCR4;
				break;
			}
			break;
			default:            break;
	}
	return reading;
}

void Timer3_voidCapture_Compare_Init(void)
{
	/*DIER Register*/

	SET_BIT(TMR3_ADD -> DIER , 1);	// Capture/Compare interrupt enable

	/*CCMR1 Register*/

	SET_BIT(TMR3_ADD -> CCMR1 , 0);	// configure timer3 ch1 as input
	CLR_BIT(TMR3_ADD -> CCMR1 , 1);

	CLR_BIT(TMR3_ADD -> CCMR1 , 2);	// configure timer3 ch1 to capture at every edge detected
	CLR_BIT(TMR3_ADD -> CCMR1 , 3);


	CLR_BIT(TMR3_ADD -> CCMR1 , 6);
	CLR_BIT(TMR3_ADD -> CCMR1 , 7);

	/*CCER Register*/

	SET_BIT(TMR3_ADD -> CCER , 0);	// Capture Enabled


	SET_BIT(TMR3_ADD -> CCER , 1);	// Capture/Compare channel captures on both edges (rising & falling)
	SET_BIT(TMR3_ADD -> CCER , 3);

	TMR_voidSetPrescaler(TMR3,64);

	TMR3_ADD -> ARR = 65535;

}





