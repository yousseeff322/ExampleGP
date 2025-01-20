/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 27 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
			

void MSPI1_voidInit(void) ;   

void MSPI1_voidSendReciveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_DataToReceive ) ;   // return after job finish 

void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));






#endif