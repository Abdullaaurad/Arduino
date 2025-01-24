float temperature; // Variable to store the calculated temperature

void setup() {
  Serial.begin(9600); // Start the serial communication to print the value
}

void loop() {
  int Value = analogRead(A0); // Read the analog value from A0 (0 to 1023)

  // Calculate the voltage (assuming 5V reference for the Arduino)
  float Vout = Value * 5.0 / 1023.0; // Convert analog value to voltage

  // Calculate the temperature in Celsius
  temperature = Vout * 100.0; // LM35 gives 10mV per degree Celsius, so multiply by 100

  // Print the raw analog value
  Serial.print("Analog Value = ");
  Serial.println(Value);

  // Print the voltage
  Serial.print("Voltage Value = ");
  Serial.println(Vout, 2); // Voltage with 2 decimal places

  // Print the temperature
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(500); // Delay to avoid flooding the Serial Monitor
}
