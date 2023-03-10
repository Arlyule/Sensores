#include <UTFT.h>


// Configuración de pines de la pantalla
UTFT myGLCD(ST7735S_4L_80160, 11, 13, 10, 8, 9);
const int SENSOR_PIN = A0;


extern uint8_t SmallFont[3];
extern uint8_t BigFont[];


// Variables para el tamaño de la pantalla
int screenWidth = 80;
int screenHeight = 160;


void setup() {
  // Inicialización de la pantalla
  myGLCD.InitLCD();


  // Configuración de la fuente de texto
  myGLCD.setFont(SmallFont);


  // Limpia la pantalla
  myGLCD.clrScr();


  pinMode(SENSOR_PIN, INPUT);
}


void loop() {
  // Valores a mostrar
  int valor1 = analogRead(SENSOR_PIN);


  // Convierte los valores a cadenas de texto
  char strValor1[10];
  dtostrf(valor1, 5, 0, strValor1);  // convierte un int a string


  // Pinta los valores en la pantalla
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("salvador", 10, 20);
  myGLCD.print("Valor: ", 10, 10);
  myGLCD.print(strValor1, 70, 10);


  // Espera un momento para evitar refrescos excesivos de la pantalla
  delay(1000);
}
