/*2. What is the mechanism used to make a task periodic for the RTOS you are using? Write a
program to make a task periodic with periodicity of 500ms.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

TaskHandle_t xAlarmHandle;


void Alarmtask_1(void *pv)
{
    while(1)
    {
        printf("Alarm TASK  RUNNING\n");
        vTaskDelay(pdMS_TO_TICKS(500));    
    }
}

void app_main()
{
    BaseType_t result;
    
    result=xTaskCreate(Alarmtask_1,"Alarmtask_1",2048,NULL,5,&xAlarmHandle);

    if(result==pdPASS)
    {
        printf("Alarmtask created\n");
    }
   
}