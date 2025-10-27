# ✋ ESP32 Gesture Recognition using MPU6050 and TinyML

This project demonstrates **gesture recognition on ESP32** using **MPU6050** sensor data and a simulated **TinyML model**.  
It detects movements like `LEFT`, `RIGHT`, `UP`, `DOWN`, and triggers LEDs based on recognized gestures.

---

## 🧠 Features
- Reads accelerometer + gyroscope data from MPU6050  
- Uses lightweight logic (replaceable with TinyML inference)  
- Controls LEDs according to detected gestures  
- Designed for low-power edge AI applications  

---

## ⚙️ Components
| Component | Description |
|------------|--------------|
| ESP32 | Microcontroller board |
| MPU6050 | Accelerometer + Gyroscope sensor |
| LEDs | For gesture indication |
| Jumper Wires | Connections |

---

## 🔌 Connections
| MPU6050 | ESP32 |
|----------|--------|
| VCC | 3.3V |
| GND | GND |
| SDA | 21 |
| SCL | 22 |

LED pins:  
- LEFT → GPIO12  
- RIGHT → GPIO13  
- UP → GPIO14  
- DOWN → GPIO27  

---

## 🧩 Setup
1. Install **MPU6050 library** from Arduino IDE Library Manager.  
2. Connect components as per the wiring table.  
3. Upload `ESP32_Gesture_Recognition_TinyML.ino` to your ESP32.  
4. Open **Serial Monitor** (115200 baud) to see gesture output.

---

## 🧠 TinyML Integration (Optional)
Once you train your model (using **Edge Impulse** or **TensorFlow**):
1. Convert it to `.tflite` format.  
2. Convert `.tflite` → `.h` using [xxd](https://linux.die.net/man/1/xxd):  
   ```bash
   xxd -i model.tflite > gesture_model_data.h
