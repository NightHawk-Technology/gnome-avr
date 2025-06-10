
# GnomeAVR - Robot Controller Board

## Overview

**GnomeAVR** is a compact and powerful robot controller board built around the **ATMega328P** microcontroller. It is designed to control various robotic components including motors, servos, analog/digital sensors, and potentiometers.  

- **Input Voltage**: 6V – 14V  
- **Motor Driver**: TB6612FNG (Dual Channel, up to 3.2A per channel)  
- **Servo Control**: Supports up to 4 PWM channels  
- **Analog Input**: 8 channels (10-bit resolution via MCP3008)  
- **Digital Input**: 8 channels (shared with analog)  
- **Knob/Potentiometer**: Built-in for user input control

---

## 📥 INPUT FUNCTIONS

### 🔢 Analog Input (8 Channels)
Reads analog value from channel (0-1023).
```c
analog(int ch);
```

### 🔘 Digital Input (8 Channels)
Reads digital HIGH/LOW (1/0) from channel.
```c
digital(int ch);
```

### 🎚️ Potentiometer (Knob)

- **Raw Data (0-1023)**  
  ```c
  knob();
  ```

- **Scaled Range**  
  Map knob value to custom range.
  ```c
  knob(int min, int max);
  ```

---

## 📤 OUTPUT FUNCTIONS

### 🔄 Motor Control (2 Channels, up to 4 motors)

#### Direct Motor Control
Control motor speed directly.  
Speed range: -100 (full reverse) to 100 (full forward).
```c
motor(int ch, int speed);
```

#### Functional Motor Commands

- **Move Forward (both motors same speed)**
  ```c
  fd(int speed);
  ```

- **Move Forward (each motor independently)**
  ```c
  fd2(int speedA, int speedB);
  ```

- **Move Backward (both motors same speed)**
  ```c
  bk(int speed);
  ```

- **Move Backward (each motor independently)**
  ```c
  bk2(int speedA, int speedB);
  ```

#### Turning & Spinning

- **Spin Left in place**
  ```c
  sl(int speed);
  ```

- **Spin Right in place**
  ```c
  sr(int speed);
  ```

- **Turn Left (curved path)**
  ```c
  tl(int speed);
  ```

- **Turn Right (curved path)**
  ```c
  tr(int speed);
  ```

---

### 🦾 Servo Motor Control

Control servo angle for up to 4 servos (0°–180°).
```c
servo(int ch, int angle);
```

**Example:**
```c
servo(0, 180);  // Set servo on channel 0 to 180°
```

---

## 📘 Notes

- Ensure power supply matches motor and servo requirements.
- Motors are controlled via the TB6612FNG dual H-bridge driver.
- Analog and digital channels are shared but interpreted differently by function used.

---

## 🧠 Ideal For

- Line-following robots  
- Obstacle-avoidance bots  
- Remote-controlled vehicles  
- Educational robotics projects

---

## 📞 Support

For questions or technical assistance, please contact the developer or check the documentation site.

---
