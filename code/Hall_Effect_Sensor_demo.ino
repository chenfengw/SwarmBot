int mag_strength;
int sensor_pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  mag_strength = analogRead(sensor_pin);
  Serial.print("Magnetic field strength is: ");
  Serial.println(mag_strength);
  delay(200);
}
