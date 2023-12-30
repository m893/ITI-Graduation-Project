/**
 * @file MSTK_interface.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief MSTK_Interface.h -> Functions Prototypes
 * @version 0.1
 * @date 2023-06-8
 */



#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_


typedef enum
{
	ENABLE,
	TICKINT,
	CLKSRC,
	COUNTFLAG
}Ctrl_t;

typedef enum
{
	DIS,
	EN
}INTst_t;

void MSTK_voidInit(void);
void MSTK_voidStart(u32 Copy_u32PreloadValue);
u8 MSTK_u8ReadFlag(void);
void MSTK_voidINTStatus(u8 Copy_u8INTStatus);
void MSTK_voidDelay_ms(u32 Copy_u3Time);
void MSTK_voidDelay_us(u32 Copy_u3Time);




#endif /* MSTK_INTERFACE_H_ */
