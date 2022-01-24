/*12. What are the APIs provided by your RTOS for enabling and disabling the interrupts?
      Write a program to demonstrate this capability?*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>


TaskHandle_t xHandle_1;

void Alarmtask(void *pv)
{
    int count=0;
    while(1)
    {
       
        printf("ALARM TASK  RUNNING\n");
        taskENTER_CRITICAL(NULL);
        count++;
        printf("Csritical section\n");
        if(count==2)
        {
            taskEXIT_CRITICAL(NULL);
        }
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    BaseType_t result;

    result=xTaskCreate(Alarmtask,"Alarmtask",2048,NULL,5,&xHandle_1);

    if(result==pdPASS)
    {
        printf("Alarmtask created\n");
    }
}




