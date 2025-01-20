#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"
#include "FunHelp.h"

#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"


void PWM_voidInit(sPWM_Confg_t *PWM_Config)
{

	if (PWM_Config->TimerSelect ==PWM_TIMER1 ){
		/* Enable clock */
		MRCC_VidEnablePeripheralClock(RCC_APB2 , TIM1_RCC);
	}
	else {

		MRCC_VidEnablePeripheralClock(RCC_APB2 , TIM8_RCC);

	}
	SET_BIT(TIMx[PWM_Config->TimerSelect]->CR1,7);
	/* Set counter direction as up-counter */
	CLR_BIT(TIMx[PWM_Config->TimerSelect]->CR1,4);
	  /* Select master mode Compare */
	  /* Compare - OC1REF signal is used as trigger output (TRGO)  */
	SET_BIT(TIMx[PWM_Config->TimerSelect]->CR2,6);
	SET_BIT(TIMx[PWM_Config->TimerSelect]->SMCR ,7);

  /* Set timer Prescaler, bus clock = 90 MHz, fCK_PSC / (PSC[15:0] + 1)
   * CK_CNT = F / (PSC+1) -> FREQ Hz -> time base = 1/FREQ */
  TIMx[PWM_Config->TimerSelect]->PSC = PWM_Config->Prescaler;
  /* Set timer auto reload value to maximum */
  TIMx[PWM_Config->TimerSelect]->ARR = PWM_Config->AutoReloadReg;;
	  /* Set duty cycle */
  TIMx[PWM_Config->TimerSelect]->CCR1 = 0x00;

	for (u8 i=0;i<4;i++){
		if (i <2){
		/* Set Capture/Compare  as output */
			CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCMR1,(0+(i*8)));
		/* Set Capture/Compare  as output */
			CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCMR1,(1+(i*8)));
		/* Output Compare  preload enable */
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCMR1,(3+(i*8)));

		/* Select Output Compare 1 PWM mode 1
		* TIMx_CNT < TIMx_CCR1 -> Output Active
		* TIMx_CNT >= TIMx_CCR1 -> Output Inactive
		* 110: PWM mode 1 - In upcounting,
		* channel 1 is active as long as TIMx_CNT<TIMx_CCR1
		* else inactive. In downcounting, channel 1 is inactive (OC1REF=‘0’) as long as */

		CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCMR1,(4+(i*8)));
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCMR1,(5+(i*8)));
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCMR1,(6+(i*8)));
		}else
		{
		/* Set Capture/Compare  as output */
			CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCMR2,(0+((i-2)*8)));
		/* Set Capture/Compare  as output */
			CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCMR2,(1+((i-2)*8)));
		/* Output Compare  preload enable */
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCMR2,(3+((i-2)*8)));

		/* Select Output Compare  PWM mode 1
		* TIMx_CNT < TIMx_CCR1 -> Output Active
		* TIMx_CNT >= TIMx_CCR1 -> Output Inactive */
		CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCMR2,(4+((i-2)*8)));
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCMR2,(5+((i-2)*8)));
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCMR2,(6+((i-2)*8)));
		}
    }


	/* Select Capture/Compare 1 output polarity active high */
	CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCER,1);

	if (PWM_Config->CCR1_Status == CCR_ENABLE )
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCER,0); /* Enable Capture/Compare output */
    else
    	CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCER,0);

	if (PWM_Config->CCR2_Status == CCR_ENABLE )
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCER,4); /* Enable Capture/Compare output */
    else
    	CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCER,4);

  	if (PWM_Config->CCR3_Status == CCR_ENABLE )
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCER,8); /* Enable Capture/Compare output */
    else
    	CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCER,8);

  	if (PWM_Config->CCR4_Status == CCR_ENABLE )
		SET_BIT(TIMx[PWM_Config->TimerSelect]->CCER,12); /* Enable Capture/Compare output */
    else
    	CLR_BIT(TIMx[PWM_Config->TimerSelect]->CCER,12);


  /* Initialize all the registers */
  SET_BIT(TIMx[PWM_Config->TimerSelect]->EGR ,0);
  /* Enable timer main output */
  SET_BIT(TIMx[PWM_Config->TimerSelect]->BDTR ,15);
  /* Enable TIMx */
  SET_BIT(TIMx[PWM_Config->TimerSelect]->CR1,0);
}



void PWM_voidUpdate(ePWM_TimerSelect_t Timer ,eCCR_Channel_t channel, u8 duty ){
	switch (channel){
		case Channel_1:
		TIMx[Timer]->CCR1=map(duty, 0, 100, 0, TIMx[Timer]->ARR);
		break ;
		case Channel_2:
		TIMx[Timer]->CCR2=map(duty, 0, 100, 0, TIMx[Timer]->ARR);
		break ;
		case Channel_3:
		TIMx[Timer]->CCR3=map(duty, 0, 100, 0, TIMx[Timer]->ARR);
		break ;
		case Channel_4:
		TIMx[Timer]->CCR4=map(duty, 0, 100, 0, TIMx[Timer]->ARR);
		break ;
	}

}






