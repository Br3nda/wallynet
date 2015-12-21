// WallyNet.h

#ifndef WallyNet_h
#define WallyNet_h

#include <stdlib.h>
#include <Arduino.h>

void wallynet_send_message(String reading_name, String reading_value);
void wallynet_setup(int tx_pin, int led_pin, String station_name);
#endif
