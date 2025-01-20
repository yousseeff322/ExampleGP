/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 6 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#include "STD_type.h"
#include "BIT_math.h"

#include "DIO_interface.h" 


#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void Led_voidOn (u8 Copy_u8Port , u8 Copy_u8Pin ) {
	
	
		MGPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin , GPIO_HIGH ) ;
	
	
}



void Led_voidOff (u8 Copy_u8Port , u8 Copy_u8Pin ) {
	
	
	
		MGPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin , GPIO_LOW ) ;

	
	
} 




void Led_voidToggle (u8 Copy_u8Port , u8 Copy_u8Pin ) {
	
	
	
	
		MGPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin , GPIO_HIGH ) ;
		for (u16 i=0 ; i <w ; i++) {

					for(u16 j=0 ; j<w ; j++)
					{

						asm("NOP") ;
					}
				}
		MGPIO_voidSetPinValue(Copy_u8Port , Copy_u8Pin , GPIO_LOW ) ;
		for (u16 i=0 ; i <w ; i++) {

					for(u16 j=0 ; j<w ; j++)
					{

						asm("NOP") ;
					}
				}

	}
	
 
