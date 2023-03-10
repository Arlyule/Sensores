#include <TM1651.h>

#define CLK 5
#define DIO 14

const int touchPin = 4; // Conecta el pin S al pin digital 2 de Arduino
TM1651 batteryDisplay(CLK,DIO);

void setup() {
  pinMode(touchPin, INPUT); // Establece el pin S como entrada
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  batteryDisplay.init();
  batteryDisplay.set(1);
  batteryDisplay.frame(FRAME_ON);
}

void loop() {
  int touchValue = digitalRead(touchPin); // Lee el valor del pin S
  Serial.println(touchValue); // Imprime el valor en el monitor serie
  delay(1000); // Espera 100 milisegundos antes de volver a leer el sensor

  if(touchValue == 1){
    charging();
  }else{
    batteryDisplay.displayLevel(0);
  }
}

void charging() {
  for (uint8_t level = 0; level < 6; level++) {
    batteryDisplay.displayLevel(level);
    delay(500);
  }
}
