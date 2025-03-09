#include "ServoControl.h"


void setup() {
    initializeServos();
    setSpeed(5, 10);  // Medium speed for the claw
}

void loop() {
    controlClaw(true, 50); // Open claw to 50 degrees
    delay(2000);
    controlClaw(false, 0); // Close claw fully
    delay(2000);
}
