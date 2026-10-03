#include <DHT.h>

// Pin Definitions
#define DHT_PIN 4
#define DHT_TYPE DHT22

#define LED_PIN 15
#define BUZZER_PIN 25

// DHT Sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Setup
void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initially alert devices OFF
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();

  delay(1000);

  Serial.println("================================");
  Serial.println("DAY 02 - SMART HEAT ALERT");
  Serial.println("ESP32 + DHT22");
  Serial.println("================================");
  Serial.println("System started.");
}

// Main Loop
void loop() {

  // 1. Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // 2. Check sensor reading
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("ERROR,DHT22_READ_FAILED");

    delay(2000);
    return;
  }

  // 3. Send data to Python
  Serial.print("DATA,");
  Serial.print(temperature, 2);
  Serial.print(",");
  Serial.println(humidity, 2);

  // Example:
  // DATA,26.50,54.20

  // 4. Check commands from Python
  if (Serial.available() > 0) {

    String command = Serial.readStringUntil('\n');

    command.trim();

    if (command == "ALERT") {

      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);

      Serial.println("STATUS,ANOMALY");

    }

    else if (command == "NORMAL") {

      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);

      Serial.println("STATUS,NORMAL");
    }

    else if (command == "OFF") {

      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);

      Serial.println("STATUS,OFF");
    }
  }

  // Wait before next reading
  delay(2000);
}