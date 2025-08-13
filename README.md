# ESP32 JMRI MQTT Client

This project provides an ESP32-based MQTT client for interfacing with JMRI (Java Model Railroad Interface) for model railroad control.

## Features

- **Sensor Feedback Detection**: Monitor up to 4 occupancy sensors
- **Turnout Control**: Control up to 2 turnouts via MQTT commands
- **Signal Control**: Control 3-color traffic signals (red, yellow, green)
- **OTA Updates**: Over-the-air firmware updates via web interface
- **WiFi Configuration**: Web-based WiFi setup interface
- **MQTT Communication**: Bidirectional communication with JMRI
- **Status Monitoring**: Real-time status reporting and monitoring

## Configuration

### 1. Copy Configuration File

Copy the example configuration file to create your own:

```bash
cp config.example.h config.h
```

### 2. Edit Configuration

Open `config.h` and modify the following settings:

#### MQTT Configuration
```cpp
#define MQTT_BROKER "192.168.1.100"  // Your MQTT broker IP address
#define MQTT_PORT 1883                // MQTT broker port
#define MQTT_CLIENT_ID "esp32_jmri_client"
#define MQTT_TOPIC_PREFIX "trains"    // Base topic for MQTT messages
```

#### WiFi Configuration
```cpp
#define DEFAULT_SSID "ESP32_Config"   // SSID for configuration mode
#define DEFAULT_PASSWORD "12345678"    // Password for configuration mode
```

#### Pin Definitions
```cpp
#define SENSOR_PIN_1 4                // Sensor 1 input pin
#define SENSOR_PIN_2 5                // Sensor 2 input pin
#define SENSOR_PIN_3 18               // Sensor 3 input pin
#define SENSOR_PIN_4 19               // Sensor 4 input pin
#define TURNOUT_PIN_1 21              // Turnout 1 control pin
#define TURNOUT_PIN_2 22              // Turnout 2 control pin
#define SIGNAL_PIN_RED 23             // Red signal LED pin
#define SIGNAL_PIN_YELLOW 25          // Yellow signal LED pin
#define SIGNAL_PIN_GREEN 26           // Green signal LED pin
#define STATUS_LED 2                  // Status LED pin
```

### 3. Timing Configuration
```cpp
#define MQTT_RETRY_INTERVAL 5000      // MQTT reconnection retry (5 seconds)
#define STATUS_UPDATE_INTERVAL 10000   // Status updates (10 seconds)
#define WIFI_RECONNECT_INTERVAL 30000 // WiFi reconnection (30 seconds)
#define WIFI_MAX_ATTEMPTS 20          // Max WiFi connection attempts
```

## Hardware Setup

### Required Components
- ESP32 development board
- 4 occupancy sensors (e.g., IR sensors, magnetic sensors)
- 2 turnout motors or servos
- 3 LEDs for traffic signal (red, yellow, green)
- 220Ω resistors for LED current limiting
- Breadboard and jumper wires

### Pin Connections
- **Sensors**: Connect to GPIO 4, 5, 18, 19 (with pull-up resistors)
- **Turnouts**: Connect to GPIO 21, 22 (via relay modules if needed)
- **Signals**: Connect LEDs to GPIO 23, 25, 26 (with 220Ω resistors)
- **Status LED**: Connect to GPIO 2 (built-in LED on most ESP32 boards)

## Installation

### 1. Install Required Libraries
In Arduino IDE, install these libraries:
- `PubSubClient` by Nick O'Leary
- `ArduinoJson` by Benoit Blanchon
- `Preferences` (built into ESP32 core)

### 2. Upload Sketch
1. Open `esp32_jmri_mqtt_client.ino` in Arduino IDE
2. Select your ESP32 board
3. Upload the sketch

### 3. Initial Setup
1. Power on the ESP32
2. Connect to the "ESP32_Config" WiFi network (password: 12345678)
3. Navigate to `http://192.168.4.1`
4. Enter your WiFi credentials
5. The device will connect to your network

## MQTT Topics

The device uses the following MQTT topic structure:
```
trains/{MAC_ADDRESS}/sensors/{sensor_number}/status
trains/{MAC_ADDRESS}/turnouts/{turnout_number}/status
trains/{MAC_ADDRESS}/turnouts/{turnout_number}/control
trains/{MAC_ADDRESS}/signals/{signal_number}/status
trains/{MAC_ADDRESS}/signals/{signal_number}/control
trains/{MAC_ADDRESS}/status
```

### Publishing Commands

#### Control Turnout
```json
// Topic: trains/{MAC}/turnouts/1/control
{
  "position": "thrown"  // or "normal"
}
```

#### Control Signal
```json
// Topic: trains/{MAC}/signals/1/control
{
  "aspect": "red"       // "red", "yellow", or "green"
}
```

### Receiving Status

#### Sensor Status
```json
{
  "sensor": 1,
  "state": "occupied",  // or "clear"
  "timestamp": 1234567890
}
```

#### Turnout Status
```json
{
  "turnout": 1,
  "position": "thrown", // or "normal"
  "timestamp": 1234567890
}
```

#### Signal Status
```json
{
  "signal": 1,
  "aspect": "red",      // "red", "yellow", or "green"
  "timestamp": 1234567890
}
```

## Web Interface

The device provides a web interface at its IP address for:
- WiFi configuration
- Status monitoring
- OTA firmware updates
- Device restart

## Troubleshooting

### Common Issues

1. **WiFi Connection Fails**
   - Check SSID and password in config.h
   - Ensure WiFi network is 2.4GHz (ESP32 doesn't support 5GHz)

2. **MQTT Connection Fails**
   - Verify MQTT broker IP address and port
   - Check if MQTT broker is running and accessible
   - Ensure network allows MQTT traffic (port 1883)

3. **Sensors Not Working**
   - Verify pin connections
   - Check if sensors are active-high or active-low
   - Ensure proper power supply for sensors

4. **OTA Updates Fail**
   - Check WiFi connection stability
   - Ensure sufficient flash memory
   - Verify firmware file is compatible

### Debug Information
Enable Serial Monitor at 115200 baud to see debug information and status messages.

## License

This project is open source. Feel free to modify and distribute according to your needs.

## Support

For issues and questions, please check the troubleshooting section above or create an issue in the project repository.
