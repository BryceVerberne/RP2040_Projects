#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define LED_PIN 25

int main() {
    stdio_init_all();
    char buffer[1024];

    // Initialize the pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        scanf("%1024s", buffer);
        if (strcmp(buffer, "ON") == 0) { // We use 0 since this indicates they're the same
            printf("Received Input: ON\n");
            printf("The LED is now ON\n\n");
            gpio_put(LED_PIN, 1);
        }
        else if (strcmp(buffer, "OFF") == 0) {
            gpio_put(LED_PIN, 0);
            printf("Received Input: OFF\n");
            printf("The LED is now OFF\n\n");
        }
        else if (strcmp(buffer, "REBOOT") == 0) {
            printf("REBOOTING...\n");
            printf("Goodbye :)\n");
            reset_usb_boot(0,0);
        }
        else {
            printf("ERROR: Foreign input value\n\n");
            gpio_put(LED_PIN, 0);
            for (int i = 0; i < 5; ++i) {
                sleep_ms(200);
                gpio_put(LED_PIN, 1);
                sleep_ms(200);
                gpio_put(LED_PIN, 0);
            }
        }
    }

    return 0;
} 