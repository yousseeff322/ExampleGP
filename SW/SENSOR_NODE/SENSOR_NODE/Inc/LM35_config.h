/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V01                                     */
/*********************************************************/

#ifndef LM35_CONFIG_H
#define LM35_CONFIG_H

// ADC resolution (typically 12 bits for STM32)
#define LM35_ADC_RESOLUTION  4096

// ADC reference voltage (usually 3.3V for STM32)
#define LM35_VREF            3.3

// LM35 conversion factor: 10 mV per degree Celsius
#define LM35_CONVERSION_FACTOR  0.01  // 10 mV -> 0.01 V per °C

// The ADC channel where the LM35 is connected
#define LM35_CHANNEL         2  // Change to the ADC channel connected to the LM35

#endif  // LM35_CONFIG_H
