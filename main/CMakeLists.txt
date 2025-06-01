file(GLOB_RECURSE SRC_FILES "src/*.c"
                            "src/**/*.c")

idf_component_register(
    SRCS ${SRC_FILES}
    INCLUDE_DIRS "include"
    REQUIRES
        esp_lcd
        driver   
        esp_timer
        spi_flash
)