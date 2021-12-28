#include "pico/stdlib.h"
#include "pico/st7789.h"


void execute_loop(void)
{
    while (1) {
        button_ticks();
    }
}

int main(void)
{
    printf("Hello World\n");
    return 0;
}
