int Value; // Declare a variable to store the analog value

void setup() {
  pinMode(A0, INPUT); // Set A0 as an input pin (optional, analog pins default to input)
  Serial.begin(9600); // Start the serial communication to print the value
}

void loop() {
  Value = analogRead(A0); // Read the analog value from A0 (0 to 1023)
  Serial.println(Value);  // Print the value to the Serial Monitor
  delay(500);             // Add a small delay (e.g., 500ms) to avoid flooding the Serial Monitor
}