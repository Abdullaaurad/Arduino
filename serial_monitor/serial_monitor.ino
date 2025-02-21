#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Web server on port 80
WebServer server(80);

// Potentiometer pin
const int POT_PIN = 34;  // GPIO 34 (ADC6/A0)

void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Configure ADC
  analogReadResolution(12);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Setup server handlers
  server.on("/", handleRoot);        // Page display
  server.on("/read", handleRead);    // AJAX endpoint for readings
  
  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = R"(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 Potentiometer Reader</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <style>
        body { font-family: Arial; text-align: center; margin: 20px; }
        .readings { font-size: 24px; margin: 20px 0; }
      </style>
    </head>
    <body>
      <h1>ESP32 Potentiometer Reader</h1>
      <div class="readings">
        <div>ADC Value: <span id="adcValue">--</span></div>
        <div>Voltage: <span id="voltage">--</span>V</div>
      </div>
      <script>
        function updateReadings() {
          fetch('/read')
            .then(response => response.json())
            .then(data => {
              document.getElementById('adcValue').textContent = data.adc;
              document.getElementById('voltage').textContent = data.voltage;
            });
        }
        setInterval(updateReadings, 100);
      </script>
    </body>
    </html>
  )";
  server.send(200, "text/html", html);
}

void handleRead() {
  int adcValue = analogRead(POT_PIN);
  float voltage = adcValue * (3.3 / 4095.0);
  
  String json = "{\"adc\":" + String(adcValue) + ",\"voltage\":" + String(voltage, 2) + "}";
  server.send(200, "application/json", json);
}