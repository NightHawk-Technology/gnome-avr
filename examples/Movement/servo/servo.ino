#include <gnomeAVR.h>

void setup() {
  gnomeInit();
  waitSW_Run();
}

void loop() {
  servo(0, 0); delay(500);
  servo(0, 90); delay(500);
  servo(0, 180); delay(500);
}