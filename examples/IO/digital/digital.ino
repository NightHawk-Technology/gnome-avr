#include <gnomeAVR.h>

void setup() {
  gnomeInit();
  Serial.begin(115200);
  waitSW_Run();
}

void loop() {
    int value = digital(0);     // Read the digital value from Channel 0
    Serial.println(value);      // Print the value to the Serial Monitor
    delay(100);                 // Delay for 100 milliseconds
}