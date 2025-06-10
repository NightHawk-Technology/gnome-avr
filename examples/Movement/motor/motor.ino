#include <gnomeAVR.h>

void setup() {
  gnomeInit();
  waitSW_Run();
}

void loop() {
    for (int i = 0; i <= 100; i++) {
        motor(1, i); motor(2, i); delay(100);
    }
    delay(1000);
    for (int i = 100; i > 0; i--) {
        motor(1, i); motor(2, i); delay(100);
    }
    delay(1000);
    for (int i = 0; i > -100; i--) {
        motor(1, i); motor(2, i); delay(100);
    }
    delay(1000);
}