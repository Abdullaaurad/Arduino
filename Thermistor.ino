const int thermistorPin = A0; // Pin connected to the thermistor
const int seriesResistor = 10000; // Value of the fixed resistor (10kΩ)
const float nominalResistance = 10000; // Thermistor resistance at 25°C
const float nominalTemperature = 25; // Nominal temperature (in Celsius)
const float bCoefficient = 3950; // Beta coefficient (depends on thermistor model)
const float supplyVoltage = 5.0; // Arduino supply voltage

void setup() {
  Serial.begin(9600); // Start serial communication
  Serial.println("Thermistor Temperature Measurement");
}

void loop() {
  // Read the analog value
  int analogValue = analogRead(thermistorPin);
  
  // Convert the analog value to voltage
  float voltage = analogValue * supplyVoltage / 1023.0;

  // Calculate the thermistor resistance
  float thermistorResistance = (supplyVoltage * seriesResistor / voltage) - seriesResistor;

  // Calculate the temperature using the Steinhart-Hart equation
  float temp = thermistorResistance / nominalResistance; // (R/Ro)
  temp = log(temp); // ln(R/Ro)
  temp /= bCoefficient; // 1/B * ln(R/Ro)
  temp += 1.0 / (nominalTemperature + 273.15); // + (1/To)
  temp = 1.0 / temp; // Invert to get Kelvin
  temp -= 273.15; // Convert to Celsius

  // Print the temperature
  Serial.print("Temperature: ");
  Serial.print(temp, 2); // Print with 2 decimal places
  Serial.println(" °C");

  delay(1000); // Wait for 1 second
}
