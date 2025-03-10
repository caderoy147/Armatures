/*
 * ServoControl.h & ServoControl.cpp
 * 
 * Servo Control Library for Arduino
 * 
 * Authors: Arbasto, Nathaniel L., Enjambre, Benedict James M., Punay, Jayco Belle C.,
 * Created: 09/03/2025
 * License: MIT License
 * 
 * Description:
 * This library provides functions to control up to MAX_SERVOS servos using 
 * smooth motion and speed control. It includes initialization, speed adjustment, 
 * and movement functions, including special handling for a claw mechanism.
 * 
 * Features:
 * - Supports up to 6 servos.
 * - Smooth movement with configurable speed.
 * - Claw control with adjustable grip width.
 * 
 * Usage:
 * - Call `initializeServos()` to set up servos.
 * - Use `moveServoSmooth(index, target)` to move a servo gradually.
 * - Adjust speed with `setSpeed(index, speed)`.
 * - Control the claw using `controlClaw(status, width)`.
 * 
 * (c) 2025 Armatures. Released under the MIT License.
 */

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
void setupLeds();
void setLed(uint8_t body, bool state);

#endif
