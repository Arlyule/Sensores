int tiltPin = 4;      // n�mero de pin para la se�al del interruptor de inclinaci�n  // n�mero de pin del LED
int tiltState = 0;    // variable para leer el estado del interruptor de inclinaci�n


void setup() {
  pinMode(tiltPin, INPUT);
  Serial.begin(9600);  // establecer el pin del interruptor de inclinaci�n como entrada
}


void loop() {
  // obtener el estado del interruptor de inclinaci�n
  tiltState = digitalRead(tiltPin);


  // comprobar si el interruptor de inclinaci�n est� inclinado
  if (tiltState == HIGH) {
    Serial.println("Esta inclinado");
  } else {
    Serial.println("No esta inclinado");  // apagar el LED
  }
  delay(2000);
}

