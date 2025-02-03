/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V02 (Supports Two LDRs)                */
/*********************************************************/

#include "STD_type.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "LDR_Interface.h"
#include "LDR_Config.h"

f32 LDR_f32ReadLightIntensity(u8 LDR_Number) {
    static f32 readings1[5] = {0};
    static f32 readings2[5] = {0};
    static u8 index1 = 0, index2 = 0;
    f32 sum = 0;
    u16 Local_u16ReadValue;
    f32 Local_f32LightIntensity;

    // Determine which LDR to read
    u8 channel = (LDR_Number == 1) ? LDR1_CHANNEL : LDR2_CHANNEL;

    // Read ADC Value from the corresponding LDR channel
    Local_u16ReadValue = (u16)ADC_u16Read(ADC1, channel);
    Local_f32LightIntensity = ((f32)Local_u16ReadValue / LDR_ADC_RESOLUTION) * LDR_VREF;

    // Store the new reading
    if (LDR_Number == 1) {
        readings1[index1] = Local_f32LightIntensity;
        index1 = (index1 + 1) % 5;
        for (u8 i = 0; i < 5; i++) sum += readings1[i];
    } else {
        readings2[index2] = Local_f32LightIntensity;
        index2 = (index2 + 1) % 5;
        for (u8 i = 0; i < 5; i++) sum += readings2[i];
    }

    return sum / 5;
}
