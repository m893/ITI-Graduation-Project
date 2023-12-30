/**
 * @file MGPIO_interface.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief MGPIO_Interface.h -> Function Prototypes
 * @version 0.1
 * @date 2023-06-8
 */


#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H



typedef enum
{
	MGPIO_PortA,
	MGPIO_PortB,
	MGPIO_PortC

}MGPIO_t;


typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;


typedef enum
{
	MGPIO_SPEED_LOW,
	MGPIO_SPEED_MED,
	MGPIO_SPEED_HIGH,
	MGPIO_SPEED_VHIGH
}Speed_t;


typedef enum
{
	MGPIO_PIN_INPUT,
	MGPIO_PIN_OUTPUT,
	MGPIO_PIN_ALTF,
	MGPIO_PIN_ANLG
}PinMode_t;


typedef enum
{
	MGPIO_PORT_INPUT,
	MGPIO_PORT_OUTPUT,
	MGPIO_PORT_ALTF,
	MGPIO_PORT_ANLG
}PortMode_t;


typedef enum
{
	MGPIO_PUSH_PULL,
	MGPIO_OPEN_DRAIN
}OutputType_t;

typedef enum
{
	MGPIO_PIN_FLOAT,
	MGPIO_PIN_PULL_UP,
	MGPIO_PIN_PULL_DOWN
}PullMode_t;

typedef enum
{
	MGPIO_PIN_LOW,
	MGPIO_PIN_HIGH
}PinValue_t;


typedef enum
{
	MGPIO_PORT_LOW,
	MGPIO_PORT_HIGH
}PortValue_t;


typedef enum
{
	Reset,
	Set
}SetReset_t;


typedef enum
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
}ALTF_t;



void MGPIO_voidSetPinMode(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PinMode);

void MGPIO_voidSetPortMode(MGPIO_t Copy_uddtPortNum , u8 Copy_u8PortMode);

void MGPIO_voidSetOutputType(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , OutputType_t CopyuddtPinOutType);

void MGPIO_voidSetOutputPinSpeed(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum ,Speed_t CopyuddtPinOutSpeed);

void MGPIO_voidSetPinPullType(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PullMode);

void MGPIO_voidSetPinValue(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PinValue);

void MGPIO_voidSetPortValue(MGPIO_t Copy_uddtPortNum , u8 Copy_u8PortValue);

u8 MGPIO_voidGetPinValue(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum);

void MGPIO_voidSetResetPin(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum ,SetReset_t Copy_u8AtomPinMode);

void MGPIO_voidSetPinLock(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum );


void MGPIO_voidSetPinAltFunction(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , ALTF_t Copy_uddtALF);


#endif /* MGPIO_INTERFACE_H_ */
