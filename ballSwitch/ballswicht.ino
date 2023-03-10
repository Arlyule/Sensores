int tiltPin = 4;      // número de pin para la señal del interruptor de inclinación  // número de pin del LED
int tiltState = 0;    // variable para leer el estado del interruptor de inclinación


void setup() {
  pinMode(tiltPin, INPUT);
  Serial.begin(9600);  // establecer el pin del interruptor de inclinación como entrada
}


void loop() {
  // obtener el estado del interruptor de inclinación
  tiltState = digitalRead(tiltPin);


  // comprobar si el interruptor de inclinación está inclinado
  if (tiltState == HIGH) {
    Serial.println("Esta inclinado");
  } else {
    Serial.println("No esta inclinado");  // apagar el LED
  }
  delay(2000);
}

