#include "ForBlynkCredentials.h"
#define BLYNK_PRINT Serial



#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#ifdef ESP8266
#include <BlynkSimpleEsp8266.h>
#elif defined(ESP32)
#include <BlynkSimpleEsp32.h>
#else
#error "Board not found"
#endif

credentials Credentials;



//Variables
char auth_token[33];
bool connected_to_internet = 0;
const int Erasing_button = 15;



//Provide credentials for your ESP server
char* esp_ssid = "ESP8266";
char* esp_pass = "";


// .     Add your variables 
//
// .             HERE
//DHT
#define DHTPIN 0          // D3
// Uncomment the dht type you're working on!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);

//DS 18B20
#define ONE_WIRE_BUS D2   //D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

BlynkTimer timer;

  WidgetLED led1(V7);
  WidgetLED led2(V8);
  WidgetLED led3(V9);
  WidgetLCD lcd1(V13);
  WidgetLED led4(V10);
  WidgetLED led5(V11);
  WidgetLED led6(V12);
  WidgetLCD lcd2(V14);

  
//====================================================
//====================================================
//DHT11 Function
//====================================================
//====================================================
void sendSensor()
{
  if (digitalRead(Erasing_button) == HIGH)
  {

    Credentials.Erase_eeprom();
    digitalWrite(Erasing_button, LOW);
    ESP.restart();
  }
  
  float temp;
  DS18B20.requestTemperatures();
  delay(1000);
  temp = DS18B20.getTempCByIndex(0);
  String voltage = String(system_get_free_heap_size());
  
  delay(1000);//DHT11 recommends waiting 2 seconds ==> 2000 = 1000(DS18B20)+1000(this)  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
  if (t>0 && t<15)        
  { 
    Serial.print("COLD   "); 
    led1.off(); led2.off(); led3.on();
    lcd1.print(0, 0, "COLD"); 
  }
  else if (t>14 && t<30)  
  { 
    Serial.print("WARM   "); 
    led1.off(); led2.off(); led3.on();
    lcd1.print(0, 0, "WARM");  
  }
  
  else if (t>30 && t<45)  
  { 
    Serial.print("HOT   "); 
    led1.on(); led2.on(); led3.off();
    lcd1.print(0, 0, "HOT");  
  }
  
  else                    
  { 
    Serial.print("VERY HOT  ");
    led1.on(); led2.off(); led3.off();
    lcd1.print(0, 0, "VERY HOT  ");  
  }

  if (h>0 && h<30)        
  { 
    Serial.println("LOW HUMIDITY"); 
    led4.on(); led5.off(); led6.off();
    lcd1.print(0, 1, "LOW HUMIDITY");    
  }
  
  else if (h>30 && h<50)  
  { 
    Serial.println("Normal HUMIDITY"); 
    led4.off(); led5.on(); led6.off();
    lcd1.print(0, 1, "Normal HUMIDITY");    
  }
  else                    
  {
    Serial.println("HIGH HUMIDITY");
    led4.off(); led5.off(); led6.on();
    lcd1.print(0, 1, "HIGH HUMIDITY");     
  }
//  String tempVar = "Temperature OutSide: " + temp + "C";
  Serial.print("DS18B20 Temperature: ");
  Serial.print(temp);
  Serial.println("C");
  Serial.print("Room Temperature(DHT): ");
  Serial.print(t);
  Serial.println("C");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  lcd2.print(0, 0, "Outdoor Temp: "); 
  lcd2.print(0, 1, temp);
  lcd2.print(5, 1, "C");
  delay(800);
}
//====================================================
//====================================================



void setup()

{

  Serial.begin(115200);
  pinMode(Erasing_button, INPUT);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.println(t);
    delay(1000);
  }

  String auth_string = Credentials.EEPROM_Config();
  auth_string.toCharArray(auth_token, 33);

  if (Credentials.credentials_get())
  {

    Blynk.config(auth_token);
    connected_to_internet = 1;

  }
  else
  {
    Credentials.setupAP(esp_ssid, esp_pass);
    connected_to_internet = 0;
  }


  if (connected_to_internet)
  {

 
  dht.begin();
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);

  }

}



void loop()
{
  Credentials.server_loops();

  if (connected_to_internet)
  {
      Blynk.run();
      timer.run();
  }
}
