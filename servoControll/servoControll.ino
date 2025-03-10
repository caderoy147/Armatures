#include "ServoControl.h"


void setup() {
    initializeServos();
    setSpeed(5, 10);  // Medium speed for the claw
    setupLeds();
}

void loop() {
    for (uint8_t i = 0; i < 6; i++) {
        setLed(i, HIGH);
        delay(500);
        setLed(i, LOW);
        delay(500);
    }
}
