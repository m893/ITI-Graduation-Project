/**
 * @file MRCC_config.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief MRCC_Config.h -> Configuration file for RCC peripheral
 * @version 0.1
 * @date 2023-06-8
 */


#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H

/*Select the Clock Source From The Following :
 * Options :
 *          1) HSI
 *          2) HSE
 *          3) PLL
 **/

#define MRCC_CLKSRC      HSI


/*Select the  Source of HSE From The Following :
 * Options :
 *          1) HSE_MECH
 *          2) HSE_RC
 **/

#define MRCC_HSE_SRC     HSE_MECH


/*Select the  Source of PLL From The Following :
 * Options :
 *          1) HSE_PLL
 *          2) HSI_PLL
 **/

#define MRCC_PLL_SRC     HSE_PLL

#endif /* MRCC_CONFIG_H_ */
