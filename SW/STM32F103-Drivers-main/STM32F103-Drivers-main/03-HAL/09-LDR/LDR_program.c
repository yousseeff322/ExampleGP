/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V01                                     */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "LDR_Interface.h"
#include "LDR_Config.h"

f32 LDR_f32ReadLightIntensity(void) {
    u16 Local_u16ReadValue = 0;
    f32 Local_f32LightIntensity = 0.0;
    
    // Read ADC Value from the defined LDR channel
    Local_u16ReadValue = (u16)ADC_u16Read(ADC1, LDR_CHANNEL);

    // Calculate the light intensity based on the ADC reading
    // Formula: (ADC_Value / ADC_Resolution) * VREF
    Local_f32LightIntensity = ((f32)Local_u16ReadValue / LDR_ADC_RESOLUTION) * LDR_VREF;
    
    return Local_f32LightIntensity;
}
