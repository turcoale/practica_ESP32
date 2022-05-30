#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "ssd1306.h"
#include "font8x8_basic.h"


#define tag "SSD1306"
SSD1306_t dev;


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
	char lineChar[20];

	displayConfig();



  ssd1306_display_text(&dev, 0, "abcdefghijklmnop", 17, false);
   vTaskDelay(4000 / portTICK_PERIOD_MS);

  ssd1306_clear_screen(&dev, false);

  for(int i = 0; i < 9; i++){

  	//lineChar[0] = 0x01;
	sprintf(&lineChar[1], "Linea: %01d", i);
    ssd1306_display_text(&dev, i, lineChar, 20, false);
  
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
  
  ssd1306_clear_screen(&dev, false);

  vTaskDelay(3000 / portTICK_PERIOD_MS);

	esp_restart();
}
