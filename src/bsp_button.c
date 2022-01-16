#include <stdio.h>
#include "multi_button.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

typedef struct button{
    const char * name;
    uint pin;
    uint trigger_level;
    uint8_t (*gpio_get)(void);
    void (*handler)(void *btn);
    struct Button btn;
} button_t;

static uint8_t gpio_get_btn_a(void)
{
    return (uint8_t)gpio_get(GAMEKIT_RP2040_BUTTON_A);
}

static uint8_t gpio_get_btn_b(void)
{
    return (uint8_t)gpio_get(GAMEKIT_RP2040_BUTTON_B);
}

static uint8_t button_adc_get(uint input, uint base)
{
    adc_select_input(input);
    uint adc = adc_read();
    return adc < base ? 0 : 1;
}

#define ADC_0_BASE  0x100
#define ADC_1_BASE  0xF00
static uint8_t gpio_get_joy_up(void)
{
    return button_adc_get(2, ADC_0_BASE);
}

static uint8_t gpio_get_joy_down(void)
{
    return button_adc_get(2, ADC_1_BASE);
}

static uint8_t gpio_get_joy_left(void)
{
    return button_adc_get(3, ADC_0_BASE);
}

static uint8_t gpio_get_joy_right(void)
{
    return button_adc_get(3, ADC_1_BASE);
}

static void btn_a_handler(void *btn);
static void btn_b_handler(void *btn);
static void joy_up_handler(void *btn);
static void joy_down_handler(void *btn);
static void joy_left_handler(void *btn);
static void joy_right_handler(void *btn);

static button_t buttons[] = {
    {"BTN_A",       GAMEKIT_RP2040_BUTTON_A,    0, gpio_get_btn_a,      btn_a_handler},
    {"BTN_B",       GAMEKIT_RP2040_BUTTON_B,    0, gpio_get_btn_b,      btn_b_handler},
    {"JOY_UP",      GAMEKIT_RP2040_JOY_X,       0, gpio_get_joy_up,     joy_up_handler},
    {"JOY_DOWN",    GAMEKIT_RP2040_JOY_X,       1, gpio_get_joy_down,   joy_down_handler},
    {"JOY_LEFT",    GAMEKIT_RP2040_JOY_Y,       0, gpio_get_joy_left,   joy_left_handler},
    {"JOY_RIGHT",   GAMEKIT_RP2040_JOY_Y,       1, gpio_get_joy_right,  joy_right_handler},
};

void bsp_button_init(void)
{
    int n = sizeof(buttons) / sizeof(buttons[0]);
    button_t *cur = buttons;
    button_t *end = cur + n;
    
    adc_init();

    while (cur < end) {
        /* Init GPIO */
        if (cur->pin == GAMEKIT_RP2040_JOY_X && cur->pin == GAMEKIT_RP2040_JOY_X) {
            adc_gpio_init(cur->pin);
        } else {
            gpio_init(cur->pin);    /* Default direction is input. */
            gpio_pull_up(cur->pin);
        }

        /* Init MulltiButton */
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
        printf("BTN_A single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("BTN_A double click.\n");
        break;
    default:
        printf("BTN_A error.\n");
        break;
    }
}

static void btn_b_handler(void *btn)
{
    switch (get_button_event(btn)) {
    case SINGLE_CLICK:  
        printf("BTN_B single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("BTN_B double click.\n");
        break;
    default:
        printf("BTN_B error.\n");
        break;
    }
}

static void joy_up_handler(void *btn)
{
    switch (get_button_event(btn)) {
    case SINGLE_CLICK:  
        printf("JOY_UP single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("JOY_UP double click.\n");
        break;
    default:
        printf("JOY_UP error.\n");
        break;
    }
}

static void joy_down_handler(void *btn)
{
    switch (get_button_event(btn)) {
    case SINGLE_CLICK:  
        printf("JOY_DOWN single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("JOY_DOWN double click.\n");
        break;
    default:
        printf("JOY_DOWN error.\n");
        break;
    }
}

static void joy_left_handler(void *btn)
{
    switch (get_button_event(btn)) {
    case SINGLE_CLICK:  
        printf("JOY_LEFT single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("JOY_LEFT double click.\n");
        break;
    default:
        printf("JOY_LEFT error.\n");
        break;
    }
}

static void joy_right_handler(void *btn)
{
    switch (get_button_event(btn)) {
    case SINGLE_CLICK:  
        printf("JOY_RIGHT single click.\n");
        break;
    case DOUBLE_CLICK:
        printf("JOY_RIGHT double click.\n");
        break;
    default:
        printf("JOY_RIGHT error.\n");
        break;
    }
}