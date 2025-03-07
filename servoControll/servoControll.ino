#include "ServoControl.h"

void setup() {
    initializeServos();  // Initialize all servos in one call
}

void loop() {
   /* // Test movement for all servos
    for (int i = 0; i < MAX_SERVOS; i++) {
        setSpeed(i, 10);  // Set medium speed
        moveServoSmooth(i, 90);  // Move to 90 degrees
        delay(2000);
        moveServoSmooth(i, 0);  // Move back to 0 degrees
        delay(2000);
    }
    
    // Test special claw behavior
    setSpeed(5, 5);
    moveServoSmooth(5, 65);  // Move claw to max limit
    delay(2000);
    moveServoSmooth(5, 0);  // Move claw to min limit
    delay(2000);
    
    // Test speed limits
    setSpeed(0, 0);  // Stop servo 0
    delay(2000);
    setSpeed(0, 20); // Max speed servo 0
    moveServoSmooth(0, 180);
    delay(2000);*/
        setSpeed(4, 20);  // Set medium speed
        moveServoSmooth(4, -90);  // Move to 90 degrees
        delay(1000);
        setSpeed(4, 20);
        moveServoSmooth(4, 0);  // Move back to 0 degrees
        delay(1000);
}
