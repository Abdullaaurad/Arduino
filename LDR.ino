void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(A0, INPUT); // Set A0 as input
}

void loop() {

  int Value = analogRead(A0);  // Read analog value
  float V = Value * 5.0 / 1023.0;  // Calculate voltage

  Serial.print("Voltage Value=");
  Serial.println(V);
  
  delay(200);
}
