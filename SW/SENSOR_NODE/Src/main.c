#include "main.h"



/* Main Function */
int main(void) {
    SystemInit();

    // Create Queue and Semaphore
    canQueue = xQueueCreate(5, sizeof(SensorData_t));
    canSemaphore = xSemaphoreCreateBinary();

    // Create FreeRTOS tasks
    xTaskCreate(SensorReadTask, "SensorRead", 256, NULL, 2, NULL);
    xTaskCreate(CANSendTask, "CANSend", 256, NULL, 1, NULL);

    // Start scheduler
    vTaskStartScheduler();

    while (1) {}  // Should never reach here
}

/* System Initialization */
void SystemInit(void) {
    MRCC_VidInit();
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOA_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOB_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, AFIO_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, ADC1_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, ADC2_RCC);

    MTIMER2_init(delay_us);
    MTIMER3_init(PWM_channel_1_IN);
    CAN_voidInit();
    CAN_voidStart();
}

/* Sensor Reading Task */
void SensorReadTask(void *pvParameters) {
    SensorData_t sensorData;
    while (1) {
        // Read LDR sensors
        sensorData.LEFT_LDR =  1 ; //(uint8_t)((LDR_f32ReadLightIntensity(1) / LDR_VREF) * 255.0f);
        sensorData.RIGTH_LDR = 2 ;  //(uint8_t)((LDR_f32ReadLightIntensity(2) / LDR_VREF) * 255.0f);

        // Read IR sensors
        sensorData.LEFT_IR =  3 ;    //Left_IR_Measurement();
        sensorData.RIGTH_IR =  4 ; //Right_IR_Measurment();

        // Trigger and Read Ultrasonic Sensor
      //  HULTRA_Trig(GPIOA, PIN6);
     //   vTaskDelay(pdMS_TO_TICKS(10));
        sensorData.ultrasonic =   5 ;  // (uint8_t)HULTRA_Distance(MTIMER3_CH2_PORTA_7);

        // Send data to Queue
        if (xQueueSend(canQueue, &sensorData, portMAX_DELAY) != pdTRUE) {
            // Handle Queue Full case (optional: increase queue size)
        }

        // Toggle GPIO for debugging

        // Signal CANSendTask to transmit
        xSemaphoreGive(canSemaphore);

        // Optimized Delay
        vTaskDelay(pdMS_TO_TICKS(250));  // Adjusted for responsiveness
    }
}

/* CAN Transmission Task */
void CANSendTask(void *pvParameters) {
    SensorData_t sensorData;
    CAN_TxHeaderTypeDef txHeader;
    uint8_t canData[5];

    txHeader.DLC = 5;
    txHeader.IDE = CAN_ID_STD;
    txHeader.StdId = 0x123;
    txHeader.RTR = CAN_RTR_DATA;

    while (1) {
        // Wait for semaphore signal
        if (xSemaphoreTake(canSemaphore, portMAX_DELAY) == pdTRUE) {
            // Receive data from Queue
            if (xQueueReceive(canQueue, &sensorData, 0) == pdTRUE) {
                // Prepare data for CAN transmission
                canData[0] = sensorData.LEFT_LDR;
                canData[1] = sensorData.RIGTH_LDR;
                canData[2] = sensorData.LEFT_IR;
                canData[3] = sensorData.RIGTH_IR;
                canData[4] = sensorData.ultrasonic;
                MGPIO_VidTogglePin(GPIOA, PIN10);

                // Transmit data via CAN
                if (CAN_voidAddTxMsg(&txHeader, canData) != 0) {
                    // Handle transmission failure (e.g., retry)
                }
            }
        }

        // Shorter delay for better responsiveness
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
