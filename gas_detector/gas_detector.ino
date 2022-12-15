void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(A3);
  Serial.println("CO2 Level (PPM): ");
  Serial.println(sensorValue);
  delay(2000);
}