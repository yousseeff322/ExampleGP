/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 29 Aug 2024                 */
/* Version          : v01                        */
/*************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



typedef enum {
	V_Internal,
	V_External
}eV_Ref_t;


typedef enum {
	ADC1,
	ADC2
}eADC_Num_t;


typedef struct {
	eADC_Num_t ADC_Num;
	u16 ADC_Prescaller;/* Clock must not exceed 14 MHz, APB2 */
	eV_Ref_t V_Refrance; /*VREFINT are only available on the master ADC1 peripheral*/
}sADC_Config_t;




void ADC_voidInit(sADC_Config_t *ADC_Config) ;
u16  ADC_u16Read(eADC_Num_t ADC_Num,u8 Channel);
void ADC_voidEnableInterrupt(eADC_Num_t ADC_Num);
void ADC_voidDisableInterrupt(eADC_Num_t ADC_Num);

#endif
