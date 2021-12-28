#include <stdio.h>
#include "multi_button.h"
#include "pcio/stdlib.h"

#ifdef GAMEKIT_RP2040_BUTTON_A
#define BOARD_BTN_A  GAMEKIT_RP2040_BUTTON_A
#else
#error "Board configure error."
#endif

#define BOARD_BTN_B GAMEKIT_RP2040_BUTTON_B

typedef struct button{
    const char * name;
    uint pin;
    uint trigger_level;
    uint (*gpio_get)(void);
    void (*handler)(void *btn);
    struct Button btn;
} button_t;

static uint gpio_get_btn_a(void)
{
    return gpio_get(BOARD_BTN_A);
}

static uint gpio_get_btn_b(void)
{
    return gpio_get(BOARD_BTN_B);
}

static void btn_a_handler(void *btn);
static void btn_b_handler(void *btn);

static button_t buttons[] = {
    {"BTN_A", BOARD_BTN_A, 0, gpio_get_btn_a, btn_a_handler},
    {"BTN_B", BOARD_BTN_B, 0, gpio_get_btn_b, btn_b_handler},
};

void bsp_sw_init(void)
{
    int n = sizeof(buttons) / sizeof(buttons[0]);
    button_t *cur = buttons;
    button_t *end = cur + n;
    
    while (cur < end) {
        button_init(&cur->btn, cur->gpio_get, cur->trigger_level);
        button_attach(&cur->btn, SINGLE_CLICK, cur->handler);
        button_attach(&cur->btn, DOUBLE_CLICK, cur->handler);
        button_start(&cur->btn);

        cur++;
    }

    printf("Board button init success.\n");
}


static void btn_a_handler(void *btn)
{
    switch (get_button_event(btn)) {
    case SINGLE_CLICK:  
        printf("SW_A single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("SW_A double click.\n");
        break;
    default:
        printf("SW_A error.\n");
        break;
    }
}

static void btn_b_handler(void *btn)
{
    switch (get_button_event(btn)) {
    case SINGLE_CLICK:  
        printf("SW_B single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("SW_B double click.\n");
        break;
    default:
        printf("SW_B error.\n");
        break;
    }
}