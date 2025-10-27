/****************************************************
 * Project: Gesture Recognition using ESP32 + MPU6050 + TinyML
 * Author: [Your Name]
 * Date: [Insert Date]
 * Description:
 *  - Reads motion data from MPU6050
 *  - Classifies gestures using a placeholder ML model
 *  - Controls LEDs based on detected gestures
 ****************************************************/

#include <Wire.h>
#include "MPU6050.h"
#include "gesture_model_data.h"  // TinyML model header (optional placeholder)

// Simulated gesture classes
const char* gesture_classes[] = {"LEFT", "RIGHT", "UP", "DOWN", "STILL"};

// LED pins for action indication
#define LED_LEFT  12
#define LED_RIGHT 13
#define LED_UP    14
#define LED_DOWN  27

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);

  Serial.println("Initializing MPU6050...");
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
  Serial.println("MPU6050 connected successfully!");
}

void loop() {
  // Get sensor readings
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Normalize sensor data (simple scaling)
  float X = ax / 16384.0;
  float Y = ay / 16384.0;
  float Z = az / 16384.0;

  // Simulated classification logic
  String gesture = detectGesture(X, Y, Z);

  Serial.print("Detected Gesture: ");
  Serial.println(gesture);

  // Perform actions based on gesture
  controlLEDs(gesture);

  delay(500); // adjust delay based on performance
}

// ----------------------------------------------------
// Simple gesture classification (placeholder logic)
// Replace with your TinyML model inference
// ----------------------------------------------------
String detectGesture(float X, float Y, float Z) {
  if (X > 0.8) return "RIGHT";
  else if (X < -0.8) return "LEFT";
  else if (Y > 0.8) return "UP";
  else if (Y < -0.8) return "DOWN";
  else return "STILL";
}

// ----------------------------------------------------
// Control LEDs based on gesture
// ----------------------------------------------------
void controlLEDs(String gesture) {
  digitalWrite(LED_LEFT,  gesture == "LEFT");
  digitalWrite(LED_RIGHT, gesture == "RIGHT");
  digitalWrite(LED_UP,    gesture == "UP");
  digitalWrite(LED_DOWN,  gesture == "DOWN");
}
