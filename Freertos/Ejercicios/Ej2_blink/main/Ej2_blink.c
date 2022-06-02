//*******************
//Ejemplo Ej2_blink
//Placa de Desarrollo 
//Amid Gabriel Ale
//Parpadeo
//******************* 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define BLINK_GPIO 25


static uint8_t s_led_state = 0;


// Prototipo de funcion de la tarea
void blinkTask( void* taskParmPtr );



void app_main(void)
{

  // Crear tarea en freeRTOS displayTask
   xTaskCreate(
      blinkTask,                     // Funcion de la tarea a ejecutar
      (const char *)"blinkTask",     // Nombre de la tarea como String amigable para el usuario
      configMINIMAL_STACK_SIZE*1, // Cantidad de stack de la tarea
      0,                          // Parametros de tarea
      tskIDLE_PRIORITY+1,         // Prioridad de la tarea
      0                           // Puntero a la tarea creada en el sistema
   );


 // ---------- REPETIR POR SIEMPRE --------------------------
   while( true ) {

   }
 }

// Implementacion de funcion de la tarea
void blinkTask( void* taskParmPtr )
{
	const char *pcTaskName = "Task 1 running";
   
   while(true) {

    vTaskDelay(3000 / portTICK_PERIOD_MS);
	}

// La tarea NUNCA debe pasar de este punto, si lo hiciera debe ser eliminada
vTaskDelete(NULL);
}

/*==================[fin del archivo]========================================*/
