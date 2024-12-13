# temp-monitor-system
This project is a simple temperature monitoring system that reads simulated temperature values, triggers LEDs based on the temperature thresholds, and displays the temperature on an LCD screen.

List of key features:
Real-time temperature simulation.
LED status indicators based on temperature thresholds.
LCD display showing temperature readings in celsius.
Simple temperature monitoring with thresholds for safety.

Software Requirements:
Arduino IDE or compatible software to arduino.

Libraries required:
Wire.h (for I2C communication)
LiquidCrystal_I2C.h (for controlling the LCD screen)

Hardware Requirements:
Arduino Uno or compatible board
Potentiometer
3 LEDs (green, yellow, red)
16x2 LCD screen (with I2C interface)
Resistors for LEDs and potentiometer

Connect the hardware (potentiometer, LEDs, and LCD) as per the provided wiring diagram.
Install the necessary Arduino libraries (Wire and LiquidCrystal_I2C).
Upload the provided code to your Arduino board using the Arduino IDE.

Instructions for using the project:
Open the Arduino IDE, connect your board, and upload the provided sketch.
The LCD will display the temperature value based on the potentiometer’s position.
The LED colors will change based on the simulated temperature (green for safe, yellow for warning, red for danger).

Code
A brief explanation of what the code does and any important functions or logic.
This could include the setup of the LCD screen, the logic for reading the potentiometer, and the temperature thresholds.

Troubleshooting
If any common issues are encountered, provide possible solutions. For example:
If the LCD screen isn’t displaying, check the I2C address.
If the LEDs aren't turning on, make sure the pin assignments are correct.
