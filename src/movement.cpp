#include "gnomeAVR.h"
#include "movement.h"

void fd(int speed) { motor(1, speed); motor(2, speed); }
void bk(int speed) { motor(1, -speed); motor(2, -speed); }
void fd2(int speedA, int speedB) { motor(1, speedA); motor(2, speedB); }
void bk2(int speedA, int speedB) { motor(1, -speedA); motor(2, -speedB); }

void sl(int speed) { motor(1, -speed); motor(2, speed); }
void sr(int speed) { motor(1, speed); motor(2, -speed); }
void tl(int speed) { motor(1, 0); motor(2, -speed); }
void tr(int speed) { motor(1, -speed); motor(2, 0); }
void stop() { motor(1, 0); motor(2, 0); }