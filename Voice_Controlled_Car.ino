#include <SoftwareSerial.h>

// Create Bluetooth serial
SoftwareSerial BT(2, 3); // RX, TX

// Right motor
int enableRightMotor = 5;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

// Left motor
int enableLeftMotor = 6;
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

char command = 'S'; // Default state: Stop

void setup() {
pinMode(enableRightMotor, OUTPUT);
pinMode(rightMotorPin1, OUTPUT);
pinMode(rightMotorPin2, OUTPUT);

pinMode(enableLeftMotor, OUTPUT);
pinMode(leftMotorPin1, OUTPUT);
pinMode(leftMotorPin2, OUTPUT);

analogWrite(enableRightMotor, 0);
analogWrite(enableLeftMotor, 0);

Serial.begin(9600);
BT.begin(9600);
Serial.println("Bluetooth Car Ready. Waiting for commands...");


}

void loop() {
if (BT.available()) {
command = BT.read();
Serial.print("Command: ");
Serial.println(command);
controlCar(command);
}
}

void controlCar(char cmd) {
int speed = 255;

switch (cmd) {
case 'F': // Forward
moveMotor(speed, speed);
break;
case 'B': // Backward
moveMotor(
-speed,
-speed);

break;
case 'L': // Left
moveMotor(0, speed);
break;
case 'R': // Right
moveMotor(speed, 0);
break;
case 'S': // Stop
moveMotor(0, 0);
break;
default:

moveMotor(0, 0);
break;
}
}
void moveMotor(int rightMotorSpeed, int leftMotorSpeed) {
// Right motor direction
if (rightMotorSpeed > 0) {
digitalWrite(rightMotorPin1, HIGH);
digitalWrite(rightMotorPin2, LOW);
} else if (rightMotorSpeed < 0) {
digitalWrite(rightMotorPin1, LOW);
digitalWrite(rightMotorPin2, HIGH);
} else {
digitalWrite(rightMotorPin1, LOW);
digitalWrite(rightMotorPin2, LOW);
}

// Left motor direction
if (leftMotorSpeed > 0) {
digitalWrite(leftMotorPin1, HIGH);
digitalWrite(leftMotorPin2, LOW);
} else if (leftMotorSpeed < 0) {
digitalWrite(leftMotorPin1, LOW);
digitalWrite(leftMotorPin2, HIGH);
} else {
digitalWrite(leftMotorPin1, LOW);
digitalWrite(leftMotorPin2, LOW);
}

analogWrite(enableRightMotor, abs(rightMotorSpeed));
analogWrite(enableLeftMotor, abs(leftMotorSpeed));