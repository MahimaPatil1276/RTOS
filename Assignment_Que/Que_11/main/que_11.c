/*11. What is the API for deleting a task? Write a program demonstrate this capability.*/


#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

TaskHandle_t xAlarmHandle;


void Alarmtask_1(void *pv)
{
    uint32_t count=0;
    while(1)
    {
        printf("Alarm TASK  RUNNING\n");
        vTaskDelay(pdMS_TO_TICKS(1000));    
        count++;
        if(count==10)
        {
            vTaskDelete(xAlarmHandle); 
        }
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