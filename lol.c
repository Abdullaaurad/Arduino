int counter = 0;

void setup() {
  for (int i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Loop through pins 2 to 7 (6 bits)
  for (int i = 2; i <= 7; i++) {
    if (counter & (1 << (i - 2))) {
      digitalWrite(i, HIGH);
    } else {
      digitalWrite(i, LOW);
    }
  }

  counter++;

  // Optionally, reset the counter if it exceeds the maximum 6-bit value (63)
  if (counter > 63) {
    counter = 0;  // Reset counter to 0 after it reaches 64 (binary 1000000)
  }

  delay(100);  // Delay to make the change visible
}