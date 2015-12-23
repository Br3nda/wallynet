# wallynet

2 methods, for sending beaconed messages over ultra cheap 433MHz transmitters.

`wallynet_setup(transmit_pin, led_pin, station_name); //Called in setup();`

```
//Called to send a message
wallynet_send_beacon(String reading_name, String reading_value)
```

e.g.
```  
  int humidity = (int) DHT.humidity;  
  wallynet_send_beacon("humidity", (String) humidity);
```
# Dependencies:
* [Virtual Wire](https://www.pjrc.com/teensy/td_libs_VirtualWire.html)

# Notes: 
* Messages are un-encrypted and trivially intercepted or jammed
* Nothing checks that the message was recieved
* Your own tranmitter may all transmit over the top of each other, and garble each other.
