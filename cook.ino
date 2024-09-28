// Include necessary libraries
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <DHT.h>

// Define DHT11 sensor type and pin
#define DHTPIN 4          // GPIO4
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Variables to store sensor data
float temperature = 0.0;
float humidity = 0.0;

void setup(){
  // Initialize Serial Monitor
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting ESP32 Cooking Timer Integration...");

  // Initialize DHT11 sensor
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define routes
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "ESP32 Cooking Timer API");
  });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    String tempStr = String(temperature, 1);
    String humStr = String(humidity, 1);
    String json = "{\"temperature\":" + tempStr + ",\"humidity\":" + humStr + "}";
    request->send(200, "application/json", json);
  });

  // Enable CORS
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "Content-Type");

  // Start server
  server.begin();
}

void loop(){
  // Read temperature and humidity every 2 seconds
  static unsigned long lastRead = 0;
  unsigned long now = millis();
  if (now - lastRead > 2000){
    lastRead = now;
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    // Check if any reads failed and exit early (to try again)
    if (isnan(temp) || isnan(hum)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    temperature = temp;
    humidity = hum;

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }
}
