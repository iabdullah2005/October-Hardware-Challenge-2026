#include <ESP32Servo.h>

#define TRIG_PIN 5
#define ECHO_PIN 18

#define SERVO_PIN 19

#define GREEN_LED 25
#define YELLOW_LED 26
#define RED_LED 27

#define BUZZER_PIN 23

Servo parkingServo;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  parkingServo.attach(SERVO_PIN);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  parkingServo.write(90);

  Serial.println("Smart Parking Assistant Started");
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  return duration * 0.0343 / 2;
}

void moveServo(int targetAngle) {
  int currentAngle = parkingServo.read();

  if (currentAngle < targetAngle) {
    for (int angle = currentAngle; angle <= targetAngle; angle++) {
      parkingServo.write(angle);
      delay(8);
    }
  } 
  else if (currentAngle > targetAngle) {
    for (int angle = currentAngle; angle >= targetAngle; angle--) {
      parkingServo.write(angle);
      delay(8);
    }
  }
}

void loop() {
  float distance = getDistance();

  Serial.print("Distance: ");

  if (distance == -1) {
    Serial.println("No object detected");
  } 
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (distance == -1 || distance > 50) {

    digitalWrite(GREEN_LED, HIGH);

    moveServo(90);

    Serial.println("STATUS: PARKING AVAILABLE");
  }

  else if (distance >= 20 && distance <= 50) {

    digitalWrite(YELLOW_LED, HIGH);

    moveServo(45);

    Serial.println("STATUS: VEHICLE APPROACHING");

    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
  }

  else {

    digitalWrite(RED_LED, HIGH);

    moveServo(0);

    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("STATUS: STOP - VEHICLE TOO CLOSE");
  }

  delay(300);
}