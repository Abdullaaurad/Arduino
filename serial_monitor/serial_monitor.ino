// Initialize variables
int lastValue = LOW; // Store the previous button state

void setup() {
  pinMode(2, OUTPUT);   // Set pin 2 as output
  pinMode(3, INPUT_PULLUP);  // Set pin 3 as input (button)
  Serial.begin(9600);   // Start serial communication
}

void loop() {
  int currentValue = digitalRead(3); // Read the button state

  // Check if the button state has changed
  if (currentValue != lastValue) {
    // Print the current button value
    Serial.print("Button State: ");
    Serial.println(currentValue);

    // Update the LED based on the button state
    if (currentValue) {
      digitalWrite(2, HIGH); // Turn LED on
    } else {
      digitalWrite(2, LOW);  // Turn LED off
    }

    // Save the current button state
    lastValue = currentValue;
  }

  delay(500); // Add a slight delay for smoother response
}
