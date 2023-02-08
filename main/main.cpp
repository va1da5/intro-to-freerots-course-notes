/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <iostream>
#include <string>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_flash.h"

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

static const char *TAG = "main";

typedef struct TaskParams
{
    const char *message;
    const int delay;
} TaskParams_t;

void printToSerial(void *args)
{

    auto params = *((TaskParams *)args);

    while (1)
    {
        ESP_LOGI(TAG, "%s", params.message);
        vTaskDelay(params.delay / portTICK_PERIOD_MS);
    }
}

extern "C" void app_main(void)
{

    TaskHandle_t xHandle = nullptr;

    TaskParams task_1_params = {"Hello, ESP32", 400};
    TaskParams task_2_params = {"Hello, FreeRTOS", 1100};

    xTaskCreatePinnedToCore(
        &printToSerial,         // function to be called
        "ESP32",                // name of the task
        2048,                   // stack size (bytes in ESP32, words in FreeRTOS)
        (void *)&task_1_params, // Parameter to pass to function
        1,                      // Task priority
        NULL,                   // Task handle
        app_cpu);               // selects core 1 to run the task on (ESP32 only)

    // https://www.freertos.org/a00125.html
    xTaskCreate(
        &printToSerial,         // Function that implements the task.
        "FreeRTOS",             // Text name for the task.
        2048,                   // Stack size in words, not bytes.
        (void *)&task_2_params, // Parameter passed into the task.
        tskIDLE_PRIORITY,       // Priority at which the task is created.
        &xHandle);              // Used to pass out the created task's handle.

    // https://www.freertos.org/a00132.html
    // vTaskStartScheduler();   // The schedule gets automatically initiated by ESP32

    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
