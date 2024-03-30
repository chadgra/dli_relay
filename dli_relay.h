#ifndef DLI_RELAY_H
#define DLI_RELAY_H

#include "boards.h"
#include "nrf_cli.h"

#define DLI_RELAY_OUTLET_NORMALLY_OFF_T 0
#define DLI_RELAY_OUTLET_NORMALLY_ON    1
#define DLI_RELAY_OUTLET_NORMALLY_OFF_B 2
#define DLI_RELAY_OUTLET_ALWAYS_ON      3

void dli_relay_init(void);
void dli_relay_button_check(void);
void dli_relay_outlets_switch(nrf_cli_t const * p_cli, size_t argc, char **argv);
void dli_relay_outlets_status(nrf_cli_t const * p_cli, size_t argc, char **argv);

#endif // DLI_RELAY_H