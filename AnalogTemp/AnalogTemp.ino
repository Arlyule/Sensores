const int sensor = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensor);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;
  Serial.print("Temperatura = ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000);
}
