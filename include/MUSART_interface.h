/**
 * @file MUSART_interface.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief MUSART_Interface.c --> functions prototype
 * @version 0.1
 * @date 2023-06-8
 */


#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H



void MSUART_voidInit(void);

void MUSART_voidEnable(u8 copy_u8Index);

void MUSART_voidDisable(u8 copy_u8Index);

void MUSART_voidSendArrayData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len);
void MUSART_voidSendData(u8 copy_u8Index, u8 copy_u8Data);

u8 MUSART_u8ReadData(u8 copy_u8Index);


#endif //UART_INTERFACE_H_
