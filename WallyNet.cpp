// VirtualWire.cpp
//
// Wrapper for VirtualWire
//
// Author: Brenda Wallace <brenda@brenda.nz>
#include <stdlib.h>
#include <Arduino.h>

#include "WallyNet.h"
#include <VirtualWire.h>

const int wallynet_bps = 500;
int wallynet_tx_pin;
int wallynet_led_pin;
String wallynet_station_name;

void wallynet_setup(int tx_pin, int led_pin, String station_name) {
    wallynet_tx_pin = tx_pin;
    wallynet_led_pin = led_pin;
    wallynet_station_name = station_name;

    // Initialise the IO and ISR
    vw_set_tx_pin(wallynet_tx_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(wallynet_bps);       // Bits per sec
    
    pinMode(led_pin, OUTPUT);    
}

void wallynet_send_beacon(String reading_type, String reading_value) { 
  String message;

  int buf_len = message.length() +1;
  
  char buf[buf_len];
  message.toCharArray(buf, buf_len);
  
  digitalWrite(wallynet_led_pin, HIGH); // Flash a light to show transmitting

  vw_send((uint8_t *)buf, buf_len);
  vw_wait_tx(); // Wait until the whole message is gone

  digitalWrite(wallynet_led_pin, LOW);
  delay(2000);
}

