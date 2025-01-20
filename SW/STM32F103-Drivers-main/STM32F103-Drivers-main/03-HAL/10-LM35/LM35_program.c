/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V01                                     */
/*********************************************************/

#include "STD_type.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "LM35_Interface.h"
#include "LM35_Config.h"

f32 LM35_f32ReadTemperature(void) {
    u16 Local_u16ReadValue = 0;
    f32 Local_f32Temperature = 0.0;

    // Read ADC Value from the defined LM35 channel
    Local_u16ReadValue = (u16)ADC_u16Read(ADC1, LM35_CHANNEL);

    // Calculate the voltage from ADC value
    f32 voltage = ((f32)Local_u16ReadValue / LM35_ADC_RESOLUTION) * LM35_VREF;

    // Calculate the temperature in Celsius
    Local_f32Temperature = voltage / LM35_CONVERSION_FACTOR;

    return Local_f32Temperature;
}
