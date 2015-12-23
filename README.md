# wallynet

2 methods, for sending beaconed messages over ultra cheap 433MHz transmitters.

In the arduino ide, in setup(), tell the library:

 * which pin the 433MHz transmitter was wired to, 
 * which led to light to indicate transmission (Uno have a handy led on pin 11)
 * what your station is called. 

`wallynet_setup(transmit_pin, led_pin, station_name);`

Example 

`wallynet_setup(1, 11, "laundry");`


Use `wallynet_send_beacon`  to transmit. 


`wallynet_send_beacon(String reading_name, String reading_value)`

e.g.

```  
  float humidity = DHT.humidity;  
  wallynet_send_beacon("humidity", (String) humidity);
```

# Dependencies:

* [Virtual Wire](https://www.pjrc.com/teensy/td_libs_VirtualWire.html)

# Notes:
 
* Messages are un-encrypted and trivially intercepted or jammed
* Nothing checks that the message was recieved
* Your own tranmitter may all transmit over the top of each other, and garble each other.
