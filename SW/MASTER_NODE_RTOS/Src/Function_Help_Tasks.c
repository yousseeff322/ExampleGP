#include "STD_type.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "TIMER3_interface.h"

#include "Function_Help_Tasks.h"


void BackLed_ON() {
    MGPIO_VidSetPinValue(GPIOA, PIN5, HIGH); // Turn on back LED
}

void BackLed_OFF() {
    MGPIO_VidSetPinValue(GPIOA, PIN5, LOW); // Turn off back LED
}

void Alarm_ON() {
    MGPIO_VidSetPinValue(GPIOA, PIN6, HIGH); // Activate alarm buzzer
}

void Alarm_OFF() {
    MGPIO_VidSetPinValue(GPIOA, PIN6, LOW); // Deactivate alarm buzzer
}


/* LED Control Functions using TIMER3 and DIO */
void LEDS_SetMaxBrightness() {
    MTIMER3_PWM(1, 100, 99); // Set max PWM duty cycle
}

void LEDS_SetAdaptiveBrightness(u8 level) {
    u8 brightness = ((level - 80) * 99) / 13; // Scale brightness proportionally
    MTIMER3_PWM(1, 100, brightness);
}

void LEDS_SetLowBrightness() {
    MTIMER3_PWM(1, 100, 30); // Set low brightness
}

void LEDS_Off() {
    MGPIO_VidSetPinValue(GPIOA, PIN5, LOW); // Turn off LEDs via GPIO
}
