/*5. Swap the priority and observe the changes in the output. What is your conclusion on the
sequence of printing the messages.*/

/*4. Create two task with priority 10 and 20. Each task prints its own custom message.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTaskLog;

void Task_1(void *task)
{
    while(1)
    {
        printf("Task-1=I am priority 20\n");
    }
    vTaskDelete(NULL);
}

void Task_2(void *task)
{
    while(1)
    {
        printf("Task-2=I am priority 10\n");
    }
    vTaskDelete(NULL);
}
void app_main()
{
    BaseType_t result;

    result = xTaskCreate(Task_1,"Task1=10", 2048, NULL, 20, NULL);
    
    result = xTaskCreate(Task_2,"Task2=5", 2048, NULL, 10, NULL);
    
}