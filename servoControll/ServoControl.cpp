#include "ServoControl.h"

Servo servos[MAX_SERVOS];
int currentAngle[MAX_SERVOS] = {0};  // Default start at 0 degrees
int speedDelay[MAX_SERVOS] = {10};

void initializeServos() {
    initServo(0, 3);
    initServo(1, 5);
    initServo(2, 6);
    initServo(3, 9);
    initServo(4, 10);
    initServo(5, 11); // Special: Claw (0-65 degrees)
   // servo 5 initialized at claw block
}

void initServo(int index, int pin) {
    if (index < MAX_SERVOS) {
        servos[index].attach(pin);
        if (pin == 11) {
            currentAngle[index] = 65;  // Start at max allowed angle for the claw
        }
        servos[index].write(currentAngle[index]);  
        delay(1000);
    }
}

void setSpeed(int index, int speed) {
    if (index < MAX_SERVOS) {
        speed = constrain(speed, 0, 20); // Limit speed between 0 (stop) and 20 (fastest)
        speedDelay[index] = (speed == 0) ? 9999 : (21 - speed); // Reverse logic: 1 is slowest, 20 is fastest, 0 is stop
    }
}

void moveServoSmooth(int index, int target) {
    if (index < MAX_SERVOS) {
        // Normalize target angle to keep it in range [-180, 180] and map negatives
        target = (target + 180) % 360 - 180; // Ensures -179 acts like 179
        target = abs(target); // Make all values positive
        
        // Limit claw range
        if (index == 5) {
            target = constrain(target, 0, 65);
        } else {
            target = constrain(target, 0, 180);
        }

        if (target > currentAngle[index]) {
            for (int pos = currentAngle[index]; pos <= target; pos++) {
                servos[index].write(pos);
                delay(speedDelay[index]);
            }
        } else {
            for (int pos = currentAngle[index]; pos >= target; pos--) {
                servos[index].write(pos);
                delay(speedDelay[index]);
            }
        }

        currentAngle[index] = target;
    }
}

void controlClaw(bool status, int width) {
    width = constrain(width, 0, 65); // Keep within limits
    int targetAngle = status ? width : (65 - width); // Open moves to width, close moves opposite
    moveServoSmooth(5, targetAngle);
}

