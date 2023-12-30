/**
 * @file  MNVIC_interface.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief NVIC_Interface.c --> implementations
 * @version 0.1
 * @date 2023-06-8
 */



#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


#define		MNVIC_TIM3_NUM		29

typedef enum
{
 NVIC_GROUP_MODE_G16S0 = 3 ,
 NVIC_GROUP_MODE_G8S2      ,
 NVIC_GROUP_MODE_G4S4      ,
 NVIC_GROUP_MODE_G2S8      ,
 NVIC_GROUP_MODE_G0S16
}NVIC_GroupMode_t ;

typedef struct
{
	u8 Copy_u8IntNum ;
	NVIC_GroupMode_t Copy_uddtGroupMode ;
	u8 Copy_GroupPriority  ;
	u8 Copy_SubPriority  ;

}NVIC_PriorityConfig_t ;


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum) ;



#endif /* NVIC_INTERFACE_H_ */
