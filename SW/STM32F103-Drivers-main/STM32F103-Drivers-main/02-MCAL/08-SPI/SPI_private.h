/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 27 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
			
typedef struct{

	volatile u32 CR1 ;
	volatile u32 CR2 ;
	volatile u32 SR  ;
	volatile u32 DR;
	volatile u32 CRCPR ;
	volatile u32 RXCRCR ;
	volatile u32 TXCRCR  ;


}SPI_Register;

#define MSPI1 ((volatile SPI_Register*)0x40013000)



 



#endif