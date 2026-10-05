#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RED_LED 25
#define YELLOW_LED 26
#define GREEN_LED 27
#define BUTTON_PIN 32
#define BUZZER_PIN 23

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool crossingActive = false;

void setup() {
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("ROAD CLEAR");

  lcd.setCursor(0, 1);
  lcd.print("Press Button");

  Serial.println("Smart Pedestrian Crossing");
  Serial.println("System Ready");
}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW && !crossingActive) {

    crossingActive = true;

    delay(200);

    Serial.println("Pedestrian Button Pressed");

    // Warning phase
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("GET READY");

    Serial.println("GET READY");

    delay(2000);

    // Stop traffic
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    Serial.println("Traffic STOPPED");

    // Countdown
    for (int count = 10; count >= 1; count--) {

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("CROSSING IN:");

      lcd.setCursor(5, 1);
      lcd.print(count);
      lcd.print(" SEC");

      Serial.print("Countdown: ");
      Serial.println(count);

      tone(BUZZER_PIN, 1000, 150);

      delay(1000);
    }

    // Pedestrian crossing
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("CROSS NOW");

    lcd.setCursor(0, 1);
    lcd.print("BE CAREFUL!");

    Serial.println("CROSS NOW");

    tone(BUZZER_PIN, 1500, 500);

    delay(5000);

    // Return to normal
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ROAD CLEAR");

    lcd.setCursor(0, 1);
    lcd.print("Press Button");

    Serial.println("ROAD CLEAR");

    crossingActive = false;
  }
}