# Voice Controlled Arduino Car

## 📌 Overview
This project is a voice-controlled robotic car that uses a mobile application to receive speech commands and control movement in real time via Bluetooth communication.

## 🚀 Features
- Voice-based control using mobile app 
- Wireless communication via Bluetooth (HC-05)
- Directional movement: forward, backward, left, right, stop 
- Real-time response to commands 
- Simple and user-friendly control system 

## 🛠️ Tech Stack
- Arduino Uno  
- Embedded C / Arduino IDE  
- Communication: HC-05 Bluetooth Module 
- Hardware: Motors, Motor Driver (L298N), Chassis, Wheels
- Mobile App: Dabble

## ⚙️ Working
The system uses the Dabble mobile application to convert voice commands into Bluetooth signals. These signals are transmitted via the HC-05 module to the Arduino. The Arduino processes the received commands and controls the motors accordingly to perform directional movements.


## ▶️ How to Run
1. Upload the code to Arduino  
2. Connect the HC-05 Bluetooth module
3. Pair the mobile device with HC-05
4. Open the Dabble app and use voice control
5. Give commands like “forward”, “left”, “right”, “back”

## 📌 Future Improvements
- Speed control using voice commands 
- Obstacle avoidance using ultrasonic sensor
- Camera integration for live monitoring  
