#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#include "ssd1306.h"
#include "font8x8_basic.h"


#define tag "SSD1306"
#define BLINK_GPIO 25


SSD1306_t dev;
static uint8_t s_led_state = 0;
int count = 0;
char lineChar[13];



// Prototipo de funcion de la tarea
void fTask( void* taskParmPtr );
void sTask( void* taskParmPtr );

void displayConfig(void)
{

//Configura I2C
	ESP_LOGI(tag, "INTERFACE is i2c");
	ESP_LOGI(tag, "CONFIG_SDA_GPIO=%d",CONFIG_SDA_GPIO);
	ESP_LOGI(tag, "CONFIG_SCL_GPIO=%d",CONFIG_SCL_GPIO);
	ESP_LOGI(tag, "CONFIG_RESET_GPIO=%d",CONFIG_RESET_GPIO);
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);

	ESP_LOGI(tag, "Panel is 128x64");
	ssd1306_init(&dev, 128, 64);

	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff); 
}



  


void app_main(void)
{

  displayConfig();
 
  // Crear tarea en freeRTOS displayTask
   xTaskCreate(
      fTask,                     // Funcion de la tarea a ejecutar
      (const char *)"fTask",     // Nombre de la tarea como String amigable para el usuario
      configMINIMAL_STACK_SIZE*1, // Cantidad de stack de la tarea
      0,                          // Parametros de tarea
      tskIDLE_PRIORITY+1,         // Prioridad de la tarea
      0                           // Puntero a la tarea creada en el sistema
   );

   // Crear tarea en freeRTOS displayTask
   xTaskCreate(
      sTask,                     // Funcion de la tarea a ejecutar
      (const char *)"sTask",     // Nombre de la tarea como String amigable para el usuario
      configMINIMAL_STACK_SIZE*1, // Cantidad de stack de la tarea
      0,                          // Parametros de tarea
      tskIDLE_PRIORITY+1,         // Prioridad de la tarea
      0                           // Puntero a la tarea creada en el sistema
   );




//while (true)	{	}

 // ---------- REPETIR POR SIEMPRE --------------------------
   while( true ) {
   	//ssd1306_clear_screen(&dev, false);
      // Si cae en este while 1 significa que no pudo iniciar el scheduler
//   	  ssd1306_display_text(&dev, 0, "      ***       ", 16, true);
   	  //vTaskDelay(3000 / portTICK_PERIOD_MS);
   }

  
//  sprintf(&lineChar[1], "   %02d/%02d/%02d", dia, mes, ano);
//  ssd1306_display_text(&dev, 3, "   Hola Mundo!  ", 16, false);
//  ssd1306_display_text(&dev, 5, lineChar, 13, false);
  
//  vTaskDelay(2000 / portTICK_PERIOD_MS);
  
//  ssd1306_clear_screen(&dev, false);

//  vTaskDelay(3000 / portTICK_PERIOD_MS);

//	esp_restart();

}


// Implementacion de funcion de la tarea
void fTask( void* taskParmPtr )
{
	const char *pcTaskName = "Task 1 running";
   
   while(true) {

   	ssd1306_clear_screen(&dev, false);

    ssd1306_display_text(&dev, 2, "****************", 16, false);
 
   	ssd1306_display_text(&dev, 4, pcTaskName, 14, false);

 	ssd1306_display_text(&dev, 6, "****************", 16, false);
  //  sprintf(&lineChar[1], "Task: %04d", count);
    //ssd1306_clear_screen(&dev, false);
    //ssd1306_display_text(&dev, 1," TASK 1:*", 10, true);
    //ssd1306_display_text(&dev, 5," TASK 2: ", 10, true);
    vTaskDelay(3000 / portTICK_PERIOD_MS);
	}

// La tarea NUNCA debe pasar de este punto, si lo hiciera debe ser eliminada
vTaskDelete(NULL);
}

void sTask( void* taskParmPtr )
{
	const char *pcTaskName = "Task 2 running";

   while(true) {

   	ssd1306_clear_screen(&dev, false);
 
   	ssd1306_display_text(&dev, 2, "****************", 16, false);
 
   	ssd1306_display_text(&dev, 4, pcTaskName, 14, false);
 
  	ssd1306_display_text(&dev, 6, "****************", 16, false);
 
  //  sprintf(&lineChar[1], "Task: %04d", count);
    //ssd1306_clear_screen(&dev, false);
    //ssd1306_display_text(&dev, 1," TASK 1:*", 10, true);
    //ssd1306_display_text(&dev, 5," TASK 2: ", 10, true);
    vTaskDelay(3000 / portTICK_PERIOD_MS);
	}

// La tarea NUNCA debe pasar de este punto, si lo hiciera debe ser eliminada
vTaskDelete(NULL);
}

/*==================[fin del archivo]========================================*/
