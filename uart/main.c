#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    while (true) {
        printf("Hello World!\n");
        sleep_ms(2000);
    }

    return 0;
} 