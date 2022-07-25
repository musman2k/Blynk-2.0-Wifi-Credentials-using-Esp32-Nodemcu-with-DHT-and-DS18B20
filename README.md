# Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20

##Manual
***
1.	Installing libraries:

1.1.	Download latest version of libraries using provided links

*	https://www.arduino.cc/reference/en/libraries/websockets/ 
*	https://www.arduino.cc/reference/en/libraries/onewire/ 
*	https://www.arduino.cc/reference/en/libraries/dallastemperature/ 
*	https://www.arduino.cc/reference/en/libraries/dht-sensor-library/ 

1.2.	Add all downloaded libraries in Arduino IDE
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/1.png?raw=true)
 ***
 
2.	Download the ForBlynkCredentials.zip file and extract at afterwards.
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/2.jpg?raw=true) 
***
 
 
3.	On Arduino IDE File menu, navigate ForBlynkCredentials.ino file.
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/3.jpg?raw=true)
***
 
4.	Finally, compile the code.


5.	Once you are done with all steps above, please proceed with connection. Thank You and All The Best!.


###Extra notes:
***
•	You can add any other library here
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/4.jpg?raw=true)
 ***
•	**D3** and **D2** are pins on ESP8266 they should be connected with *data pins* of **DHT22** and **DS18B20** sensors respectively. You can also initialize variable for other sensors here. Make sure you aren’t using same data pin for multiple sensors.
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/5.jpg?raw=true) 
 ***
•	Blynk Widgets and there assigned virtual pins. Make sure you aren’t using same virtual pin to send data to multiple Widgets.
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/6.jpg?raw=true)
 ***
•	Function for DHT and DS18B20:
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/7.jpg?raw=true)
 ***
•	Code for retrieving data from DS18B20:
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/8.jpg?raw=true)
 ***
•	Code for retrieving data from DHT:
***
![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/9.jpg?raw=true)
 ***
•	Following command is to erase all the data stored in eeprom, in case you want to change wifi connections. In order to be use it you need to install a button and connect with the D8 data pin on ESP8266. However, if you only have one wifi connection just leave it as it is.
 ![alt text](https://github.com/musman2k/Blynk-Wifi-Credentials-using-Esp32-Nodemcu-with-DHT-and-DS18B20/blob/main/Screenshots/10.jpg?raw=true)
 ***
•	***Good Luck!***

