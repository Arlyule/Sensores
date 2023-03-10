#include <Arduino.h>


const int sensorPin = 4;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}


void loop() {
  int sensorValue = digitalRead(sensorPin);
  
  if (sensorValue == HIGH) {
    Serial.println("Bloque de luz detectado");
  } else {
    Serial.println("Bloque de luz no detectado");
  }


  delay(1000);
}

