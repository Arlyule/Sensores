int pinA = 18;  // Conectado a CLK en KY-040
int pinB = 19;  // Conectado a DT en KY-040
int encoderPosCount = 0;
int pinALast;
int aVal;
boolean bCW;


void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  /* Leer Pin A
Cualquier estado que tenga reflejará la última posición
*/
  pinALast = digitalRead(pinA);
  Serial.begin(9600);
}


void loop() {
  aVal = digitalRead(pinA);
  if (aVal != pinALast) {  // Significa que el control está rotando
    // Si el control está rotando, necesitamos determinar la dirección
    // Lo hacemos leyendo el pin B.
    if (digitalRead(pinB) != aVal) {  // Significa que Pin A cambió primero - Estamos rotando en sentido horario
      encoderPosCount++;
      bCW = true;
    } else {  // De lo contrario, B cambió primero y estamos moviendo en sentido antihorario
      bCW = false;
      encoderPosCount--;
    }
    Serial.print("Rotado: ");
    if (bCW) {
      Serial.println("sentido horario");
    } else {
      Serial.println("sentido antihorario");
    }
    Serial.print("Posición del encoder: ");
    Serial.println(encoderPosCount);
  }
  pinALast = aVal;
}

