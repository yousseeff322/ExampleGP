#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"



void ADC_voidInit(sADC_Config_t *ADC_Config) {


    // Enable the ADC (ADON bit must be set twice to start the ADC)
    SET_BIT(ADCx[ADC_Config->ADC_Num]->CR2, 0);
    ADC_voidOn(ADC_Config->ADC_Num);  // Ensure the ADC is properly powered up

    // Set ADC prescaler (must ensure it doesn't exceed 14 MHz)
      MRCC_voidSetADCPrescaler(ADC_Config->ADC_Prescaller);

    // Set ADC to single conversion mode
    CLR_BIT(ADCx[ADC_Config->ADC_Num]->CR1, 1);

    // Disable scan mode for single-channel conversion
    CLR_BIT(ADCx[ADC_Config->ADC_Num]->CR1, 8);

    // Disable discontinuous mode on regular channels
    CLR_BIT(ADCx[ADC_Config->ADC_Num]->CR1, 11);

    // Set data alignment to right (clear ALIGN bit)
    CLR_BIT(ADCx[ADC_Config->ADC_Num]->CR2, 11);

    // Set ADC to single conversion mode (CONT bit = 0)
    CLR_BIT(ADCx[ADC_Config->ADC_Num]->CR2, 1);

    // Configure voltage reference if applicable
    if (ADC_Config->ADC_Num == ADC1) {
        // Enable/Disable Temperature sensor and VREFINT based on the voltage reference
        if (ADC_Config->V_Refrance == V_Internal) {
            SET_BIT(ADCx[ADC_Config->ADC_Num]->CR2, 23);  // Enable TSVREFE
        } else {
            CLR_BIT(ADCx[ADC_Config->ADC_Num]->CR2, 23);  // Disable TSVREFE
        }
    }
}



u16 ADC_u16Read(eADC_Num_t ADC_Num, u8 Channel) {
    // Validate channel number
    if (Channel > 15) {
        return 0; // Invalid channel number, handle error
    }

    // Ensure ADC is on and ready
    ADC_voidOn(ADC_Num);   // Power up ADC
    ADC_voidOn(ADC_Num);   // Ensure ADC is ready (ADON bit must be set twice)

    // Clear previous channel selection and set new channel
    ADCx[ADC_Num]->SQR3 &= 0xFFFFFFF0;  // Clear channel selection
    ADCx[ADC_Num]->SQR3 |= Channel;     // Set new channel

    // Start conversion of regular channels
    SET_BIT(ADCx[ADC_Num]->CR2, 22);

    // Wait till conversion is complete (End of Conversion flag is set)
    while (GET_BIT(ADCx[ADC_Num]->SR, 1) == 0);  // Corrected loop structure

    // Read the converted result from the data register
    u16 Result = (u16)ADCx[ADC_Num]->DR;

    // Clear end of conversion (EOC) and other status flags
    CLR_BIT(ADCx[ADC_Num]->SR, 1); // Clear EOC flag
    CLR_BIT(ADCx[ADC_Num]->SR, 4); // Clear STRT flag

    // Power down the ADC to save power
    ADC_voidOff(ADC_Num);

    return Result;
}


void ADC_voidEnableInterrupt(eADC_Num_t ADC_Num) {
    SET_BIT(ADCx[ADC_Num]->CR1, 5);  // Enable EOC (End of Conversion) interrupt
}

void ADC_voidDisableInterrupt(eADC_Num_t ADC_Num) {
    CLR_BIT(ADCx[ADC_Num]->CR1, 5);  // Disable EOC interrupt
}




static void ADC_voidOn(eADC_Num_t ADC_Num){

	SET_BIT(ADCx[ADC_Num]->CR2,0);
}

static void ADC_voidOff(eADC_Num_t ADC_Num){

	CLR_BIT(ADCx[ADC_Num]->CR2,0);
}
