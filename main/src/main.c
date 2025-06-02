#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_lcd_st7735.h"

#define LCD_MOSI 23
#define LCD_SCLK 18
#define LCD_CS 5
#define LCD_DC 2
#define LCD_RST 4
#define LCD_WIDTH 128
#define LCD_HEIGHT 160

esp_lcd_panel_handle_t panel_handle;

void app_main(void)
{
    spi_bus_config_t buscfg = {
        .mosi_io_num = LCD_MOSI,
        .sclk_io_num = LCD_SCLK,
        .miso_io_num = -1,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = LCD_WIDTH * LCD_HEIGHT * 2 + 8,
    };
    spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);

    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_spi_config_t io_config = {
        .dc_gpio_num = LCD_DC,
        .cs_gpio_num = LCD_CS,
        .pclk_hz = 20 * 1000 * 1000,
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
        .spi_mode = 0,
        .trans_queue_depth = 10,
        .on_color_trans_done = NULL,
        .user_ctx = NULL,
    };
    esp_lcd_new_panel_io_spi(SPI2_HOST, &io_config, &io_handle);

    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = LCD_RST,
        .color_space = ESP_LCD_COLOR_SPACE_RGB,
        .bits_per_pixel = 16,
    };

    esp_lcd_new_panel_st7735(io_handle, &panel_config, &panel_handle);
    esp_lcd_panel_reset(panel_handle);
    esp_lcd_panel_init(panel_handle);
    esp_lcd_panel_disp_on_off(panel_handle, true);

    // Fill screen red
    uint16_t red = 0xF800;
    esp_lcd_panel_draw_bitmap(panel_handle, 0, 0, LCD_WIDTH, LCD_HEIGHT, &red);

    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        esp_lcd_panel_disp_on_off(panel_handle, false);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        esp_lcd_panel_disp_on_off(panel_handle, true);
    }
}
