int sensorPin = 12; // Pin digital donde se conecta el sensor de llama
void setup() {
  pinMode(sensorPin, INPUT); // Configura el pin del sensor de llama como entrada
  Serial.begin(9600); // Inicializa la comunicación serie a 9600 baudios
}
void loop() {
  int flame = digitalRead(sensorPin); // Lee el valor del sensor de llama (0 o 1)
  if (flame == HIGH) { // Si el sensor detecta llama
    Serial.println("¡Hay llama!"); // Imprime un mensaje en la consola serie
  } else { // Si el sensor no detecta llama
    Serial.println("¡No llama!");
  }
  delay(500); // Espera medio segundo antes de tomar otra lectura del sensor de llama
}

