#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_10

void app_main(void)
{
    uint8_t led_state = 0;

    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        led_state = !led_state;

        gpio_set_level(LED_GPIO, led_state);
        printf("Led State %d\n", led_state);
        vTaskDelay(pdMS_TO_TICKS(1000));

    }
}