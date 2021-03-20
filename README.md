# ESPNOW-Gyro-Servo
With the help of the ESP-Now protocol, we intend to receive x values from the MPU6050 module, and at the destination in this way, we control one to change the x values of the servo motor.

## What it DO!
In the project of servo motor control with gyro transmitter, which is our nodemcu board with ESP32 chip, the task is to obtain x-axis values from the mpu6050 module and send it to the receiver by ESP-NOW protocol. And in the other part of the project, our receiver, for which we considered a Wemos board to receive the sent data and analyze it to command the SG90 servo motor.

### Items needed
-ESP32
-Wemos
-MPU6050
-Servo sg90

### Required libraries
-esp_now
-WiFi

## Conclusion
In this project, we analyzed the values of the Giro MPU6050 module and sent it to the second board, and as a result, we were able to control the servo motor at the destination. This project can be used in cases where motion control is needed in a project, but without a physical connection, and of course different scenarios can be applied for such projects.


 Full Tutorial at http://cifertech.net/
