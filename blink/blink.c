#include "pico/stdlib.h"

enum GPIO { ON, OFF };
#define LED_PIN  25

int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    for (int i = 0; i < 10; ++i) {
        gpio_put(LED_PIN, ON);
        sleep_ms(2000);
        gpio_put(LED_PIN, OFF);
        sleep_ms(2000);
    }
    gpio_put(LED_PIN, OFF);

    return 0;
}