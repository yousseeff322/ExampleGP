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
     
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}


/* Lane Keeping System Task */
void LKSTask(void *pvParameters) {
    SensorData_t receivedData;
    while (1) {
       
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

/* Adaptive Cruise Control Task */
void ACCTask(void *pvParameters) {
    SensorData_t receivedData;
    while (1) {
      
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

/* Automatic Light Control Task */
void ALCTask(void *pvParameters) {
    SensorData_t receivedData;
    while (1) {
     
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

/* Bluetooth Remote Control Task */
void BluetoothTask(void *pvParameters) {
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

