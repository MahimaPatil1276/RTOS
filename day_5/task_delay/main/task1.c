#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void SensorTask(void *pv)
{
    while(1)
    {
        printf("Sensor Task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    xTaskCreate(SensorTask,"SensorTask",2048,NULL,5,NULL);
    printf("Hello World\n");
}