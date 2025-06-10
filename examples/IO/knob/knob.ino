#include <gnomeAVR.h>

void setup() {
  gnomeInit();
  Serial.begin(9600);
}

void loop() {
    int rawValue = knob();              // Read the raw value from the knob
    int mappedValue = knob(0, 180);     // Map the raw value to a range of 0 to 180
    Serial.print("Raw Value: ");
    Serial.print(rawValue);            // Print the raw value to the Serial Monitor
    Serial.print(" | Mapped Value: ");
    Serial.println(mappedValue);       // Print the mapped value to the Serial Monitor
    delay(100);                        // Delay for 100 milliseconds
}