#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <freertos/event_groups.h>


TaskHandle_t temp_handle;
TaskHandle_t pres_handle;
TaskHandle_t calib_handle;

EventGroupHandle_t SensorEventGroup;

const uint32_t temp_event_bit = (1 << 0);
const uint32_t pres_event_bit = (1 << 1);
const uint32_t all_bits = (temp_event_bit | pres_event_bit);

void TempratureTask(void *pv)
{
    while(1)
    {
        printf("Temprature Task\n");
        xEventGroupSetBits(SensorEventGroup,temp_event_bit);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}


void PressureTask(void *pv)
{
    while (1)
    {
        printf("Pressure Task\n");
        xEventGroupSetBits(SensorEventGroup,pres_event_bit);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void CalibrationTask(void *pv)
{
    uint32_t result;
    while(1)
    {
    printf("Calibration Task\n");
    result= xEventGroupWaitBits(SensorEventGroup, all_bits, pdTRUE, pdTRUE, pdMS_TO_TICKS(5000));
    printf("Result: %d\n",result);
    }
    vTaskDelete(NULL);
}


void app_main()
{
    SensorEventGroup = xEventGroupCreate();
    xTaskCreate(TempratureTask, "TempratureTask", 2048, NULL, 5, &temp_handle);
    xTaskCreate(PressureTask, "PressureTask", 2048, NULL, 5, &pres_handle);
    xTaskCreate(CalibrationTask, "CalibrationTask", 2048, NULL, 5, &calib_handle);

    while(1)
    {
        printf("Main task\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}