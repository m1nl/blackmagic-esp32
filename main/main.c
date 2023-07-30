#include <stdint.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <rom/ets_sys.h>

#include "nvs.h"
#include "gdb_main.h"
#include "cli-uart.h"
#include "network.h"
#include "network-http.h"
#include "network-uart.h"
#include "network-gdb.h"
#include "led.h"
#include <gdb-glue.h>
#include <platform.h>

static const char* TAG = "main";

void gdb_application_thread(void* pvParameters) {
    ESP_LOGI("gdb", "start");
    while(1) {
        gdb_main();
    }
    ESP_LOGI("gdb", "end");
}

#include <platform.h>
#include <driver/gpio.h>

void app_main(void) {
    ESP_LOGI(TAG, "start");

    platform_init();
    gdb_glue_init();

    led_init();
    led_set_blue(255);

    nvs_init();
    network_init();

    network_http_server_init();
    network_gdb_server_init();

    cli_uart_init();

    xTaskCreatePinnedToCore(&gdb_application_thread, "gdb_thread", 4096, NULL, 5, NULL, 1);
    ESP_LOGI(TAG, "end");
}
