#include "main.h"

void Task1Handler (void *parmeters) ;
void Task2Handler (void *parmeters) ;



void main(void)
{
	TaskHandle_t  HandleTask1  , HandleTask2  ;
	BaseType_t  Local_status ;



    MRCC_VidInit();
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOA_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, AFIO_RCC);

    MGPIO_VidSetPinDirection(GPIOA, PIN1, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPinDirection(GPIOA, PIN2, OUT_SPEED_2MHZ_PP);


    Local_status  = xTaskCreate(Task1Handler, "Task1", 200, "Hello Ftom TAsk1 " , 2	,&HandleTask1 ) ;
	configASSERT((Local_status == pdPASS));

    Local_status  = xTaskCreate(Task2Handler, "Task2", 200, "Hello Ftom TAsk2 " , 2	,&HandleTask2 ) ;
	configASSERT((Local_status == pdPASS));
	vTaskStartScheduler() ;

	while(1)
	{




	}

}
void Task1Handler (void *parmeters)
{

while(1)
{
	MGPIO_VidSetPinValue(GPIOA, PIN1, GPIO_HIGH) ;
    vTaskDelay(pdMS_TO_TICKS(500));  // Delay for 500 ms

}

}


void Task2Handler (void *parmeters)
{

while(1)
{

	MGPIO_VidSetPinValue(GPIOA, PIN2, GPIO_HIGH) ;
    vTaskDelay(pdMS_TO_TICKS(500));  // Delay for 500 ms

}

}

