# wallynet

2 methods, for sending beaconed messages over ultra cheap 433MHz transmitters.

wallynet_setup(transmit_pin, led_pin, station_name); //Called in setup();

//Called to send a message
wallynet_send_beacon(String reading_name, String reading_value)


e.g.
```  
  int temp     = (int) DHT.temperature; //accuracy is only 2deg, so don't bother using floats
  int humidity = (int) DHT.humidity;  
  
  wallynet_send_beacon("temp", (String) temp);
  wallynet_send_beacon("humidity", (String) humidity);
```
