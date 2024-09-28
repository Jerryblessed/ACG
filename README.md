# African Dish Guide - Hardware Setup

## Overview
This document outlines the steps to set up the hardware components for the African Dish Guide application, which uses an ESP-WROOM-32 microcontroller and a DHT11/DHT22 sensor to monitor temperature and humidity for cooking traditional African dishes.

## Components Required
- ESP-WROOM-32 microcontroller
- DHT11 or DHT22 temperature and humidity sensor
- Breadboard and jumper wires
- USB cable for powering the ESP32
- (Optional) Resistor (4.7kΩ for DHT11/DHT22)

## Hardware Setup Steps

### Step 1: Connect the DHT Sensor
1. **Identify the DHT Sensor Pins**:
   - VCC (Power)
   - GND (Ground)
   - Data (Signal)

2. **Wiring the DHT Sensor to the ESP32**:
   - Connect the VCC pin of the DHT sensor to the 3.3V pin on the ESP32.
   - Connect the GND pin of the DHT sensor to a GND pin on the ESP32.
   - Connect the Data pin of the DHT sensor to a digital GPIO pin on the ESP32 (e.g., GPIO 21).

   (Optional) If using a resistor, connect a 4.7kΩ resistor between the VCC and Data pins of the DHT sensor.

### Step 2: Set Up the ESP-WROOM-32
1. **Install the ESP32 Board in Arduino IDE**:
   - Open the Arduino IDE.
   - Go to `File` > `Preferences`.
   - Add the following URL to the "Additional Board Manager URLs": `https://dl.espressif.com/dl/package_esp32_index.json`.
   - Go to `Tools` > `Board` > `Board Manager`, search for "ESP32", and install it.

2. **Select the ESP32 Board**:
   - Go to `Tools` > `Board`, and select the appropriate ESP32 board (e.g., ESP32 Dev Module).

3. **Connect the ESP32 to Your Computer**:
   - Use a USB cable to connect the ESP32 to your computer.

### Step 3: Upload the Code
1. **Download the Application Code**:
   - Obtain the source code for the African Dish Guide application (from the repository or your local files).

2. **Open the Code in Arduino IDE**:
   - Open the main code file in the Arduino IDE.

3. **Select the Correct Port**:
   - Go to `Tools` > `Port`, and select the port corresponding to your ESP32.

4. **Upload the Code**:
   - Click on the upload button in the Arduino IDE to upload the code to the ESP32.

### Step 4: Test the Setup
1. **Open the Serial Monitor**:
   - Go to `Tools` > `Serial Monitor` in the Arduino IDE.
   - Set the baud rate to 115200 to view the sensor data and confirm that the DHT sensor is functioning correctly.

2. **Access the Web Application**:
   - Open a web browser and navigate to the IP address assigned to the ESP32 (displayed in the Serial Monitor) to access the African Dish Guide web application.

## Conclusion
You have successfully set up the hardware for the African Dish Guide application. Follow the on-screen instructions in the web application to start cooking traditional African dishes with the help of real-time sensor monitoring.
