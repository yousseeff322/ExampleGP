/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V01                                     */
/*********************************************************/

#ifndef LDR_CONFIG_H
#define LDR_CONFIG_H

// ADC resolution (typically 12 bits for STM32)
#define LDR_ADC_RESOLUTION  4096

// ADC reference voltage (usually 3.3V for STM32)
#define LDR_VREF            3.3

// Resistor values used in the voltage divider with the LDR
// Adjust based on your specific circuit configuration
#define FIXED_RESISTOR_OHMS 10000  // Example: 10kΩ fixed resistor
#define LDR_CHANNEL         1      // The ADC channel the LDR is connected to

#endif  // LDR_CONFIG_H
