/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 27 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#include "STD_type.h"
#include "BIT_math.h"

#include "DIO_interface.h"


#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*MSPI1_CallBack)(u8);

void MSPI1_voidInit(void)  
{
	/* 0000 1011 0100 0111 */ 
	MSPI1->CR1 = 0x0347;
	
}


void MSPI1_voidSendReciveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_DataToReceive )    // return after job finish 
{
	MGPIO_VidSetPinValue (MSPI1_SLAVE_PIN , LOW ) ;
	
	 /* send Data */ 
	MSPI1->DR = Copy_u8DataToTransmit ; 
	
	/* Wait Busy Flag */ 
	while (GET_BIT(MSPI1->SR , 7) == 1) ;
	
	/* Receive Data */ 
	
	*Copy_DataToReceive = MSPI1->DR  ; 
	
	
	MGPIO_VidSetPinValue (MSPI1_SLAVE_PIN , HIGH ) ;

}



void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8))
{
    // Set the slave select pin low to start the transmission
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN, LOW);

    // Load data into the data register to start transmission
    MSPI1->DR = Copy_u8DataToTransmit;

    // Enable SPI interrupt
    SET_BIT(MSPI1->CR2, 7); // Enable RXNE interrupt

    // Save the callback function
    MSPI1_CallBack = CallBack;
}


// SPI1 interrupt handler
void SPI1_IRQHandler(void)
{
    u8 ReceivedData;

    // Check if data is received
    if (GET_BIT(MSPI1->SR, 0)) // RXNE flag
    {
        // Read received data
        ReceivedData = MSPI1->DR;

        // Call the callback function with the received data
        MSPI1_CallBack(ReceivedData);

        // Set the slave select pin high to end the transmission
        MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN, HIGH);

        // Clear RXNE flag
        CLR_BIT(MSPI1->SR, 0); // RXNE flag
    }
}
