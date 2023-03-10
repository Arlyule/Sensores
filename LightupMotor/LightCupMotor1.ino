#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>


Servo servo;


const int lm35Pin = 14; // pin analógico del sensor LM35


void setup() {
  servo.attach(5);
  Serial.begin(9600); // Inicializar el monitor serie
  pinMode(lm35Pin, INPUT);
}


void loop() {
  Serial.println(digitalRead(lm35Pin));
  if(digitalRead(lm35Pin)) {
    servo.write(360);
  } else {
    servo.write(0);
  }
}