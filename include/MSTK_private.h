/**
 * @file MSTK_private.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief MSTK_Private.h -> Register Definitions
 * @version 0.1
 * @date 2023-06-8
 */

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_


#define MSTK_Base_Address	(0xE000E010)

typedef struct
{
	u32 volatile CTRL;
	u32 volatile LOAD;
	u32 volatile VAL;
	u32 volatile CALIB;
}MSTKR_t;


#define MSTK	((MSTKR_t *)(MSTK_Base_Address))






#endif /* MSTK_PRIVATE_H_ */
