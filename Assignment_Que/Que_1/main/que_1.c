/*1. Find what is the task priority numbering for the RTOS you are using. eg. Higher the
number higher the priority or vice-versa. Find the range of priority that can be assigned to
a task for your RTOS.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>


TaskHandle_t xSensorHandle;
TaskHandle_t xAlarmHandle;


void sensortask_1(void *pvparameters)
{
    while(1)
    {
        printf("SENSOR TASK PRIORITY %d\n",uxTaskPriorityGet(NULL));
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void Alarmtask_1(void *pvparameters)
{
   
    while(1)
    {
        printf("ALARM TASK PRIORITY %d\n",uxTaskPriorityGet(NULL));
        
        vTaskDelay(2000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    BaseType_t result;
    
    result=xTaskCreate(sensortask_1,"sensortask_1",2048,NULL,5,&xSensorHandle);

    if(result==pdPASS)
    {
        printf("sensortask created\n");
    }
    result=xTaskCreate(Alarmtask_1,"Alarmtask_1",2048,NULL,10,&xAlarmHandle);

    if(result==pdPASS)
    {
        printf("Alarmtask created\n");
    }
}