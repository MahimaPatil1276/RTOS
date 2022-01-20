#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/queue.h>

#define ALARM_PIN 15

QueueHandle_t sensor_queue;


void SensorTask(void *pv)
{
    int sensor_data = 0;
    while(1)
    {
        sensor_data ++;
        printf("Sensor Task: sensor_data %d\n",sensor_data);
        xQueueSend(sensor_queue, &sensor_data, 1000/portTICK_PERIOD_MS);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void ProcessingTask(void *pv)
{
    int recv_data = 0;
    while(1)
    {
        xQueueReceive(sensor_queue, &recv_data,portMAX_DELAY);
        printf("Processing Task : recv_data %d\n", recv_data);
    }
}

void app_main()
{
    sensor_queue = xQueueCreate(10, sizeof(int));
    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 5, NULL);
    xTaskCreate(ProcessingTask, "ProcessingTask", 2048, NULL, 3, NULL);
    printf("Hello World\n");
}