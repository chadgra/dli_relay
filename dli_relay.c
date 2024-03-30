#include "nrf_delay.h"
#include "dli_relay.h"

static void dli_relay_outlet_enable(uint32_t idx)
{
    // This actually just enables the LEDs to indicate that they are on.
    // This does not actually enable the outlet. But they should match
    bsp_board_led_on(idx);
}

static void dli_relay_outlet_invert(uint32_t idx)
{
    // Change the color of the LED
    bsp_board_led_invert(idx);
}

static int dli_relay_state_get(uint32_t idx)
{
    return (int)bsp_board_led_state_get(idx);
}

void dli_relay_init(void)
{
    // Configure board for leds and buttons
    bsp_board_init(BSP_INIT_LEDS | BSP_INIT_BUTTONS);

    // Enable the outlets (leds) of those that should be initially on.
    dli_relay_outlet_enable(DLI_RELAY_OUTLET_NORMALLY_ON);
    dli_relay_outlet_enable(DLI_RELAY_OUTLET_ALWAYS_ON);
}

void dli_relay_button_check(void)
{
    bool button_pressed = false;

    for (uint32_t i = 0; i < BUTTONS_NUMBER; i++)
    {
        button_pressed |= bsp_board_button_state_get(i);
    }

    if (button_pressed)
    {
        dli_relay_outlets_switch(NULL, 0, NULL);

        // Delay for half a second for debounce purposes
        nrf_delay_ms(500);
    }
}

void dli_relay_outlets_switch(nrf_cli_t const * p_cli, size_t argc, char **argv)
{
    dli_relay_outlet_invert(DLI_RELAY_OUTLET_NORMALLY_OFF_T);
    dli_relay_outlet_invert(DLI_RELAY_OUTLET_NORMALLY_ON);
    dli_relay_outlet_invert(DLI_RELAY_OUTLET_NORMALLY_OFF_B);

    dli_relay_outlets_status(p_cli, argc, argv);
}

void dli_relay_outlets_status(nrf_cli_t const * p_cli, size_t argc, char **argv)
{
    if (p_cli != NULL)
    {
        nrf_cli_error(p_cli, "%u %u", dli_relay_state_get(DLI_RELAY_OUTLET_NORMALLY_OFF_T), dli_relay_state_get(DLI_RELAY_OUTLET_NORMALLY_ON));
        nrf_cli_error(p_cli, "%u %u", dli_relay_state_get(DLI_RELAY_OUTLET_NORMALLY_OFF_B), dli_relay_state_get(DLI_RELAY_OUTLET_ALWAYS_ON));
    }
}
