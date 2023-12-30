/**
 * @file MRCC_private.h
 * @authors 
 * Hossam Elzhar  (hossam.elzhar1@gmail.com)
 * Mohammed Akram  (mhmddakram2@gmail.com) 
 * @brief MRCC_Private.h -> Register Definitions
 * @version 0.1
 * @date 2023-06-8
 */



#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define MRCC_BASE_ADDRESS              0x40023800


#define MRCC_CR             (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define MRCC_PLLCFGR        (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x04)))
#define MRCC_CFGR           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x08)))
#define MRCC_CIR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x0C)))
#define MRCC_AHB1RSTR       (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x10)))
#define MRCC_AHB2RSTR       (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x14)))
#define MRCC_APB1RSTR       (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x20)))
#define MRCC_APB2RSTR       (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x24)))
#define MRCC_AHB1ENR        (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x30)))
#define MRCC_AHB2ENR        (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x34)))
#define MRCC_APB1ENR        (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x40)))
#define MRCC_APB2ENR        (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x44)))
#define MRCC_AHB1LPENR      (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x50)))
#define MRCC_AHB2LPENR      (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x54)))
#define MRCC_APB1LPENR      (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x60)))
#define MRCC_APB2LPENR      (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x64)))
#define MRCC_BDCR           (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x70)))
#define MRCC_CSR            (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x74)))
#define MRCC_SSCGR          (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x80)))
#define MRCC_PLLI2SCFGR     (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x84)))
#define MRCC_DCKCFGR        (*((volatile u32*)(MRCC_BASE_ADDRESS + 0x8C)))


/*System Clock Source */
#define  HSI        0U
#define  HSE        1U
#define  PLL        2U

/*HSE Clock Source */
#define  HSE_MECH   0U
#define  HSE_RC     1U



/*PLL Clock Source */
#define  HSE_PLL    0U
#define  HSI_PLL    1U


#endif /* MRCC_PRIVATE_H_ */
