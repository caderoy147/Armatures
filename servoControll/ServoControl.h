#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <Arduino.h>
#include <Servo.h>

#define MAX_SERVOS 6  // Adjust if needed

void initializeServos();  // Function to initialize all servos
void initServo(int index, int pin);
void setSpeed(int index, int speed);
void moveServoSmooth(int index, int target);
void controlClaw(bool status, int width);

#endif
