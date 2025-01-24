bool running = true; // Flag to control whether output is running

void setup()
{
    Serial.begin(9600); // Start serial communication
    pinMode(A0, INPUT); // Set A0 as input
    Serial.println("Starting...");
}

void loop()
{
    // Check if there is input from the Serial Monitor
    if (Serial.available() > 0)
    {
        char input = Serial.read(); // Read the input character
        if (input == '\n')
        {                       // Check if the input is "Enter" (newline)
            running = !running; // Toggle the running state
            Serial.println(running ? "Resumed" : "Stopped");
        }
    }

    // Execute the main logic only if running is true
    if (running)
    {
        int Value = analogRead(A0);     // Read analog value
        float V = Value * 5.0 / 1023.0; // Calculate voltage

        // Calculate elapsed time in seconds
        unsigned long timeElapsed = millis() / 200;

        // Print time and voltage
        Serial.print("Time: ");
        Serial.print(timeElapsed in 0.2 periods); // Print time in seconds
        Serial.print("s, Voltage: ");
        Serial.print(V, 3); // Print voltage with 3 decimal places
        Serial.println("V");

        delay(200); // Wait 200 ms
    }
}