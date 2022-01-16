/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

#include "multi_button.h"

extern void bsp_button_init(void);

int main() {
    stdio_init_all();
    bsp_button_init();
    while (true) {
        // printf("Hello, world!\n");
        // sleep_ms(1000);
        button_ticks();
        sleep_ms(5);
    }
    return 0;
}
