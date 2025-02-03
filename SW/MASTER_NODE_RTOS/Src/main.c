#include "main.h"

/* Main function */
int main(void) {
    SystemInit();

    // Create Queue and Semaphore
    canQueue = xQueueCreate(5, sizeof(SensorData_t));
    canSemaphore = xSemaphoreCreateBinary();

    // Create FreeRTOS task for CAN reception
    xTaskCreate(AEBTask, "AEB", 128, NULL, 4, NULL);
    xTaskCreate(LKSTask, "LKS", 128, NULL, 3, NULL);
    xTaskCreate(CANReceiveTask, "CANReceive", 128, NULL, 3, NULL);
    xTaskCreate(ACCTask, "ACC", 128, NULL, 2, NULL);
    xTaskCreate(ALCTask, "ALC", 128, NULL, 1, NULL);
    xTaskCreate(BluetoothTask, "Bluetooth", 128, NULL, 1, NULL);

    /* Start scheduler */
    vTaskStartScheduler();

    while (1) {}
}

/* System Initialization */
void SystemInit(void) {
    MRCC_VidInit();
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOA_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOB_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, AFIO_RCC);

    CAN_voidInit();

    // Configure CAN filter to accept messages with ID = 0x123 only
    CAN_FilterTypeDef canFilter;
    canFilter.FilterBank = 0;
    canFilter.FilterMode = CAN_FILTERMODE_IDMASK;
    canFilter.FilterScale = CAN_FILTERSCALE_32BIT;
    canFilter.FilterIdHigh = 0x123 << 5;
    canFilter.FilterIdLow = 0;
    canFilter.FilterMaskIdHigh = 0xFFF << 5;
    canFilter.FilterMaskIdLow = 0;
    canFilter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    canFilter.FilterActivation = ENABLE;
    CAN_voidConfigFilter(&canFilter);

    CAN_voidStart();

    MotorDriver_voidInit() ;
}

/* CAN Receive Task */
void CANReceiveTask(void *pvParameters) {
    SensorData_t receivedData; // Local variable
    CAN_RxHeaderTypeDef rxHeader;
    uint8_t canData[5];

    while (1) {
        // Check if data is available in CAN FIFO
        if (CAN_voidRXPending(CAN_RX_FIFO0)) {
            // Retrieve the message from CAN FIFO
            CAN_voidGetRxMsg(CAN_RX_FIFO0, &rxHeader, canData);


            // Verify the received message ID
            if (rxHeader.StdId == 0x123) {
            	receivedData.LEFT_LDR = canData[0];
            	receivedData.RIGHT_LDR = canData[1];
            	receivedData.LEFT_IR = canData[2];
            	receivedData.RIGHT_IR = canData[3];
            	receivedData.ultrasonic = canData[4];
            	MGPIO_VidTogglePin(GPIOB , PIN0) ;
                // Send the received data to the queue
                xQueueSend(canQueue, &receivedData, portMAX_DELAY);
                // Signal that new data is available
                xSemaphoreGive(canSemaphore);
            }
        }
        // Delay to prevent CPU overuse
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

/* Automatic Emergency Braking Task */
void AEBTask(void *pvParameters) {
    SensorData_t receivedData;

    while (1) {
        // Wait for new sensor data from CANReceiveTask
        if (xQueueReceive(canQueue, &receivedData, portMAX_DELAY) == pdTRUE) {
            if (receivedData.ultrasonic < 10 || (receivedData.LEFT_IR == White && receivedData.RIGHT_IR == White))
            {
                MotorDriver_voidStop(); // Stop the car using motor driver
                BackLed_ON();
                Alarm_ON();
                vTaskDelay(pdMS_TO_TICKS(3000)); // Wait 3 seconds
                BackLed_OFF();
                Alarm_OFF();
            }
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}


/* Lane Keeping System Task */
void LKSTask(void *pvParameters) {
    SensorData_t receivedData;
    while (1) {
        if (xQueueReceive(canQueue, &receivedData, portMAX_DELAY) == pdTRUE) {
            if (receivedData.LEFT_IR == Black && receivedData.RIGHT_IR == Black) {
                MotorDriver_voidMoveForward(); // Move forward
            } else if (receivedData.LEFT_IR == Black && receivedData.RIGHT_IR == White) {
                MotorDriver_voidMoveRight(); // Move right
            } else if (receivedData.LEFT_IR == White && receivedData.RIGHT_IR == Black) {
                MotorDriver_voidMoveLeft(); // Move left
            }else {
                MotorDriver_voidStop(); // Stop if unclear condition
            }
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

/* Adaptive Cruise Control Task */
void ACCTask(void *pvParameters) {
    SensorData_t receivedData;
    while (1) {
        if (xQueueReceive(canQueue, &receivedData, portMAX_DELAY) == pdTRUE) {
            if (receivedData.ultrasonic > 50) {
                MotorDriver_voidControlSpeed(100); // Max speed
            } else if (receivedData.ultrasonic >= 10 && receivedData.ultrasonic <= 50) {
            	u8 adaptiveSpeed = (receivedData.ultrasonic - 10) * 2;
            	adaptiveSpeed = (adaptiveSpeed > 100) ? 100 : adaptiveSpeed;
            	MotorDriver_voidControlSpeed(adaptiveSpeed);
            }
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

/* Automatic Light Control Task */
void ALCTask(void *pvParameters) {
    SensorData_t receivedData;
    while (1) {
        if (xQueueReceive(canQueue, &receivedData, portMAX_DELAY) == pdTRUE) {
            if (receivedData.LEFT_LDR >= 93) {
                LEDS_SetMaxBrightness(); // Max lighting
            } else if (receivedData.LEFT_LDR >= 80 && receivedData.LEFT_LDR < 93) {
                LEDS_SetAdaptiveBrightness(receivedData.LEFT_LDR); // Adaptive lighting
            } else if (receivedData.LEFT_LDR >= 20 && receivedData.LEFT_LDR < 80) {
                LEDS_SetLowBrightness(); // Low brightness
            } else {
                LEDS_Off(); // Turn off LEDs
            }
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

/* Bluetooth Remote Control Task */
void BluetoothTask(void *pvParameters) {
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

