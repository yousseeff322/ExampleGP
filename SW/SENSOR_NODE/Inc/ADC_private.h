/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 29 Aug 2024                 */
/* Version          : v01                        */
/*************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADC1_BASE_ADDRESS         0x40012400
#define ADC2_BASE_ADDRESS         0x40012800


typedef struct
{
    volatile u32 SR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMPR1;
    volatile u32 SMPR2;
    volatile u32 JOFR1;
    volatile u32 JOFR2;
    volatile u32 JOFR3;
    volatile u32 JOFR4;
    volatile u32 HTR;
    volatile u32 LTR;
    volatile u32 SQR1;
    volatile u32 SQR2;
    volatile u32 SQR3;
    volatile u32 JSQR;
    volatile u32 JDR1;
    volatile u32 JDR2;
    volatile u32 JDR3;
    volatile u32 JDR4;
    volatile u32 DR;
}sADC_t;



sADC_t * ADCx[2]=
{
	(( sADC_t*)ADC1_BASE_ADDRESS),             //adc1
	(( sADC_t*)ADC2_BASE_ADDRESS),
};


static void ADC_voidOn(eADC_Num_t ADC_Num);
static void ADC_voidOff(eADC_Num_t ADC_Num);


#endif
