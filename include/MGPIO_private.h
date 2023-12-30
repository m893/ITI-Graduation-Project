/**
 * @file MGPIO_private.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief registers definitions of GPIO peripheral
 * @version 0.1
 * @date 2023-06-8
 */


#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_


#define MGPIOA_BASE_ADDRESS		(0x40020000)
#define MGPIOB_BASE_ADDRESS		(0x40020400)
#define MGPIOC_BASE_ADDRESS		(0x40020800)


typedef struct
{
	u32 volatile MODER 		;
	u32 volatile OTYPER 	;
	u32 volatile OSPEEDR 	;
	u32 volatile PUPDR 		;
	u32 volatile IDR 		;
	u32 volatile ODR 		;
	u32 volatile BSRR 		;
	u32 volatile LCKR 		;
	u32 volatile AFRL 		;
	u32 volatile AFRH 		;

}MGPIOR_t;

#define MGPIOA 		((MGPIOR_t *) (MGPIOA_BASE_ADDRESS))
#define MGPIOB 		((MGPIOR_t *) (MGPIOB_BASE_ADDRESS))
#define MGPIOC 		((MGPIOR_t *) (MGPIOC_BASE_ADDRESS))














#endif /* MGPIO_PRIVATE_H_ */
