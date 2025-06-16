#ifndef gnomeAVR_h
#define gnomeAVR_h

#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include "movement.h"

// Pin definitions
#define PWMA 10
#define AI1 A0
#define AI2 A1
#define PWMB 11
#define BI1 A2
#define BI2 A3
#define MISO_PIN 12
#define MOSI_PIN 8
#define SS_PIN 4
#define SCK_PIN 13
#define RUN 2
#define KNOB A6
#define SV0_PIN 3
#define SV1_PIN 5
#define SV2_PIN 6
#define SV3_PIN 9

void gnomeInit();
int analog(uint8_t channel);
int digital(uint8_t channel);
int knob();
int knob(int min, int max);
int SW_Run();
void waitSW_Run();
void motor(int id, int speed);
void servo(int id, int angle);
void sleep(int ms);

#endif