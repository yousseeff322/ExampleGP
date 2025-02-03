/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V02 (Supports Two LDRs)                */
/*********************************************************/

#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H

// ADC resolution (typically 12 bits for STM32)
#define LDR_ADC_RESOLUTION  4096

// ADC reference voltage (usually 3.3V for STM32)
#define LDR_VREF            3.3

// Resistor values used in the voltage divider with the LDR
#define FIXED_RESISTOR_OHMS 10000  // Example: 10kΩ fixed resistor



f32 LDR_f32ReadLightIntensity(u8 LDR_Number);

#endif  // LDR_INTERFACE_H
