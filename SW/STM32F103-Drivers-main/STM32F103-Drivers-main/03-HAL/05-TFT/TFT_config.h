/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 29 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#ifndef TFT_CONFIG_H_
#define TFT_CONFIG_H_
/* Write pin in pair port,pin */
#define 	TFT_A0_PIN   GPIOA,2
#define 	TFT_RST_PIN	 GPIOA,1

/* Write pin in pair port,pin */
#define    TFT_SLAVE_PIN   GPIOA,3   // slave select pin


/* Configure TFT size */
#define    TFT_MAX_X       127
#define    TFT_MAX_Y       159
	
#endif
