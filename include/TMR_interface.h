/**
 * @file Ultrasonic_interface.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
  * @brief TMR_interface.h -> functions prototype
 * @version 0.3
 * @date 2023-06-9
 */

#ifndef TMR_INTERFACE_H
#define TMR_INTERFACE_H


typedef enum
{
	TMR2,
	TMR3,
	TMR4,
	TMR5
}TMRN_t;

typedef enum
{
	CH1 = 1,
	CH2,
	CH3,
	CH4
}CHN_t;

typedef enum
{
	FROZEN,
	ACTIVE,
	INACTIVE,
	TOGGLE,
	INACTIVE_FORCE,
	ACTIVE_FORCE,
	PWM_MODE1,
	PWM_MODE2
}CMPFn_t;

typedef enum
{
	OUTPUT,
	IC_T2,
	IC_T1,
	IC_TRC
}CH_MODE_t;

typedef enum
{
	RISIN,
	FALLIN,
	RESERVED,
	BOTH
}EDGE_t;



void TMR_voidStart(TMRN_t Copy_uddtTMR_no);
void TMR_voidStop(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetPrescaler(TMRN_t Copy_uddtTMR_no, u16 Copy_u16Value);
void TMR_voidEnableOPM(TMRN_t Copy_uddtTMR_no);
void TMR_voidCountRst(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetChannelOutput(TMRN_t Copy_uddtTMR_no, CMPFn_t Copy_uddtFn, CHN_t Copy_uddtChNo);
void TMR_voidSetChannelInput(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtCH_no);
void TMR_voidSetARR(TMRN_t Copy_uddtTMR_no, u32 Copy_u32Value);
void TMR_voidStop(TMRN_t Copy_uddtTMR_no);
void TMR_voidClearCount(TMRN_t Copy_uddtTMR_no);
void TMR_voidEnableICUInt(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetCMPVal(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo, u32 cmpValue);
u32 TMR_voidReadCapture(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo);
void Timer3_voidCapture_Compare_Init(void);




#endif /* TMR_INT_H_ */
