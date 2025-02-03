/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void MRCC_VidInit ( void ) {
	
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	
			RCC_CR = 0x00010000	;		
			RCC_CFGR =0x00000001 ;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR = 0x00050000	;	/* enable HSE with BYP */ 
			RCC_CFGR =0x00000001 ;


	#elif   RCC_CLOCK_TYPE == RCC_HSI
	
			RCC_CR = 0x00000081	;	/* enable HSI RC */ 
			RCC_CFGR =0x00000000 ;



	#elif   RCC_CLOCK_TYPE == RCC_PLL
	
	/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* PLL Selected As A System Clock */
		CLR_BIT( RCC_CFGR , 0  );
		SET_BIT( RCC_CFGR , 1  );
			#if RCC_PLL_INPUT ==  RCC_PLL_HSI_DIV_2
			
						CLR_BIT( RCC_CFGR , 16 );

			
			#elif RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2
			
			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( RCC_CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( RCC_CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Divided */
			SET_BIT( RCC_CFGR , 17 );
			
			
			#elif RCC_PLL_INPUT == RCC_PLL_HSE
			
		/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( RCC_CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( RCC_CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Not Divided */
			CLR_BIT( RCC_CFGR , 17 );
			
			
			#else
				#error("you chosed wrong Pll input")
			#endif
			


				SET_BIT( RCC_CR , 24 );


	#else
		#error("you chosed wrong clock type")
	
	
	
	#endif
	
	
	/* For Clock Security System */
	#if CLOCK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM

			SET_BIT(RCC_CR , 19 ) ; 
	#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM

			CLR_BIT(RCC_CR , 19 ) ; 

	#else

		#warning " Wrong Clock Security System Configuration Choice "

	#endif
}





















void MRCC_VidEnablePeripheralClock (u8 Copy_u8BusID , u8 Copy_u8Peripheral){
	
	if (Copy_u8Peripheral <=31 )
	{
		
		switch (Copy_u8BusID)
		{
			case RCC_AHB   :	SET_BIT(RCC_AHBENR  , Copy_u8Peripheral ) ; break ;  
			case RCC_APB1  :	SET_BIT(RCC_APB1ENR , Copy_u8Peripheral ) ; break ;
			case RCC_APB2  :	SET_BIT(RCC_APB2ENR , Copy_u8Peripheral ) ; break ;
		//	default 	   :   		/* Return Error */ 			       break ; 

			

		}
		
	}
	else 
	{
		/* Return Error */ 
		
	}		
	
}


void MRCC_VidDisablePeripheralClock (u8 Copy_u8BusID , u8 Copy_u8Peripheral){
	
	if (Copy_u8Peripheral <=31 )
	{
		
		switch (Copy_u8BusID)
		{
			case RCC_AHB   :	CLR_BIT(RCC_AHBENR  , Copy_u8Peripheral ) ; break ;  
			case RCC_APB1  :	CLR_BIT(RCC_APB1ENR , Copy_u8Peripheral ) ; break ;
			case RCC_APB2  :	CLR_BIT(RCC_APB2ENR , Copy_u8Peripheral ) ; break ;
		//	default 	   :   		/* Return Error */ 			       break ; 

			

		}
		
	}
	else 
	{
		/* Return Error */ 
		
	}		
	
}




void MRCC_voidSetADCPrescaler(u16 Copy_u16Prescaler) {

	CLR_BIT(RCC_CFGR, 14);
    CLR_BIT(RCC_CFGR, 15);

    switch (Copy_u16Prescaler) {
        case ADC_PRESCALER_DIV2:
            // ADCPRE = 00: PCLK2 divided by 2
            break;
        case ADC_PRESCALER_DIV4:
            // ADCPRE = 01: PCLK2 divided by 4
            SET_BIT(RCC_CFGR, 14);
            break;
        case ADC_PRESCALER_DIV6:
            // ADCPRE = 10: PCLK2 divided by 6
            SET_BIT(RCC_CFGR, 15);
            break;
        case ADC_PRESCALER_DIV8:
            // ADCPRE = 11: PCLK2 divided by 8
            SET_BIT(RCC_CFGR, 14);
            SET_BIT(RCC_CFGR, 15);
            break;
        default:
            break;
    }
}


