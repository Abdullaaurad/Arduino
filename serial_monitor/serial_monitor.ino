#include <DHT.h>

// Pin definitions
const int TRIG_PIN = 9;     // Ultrasonic sensor trigger pin
const int ECHO_PIN = 10;    // Ultrasonic sensor echo pin
const int LED_PIN = 11;     // LED pin
const int DHT_PIN = 4;      // DHT11 data pin
const int LDR_PIN = A0;     // Analog pin for LDR

// Constants
const int DISTANCE_THRESHOLD = 100;   // Distance threshold in cm
const int LED_MAX_BRIGHTNESS = 255;
const int DARKNESS_THRESHOLD = 500;  // Adjust this value based on your LDR
const int DHTTYPE = DHT11;           // Define DHT type

// Initialize the DHT sensor
DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);

  Serial.println("Light Level | Is Dark? | Distance(cm) | LED Status | Temperature(°C) | Humidity(%)");

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read light level (0-1023)
  int lightLevel = analogRead(LDR_PIN);

  // Check if it's dark (LDR value BELOW threshold in darkness)
  boolean isDark = (lightLevel < DARKNESS_THRESHOLD);

  // Get distance reading from ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  // Read temperature and humidity from the DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check for DHT read failure
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    temperature = humidity = 0;
  }

  // Calculate LED intensity
  int ledIntensity = 0;  // Default to off

  if (isDark && distance <= DISTANCE_THRESHOLD) {
    ledIntensity = map(distance, 0, DISTANCE_THRESHOLD, LED_MAX_BRIGHTNESS, 0);
  }

  // Set LED brightness
  analogWrite(LED_PIN, ledIntensity);

  // Debug output
  Serial.print(lightLevel);
  Serial.print(" | ");
  Serial.print(isDark ? "Dark" : "Light");
  Serial.print(" | ");
  Serial.print(distance);
  Serial.print("cm | ");
  Serial.print(ledIntensity);
  Serial.print("/255 | ");
  Serial.print(temperature);
  Serial.print("°C | ");
  Serial.print(humidity);
  Serial.println("%");

  // Delay for stability
  delay(500);
}
