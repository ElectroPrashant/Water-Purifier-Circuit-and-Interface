# Water-Purifier-Circuit-and-Interface
This circuit is controlled by Arduino Nano.

Components Connected-
- 24V DC Solenoid
- Sparkfun 16x2 LCD
- Water Level Sensor
- HC-CR Ultrasonic Sensor
- 4x Push Buttons
- 1x 220 ohm Resistor
- 1x 600 ohms Resistor
- 1x P-type Transistor

Power Consumption-
This circuit is powered by Compact low profile AC-DC power supply
Voltage output- 24V
Max Current - 42mA

Max Current Intake of Arduino nano is 40mA
Thus, Max resistance would be 5V/40mA = 128 ohms
To get volatage drop of around 5V across the Arduino Nano
We need resistor of around 614 ohms.
Any fluctuation/Miscalculated Power would be handeled by in-built Voltage Regulator.

Interface-
The Interface is coded to grant it ability to handle basic as well as multiple user input 
through basic push button and Display it on LCD screen.
