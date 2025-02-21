// Constants
const int ledPin = 12;      // Pin for the LED
const int buttonPin = 2;    // Pin for the push button

// Variables
int buttonState = 0;        // Variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);   // Initialize the LED pin as an output
  pinMode(buttonPin, INPUT);   // Initialize the pushbutton pin as an input
}

void loop() {
  // Read the state of the pushbutton
  buttonState = digitalRead(buttonPin);

  // Check if the pushbutton is pressed (HIGH)
  if (buttonState == HIGH) {
    // Turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn LED off
    digitalWrite(ledPin, LOW);
  }
}