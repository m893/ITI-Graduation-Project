/**
 * @file FWCS_interface.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com)
 * @brief FWCS_interface.h -> functions prototype
 * @version 0.7
 * @date 2023-06-7
 */


#ifndef FWCS_INTERFACE_H
#define FWCS_INTERFACE_H



void FWC_voidSystemInit(void);
void FWC_voidGetDistance(void);
void FWC_voidGetCarSpeed(void);
void FWC_voidSystemStart(void);
void FWC_voidSendDataToGUI(void);
void start_motor(void);
void stop_motor(void);


#endif /* ACC_INTERFACE_H_ */
