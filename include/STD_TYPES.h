/**
 * @file STD_TYPES.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com)
 * @version 0.1
 * @date 2023-06-7
 */
#ifndef STD_TYPES_H
#define STD_TYPES_H
		
		
#ifndef		FALSE
#define		FALSE   (0u)
#endif
	
#ifndef		TRUE
#define		TRUE    (1u)
#endif
	
	
	
typedef unsigned char					    u8;						
typedef unsigned short int			        u16;					
typedef unsigned long  int			        u32;					
typedef signed char					        s8;							
typedef signed short int				    s16;						
typedef signed long  int				    s32;						
typedef unsigned long long int				u64;
typedef signed long long int				s64;
typedef float						        f32;
typedef double						        f64;


#define NULL  		(void*)0


#endif /* STD_TYPES_H_ */
