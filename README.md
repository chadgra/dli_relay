This project uses a Digital Loggers brand IoT Relay (https://www.amazon.com/dp/B00WV7GMA2) and a nRF PCA10040 dev-kit.

The relay plugs into pin 18 (and ground) to achieve functionality.

Two commands are added to the cli:
- dli_status: Show the status of the LEDs (and ideally the plugs of the relay)
- dli_switch: Switch the LEDs and the "Normally ON" and "Normally OFF" plugs 
