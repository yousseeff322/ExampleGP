/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* options			*/
/* 	RCC_HSE_CRYSTAL */
/*  RCC_HSE_RC      */ 
/*  RCC_HSI         */ 
/*  RCC_PLL         */ 

#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL


/* option 			 		 */
/* 	RCC_PLL_HSI_DIV_2 		*/
/*  RCC_PLL_HSE_DIV_2      */ 
/*  RCC_PLL_HSE           */ 

/* select value if you choose RCC_PLL */ 
#if RCC_PLL == RCC_PLL

#define RCC_PLL_INPUT   RCC_PLL_HSI_DIV_2

#endif


/********************************************************************************************/
/*                              ClockFactor For PLL  Maybe :                                */
/*                              0-NO_CLOCK_FACTOR                                           */
/*                              1-PLL_Clock_MULTIPLE_BY_2                                   */
/*                              2-PLL_Clock_MULTIPLE_BY_3                                   */
/*                              3-PLL_Clock_MULTIPLE_BY_4                                   */
/*                              4-PLL_Clock_MULTIPLE_BY_5                                   */
/*                              5-PLL_Clock_MULTIPLE_BY_6                                   */
/*                              6-PLL_Clock_MULTIPLE_BY_7                                   */
/*                              7-PLL_Clock_MULTIPLE_BY_8                                   */
/*                              8-PLL_Clock_MULTIPLE_BY_9                                   */
/*                              9-PLL_Clock_MULTIPLE_BY_10                                  */
/*                              10-PLL_Clock_MULTIPLE_BY_11                                 */
/*                              11-PLL_Clock_MULTIPLE_BY_12                                 */
/*                              12-PLL_Clock_MULTIPLE_BY_13                                 */
/*                              13-PLL_Clock_MULTIPLE_BY_14                                 */
/*                              14-PLL_Clock_MULTIPLE_BY_15                                 */
/*                              15-PLL_Clock_MULTIPLE_BY_16                                 */
/********************************************************************************************/


#define RCC_PLL_MUL_VAL   PLL_CLOCK_MULTIPLE_BY_16




/**********************************************************************/
/*                                                                    */
/*                 Clock Security System May be                       */
/*                 1-ENABLE_CLOCK_SECURITY_SYSTEM:                                          */
/* 				  	-To Set HSI By H.W When There are Failure In HSE  */
/* 				    -To Set HSI By H.W When Leaving Stop Or Standby   */
/* 				   2-DISABLE_CLOCK_SECURITY_SYSTEM                                          */
/* 				   The Previouse Feature Does not Happen              */
/*                                                                    */
/**********************************************************************/

#define CLOCK_SECURITY_SYSTEM     DISABLE_CLOCK_SECURITY_SYSTEM













#endif
