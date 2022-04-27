//include a library to handle DHT sensor requirements
#include "Adafruit_DHT.h"

// DHT parameters
#define DHTPIN 7 // set to pin 7
#define DHTTYPE DHT11

// varible to hold the temperature
int temperature;
// set up a dht varaible to handle the sensor data 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
}
 // loop through to conitnue publishing the temperature
void loop() {
  // get the temperatire data from the sensor
  temperature = dht.getTempCelcius();
  // publish the temperature to thingsspeak
  Particle.publish("temp", String(temperature), PRIVATE);
  // delay to only get the temp every 10 seconds 
  delay(1000);
}
