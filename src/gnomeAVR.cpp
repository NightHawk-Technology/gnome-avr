#include "gnomeAVR.h"
#include <SPI.h>
#include <Wire.h>

Servo sv;

void sleep(int ms) { delay(ms); }

void gnomeInit() {
  pinMode(7, OUTPUT);
  pinMode(KNOB, INPUT);
  pinMode(RUN, INPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);

  pinMode(MISO_PIN, INPUT);
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(SS_PIN, OUTPUT);
  pinMode(SCK_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);

  pinMode(SV0_PIN, OUTPUT);
  pinMode(SV1_PIN, OUTPUT);
  pinMode(SV2_PIN, OUTPUT);
  pinMode(SV3_PIN, OUTPUT);
}

int analog(uint8_t channel) {
  if (channel > 8) return 0;

  digitalWrite(SS_PIN, LOW);
  digitalWrite(SCK_PIN, LOW);

  uint8_t command = (0x18 | channel) << 3;
  for (int8_t i = 7; i >= 3; i--) {
    digitalWrite(MOSI_PIN, (command >> i) & 1);
    digitalWrite(SCK_PIN, HIGH);
    digitalWrite(SCK_PIN, LOW);
  }

  uint16_t result = 0;
  for (int8_t i = 11; i >= 0; i--) {
    digitalWrite(SCK_PIN, HIGH);
    result |= (digitalRead(MISO_PIN) << i);
    digitalWrite(SCK_PIN, LOW);
  }

  digitalWrite(SS_PIN, HIGH);
  return result & 0x3FF;
}

int digital(uint8_t channel) {
  if (channel > 8) return 0;

  digitalWrite(SS_PIN, LOW);
  digitalWrite(SCK_PIN, LOW);

  uint8_t command = (0x18 | channel) << 3;
  for (int8_t i = 7; i >= 3; i--) {
    digitalWrite(MOSI_PIN, (command >> i) & 1);
    digitalWrite(SCK_PIN, HIGH);
    digitalWrite(SCK_PIN, LOW);
  }

  uint16_t result = 0;
  for (int8_t i = 11; i >= 0; i--) {
    digitalWrite(SCK_PIN, HIGH);
    result |= (digitalRead(MISO_PIN) << i);
    digitalWrite(SCK_PIN, LOW);
  }

  digitalWrite(SS_PIN, HIGH);
  return result & 0x01;
}

int knob() {
  return analogRead(KNOB);
}

int knob(int min, int max) {
  return map(analogRead(KNOB), 703, 0, min, max);
}

int SW_Run() {
  return digitalRead(RUN);
}

void waitSW_Run() {
  while (!digitalRead(RUN));
  while (digitalRead(RUN));
}

void motor(int id, int speed) {
  speed = constrain(speed, -100, 100);
  int pwm = map(abs(speed), 0, 100, 0, 255);

  if (id == 1) {
    if (speed > 0) {
      digitalWrite(AI1, HIGH);
      digitalWrite(AI2, LOW);
    } else if (speed < 0) {
      digitalWrite(AI1, LOW);
      digitalWrite(AI2, HIGH);
    } else {
      digitalWrite(AI1, LOW);
      digitalWrite(AI2, LOW);
    }
    analogWrite(PWMA, pwm);
  } else if (id == 2) {
    if (speed > 0) {
      digitalWrite(BI1, HIGH);
      digitalWrite(BI2, LOW);
    } else if (speed < 0) {
      digitalWrite(BI1, LOW);
      digitalWrite(BI2, HIGH);
    } else {
      digitalWrite(BI1, LOW);
      digitalWrite(BI2, LOW);
    }
    analogWrite(PWMB, pwm);
  }
}

void servo(int id, int angle) {
  if (id == 0) { sv.attach(SV0_PIN); }
  else if (id == 1) { sv.attach(SV1_PIN); }
  else if (id == 2) { sv.attach(SV2_PIN); }
  else if (id == 3) { sv.attach(SV3_PIN); }
  sv.write(angle);
}