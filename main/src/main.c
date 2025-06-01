#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/spi_master.h>
#include "App/Components/TFTManager.h"
#include "App/Components/LEDManager.h"

void app_main()
{
    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}