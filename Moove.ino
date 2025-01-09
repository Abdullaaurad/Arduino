#include "Arduino.h"

void setup()
{
    for (int i = 2; i <= 7; i++)
    {
        pinMode(i, OUTPUT);
    }
}

// the loop function runs over and over again forever
void loop()
{
    for (int i = 2; i <= 7; i++)
    {
        digitalWrite(i, HIGH); // Turn pin ON
        delay(100);            // Wait for 500ms
        digitalWrite(i, LOW);  // Turn pin OFF
        delay(100);
    }
}