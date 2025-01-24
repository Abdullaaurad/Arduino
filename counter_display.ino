// Pin configuration
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // a, b, c, d, e, f, g
const int digitPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1}  // 9
};

void setup() {
  // Set all segment pins as output
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void displayDigit(int number) {
  // Set each segment based on the digitPatterns array
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[number][i]);
  }
}

void loop() {
  // Count from 0 to 9 with a 1-second delay
  for (int i = 0; i < 10; i++) {
    displayDigit(i);
    delay(1000);
  }
}
