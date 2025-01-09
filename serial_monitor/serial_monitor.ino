// Constants
const int sensorPin = A0; // Analog pin connected to the sensor
const int ledPin = 9;     // PWM pin connected to the LED

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the input on analog pin 0
  int sensorValue = analogRead(sensorPin);
  
  // Map the sensor value (0-1023) to the LED brightness range (0-255)
  int ledValue = map(sensorValue, 0, 1023, 0, 255);
  
  // Output the LED brightness
  analogWrite(ledPin, ledValue);
  
  // Print out the sensor value and corresponding LED value
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" -> LED Brightness: ");
  Serial.println(ledValue);

  // Small delay for stability
  delay(10);
}
