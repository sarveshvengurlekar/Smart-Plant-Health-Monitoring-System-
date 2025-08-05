# Smart-Plant-Health-Monitoring-System


An IoT-based system that monitors plant health parameters in real-time using various sensors and provides insights through the Blynk platform.

![Project Badge](https://img.shields.io/badge/Project-IoT-brightgreen)
![License Badge](https://img.shields.io/badge/License-MIT-blue)

## 📝 Description

The Smart Plant Health Monitoring System is an innovative IoT solution that helps users monitor and maintain their plants' health effectively. The system uses multiple sensors to collect vital plant health parameters and provides real-time monitoring through the Blynk IoT platform.

### Key Features:
- Real-time temperature and humidity monitoring
- Soil moisture level tracking
- Light intensity detection
- LCD display for immediate readings
- Remote monitoring through Blynk mobile app
- Automatic data logging and analysis

## 🛠️ Hardware Requirements

- ESP8266 WiFi Module
- DHT11 Temperature and Humidity Sensor
- Soil Moisture Sensor
- LDR (Light Dependent Resistor)
- 20x4 I2C LCD Display
- Connecting wires
- Power supply

## 📚 Software Requirements

- Arduino IDE
- Required Libraries:
  - ESP8266WiFi
  - BlynkSimpleEsp8266
  - LiquidCrystal_I2C
  - DHT sensor library

## 📋 Pin Configuration

- DHT11 Sensor: D4
- Soil Moisture Sensor: A0
- LDR: D0
- LCD I2C: SDA & SCL pins
- Power: 5V and GND connections

## ⚙️ Setup Instructions

1. **Hardware Setup**
   - Connect all components according to the pin configuration
   - Ensure proper power supply connections

2. **Software Setup**
   - Install Arduino IDE
   - Install required libraries
   - Configure Blynk:
     - Create a new project in Blynk app
     - Get the authentication token
     - Set up the virtual pins (V0-V3)

3. **Configuration**
   - Update the following in the code:
     ```cpp
     char ssid[] = "your_wifi_ssid";
     char password[] = "your_wifi_password";
     #define BLYNK_TEMPLATE_ID "your_template_id"
     #define BLYNK_TEMPLATE_NAME "your_template_name"
     #define BLYNK_AUTH_TOKEN "your_auth_token"
     ```

## 📊 Data Monitoring

The system monitors and displays:
- Temperature (°C and °F)
- Humidity percentage
- Soil moisture percentage
- Light intensity (Bright/Dim)

Data is displayed on both:
- Local 20x4 LCD display
- Blynk mobile app interface

## 🔄 Working

1. System initializes and connects to WiFi
2. Sensors collect data every 3 seconds
3. Data is displayed on LCD screen
4. Values are sent to Blynk cloud
5. Users can monitor values remotely through Blynk app

## 🌟 Features

- **Real-time Monitoring**: Instant access to plant health parameters
- **Dual Display**: Both LCD and mobile app visualization
- **Remote Access**: Monitor plants from anywhere using Blynk app
- **Easy Setup**: Simple configuration and user-friendly interface
- **Comprehensive Data**: Multiple parameters for complete plant health analysis

## 🏆 Recognition

This project received special mention at a hackathon for providing a practical solution to real-life plant care challenges.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👥 Contributors

- [Sarvesh Vengurlekar](https://github.com/sarveshvengurlekar)

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check [issues page](https://github.com/sarveshvengurlekar/Smart-Plant-Health-Monitoring-System-/issues).
