# ESP32 JMRI MQTT Client

An ESP32-based MQTT client for interfacing with JMRI (Java Model Railroad Interface) for model railroad control. This project provides a robust, configurable interface between physical hardware (sensors, turnouts, signals) and JMRI via MQTT.

## Features

### Hardware Interface
- **Sensors**: 4 digital input pins with pull-up resistors
- **Turnouts**: 2 digital output pins for turnout control
- **Signals**: 3-aspect signal support (Red, Yellow, Green)
- **Status LED**: Activity indication

### MQTT Integration
- **Topic Structure**: `/trains/track/[type]/[number]`
  - Sensors: `.../sensor/1` through `.../sensor/4`
  - Turnouts: `.../turnout/1` and `.../turnout/2`
  - Signal: `.../signal/1`
- **Retained Messages**: All state changes are published as retained messages
- **Boot Synchronization**: Reads retained messages on boot to sync with JMRI
- **Feedback Loop Prevention**: Smart message filtering prevents self-triggering
- **Hostname Support**: Supports both IP and mDNS hostnames (e.g., "rpi-jmri.local")

### Web Interface
- **Dark/Light Mode**: Configurable theme with automatic persistence
- **Device Status**: Real-time status display including WiFi and MQTT connection state
- **Device Control Panel**: Interactive control of turnouts and signals
- **Configuration**:
  - WiFi settings
  - MQTT broker settings (IP/hostname, port, client ID)
  - Channel name and topic prefix
- **Firmware Management**:
  - OTA (Over-The-Air) updates
  - Version display
  - Backup/restore configuration
  - Factory reset option
  - Device restart control

### Configuration
- **WiFi**: Supports both station and AP modes
  - Station mode for normal operation
  - AP mode (ESP32_Config_XXXX) for initial setup
- **Persistence**: All settings stored in non-volatile memory
- **Defaults**: Sensible defaults provided in config.h
- **Backup/Restore**: Export/import of all settings

### Reliability Features
- **Auto-Reconnect**: Automatic reconnection for both WiFi and MQTT
- **State Persistence**: Maintains correct state across reboots
- **Error Recovery**: Graceful handling of connection failures
- **Status Monitoring**: Comprehensive status reporting via web interface

## Installation

1. Copy `config.example.h` to `config.h`
2. Modify settings in `config.h` for your environment:
   - WiFi credentials (optional, can be set via web interface)
   - MQTT broker details (optional, can be set via web interface)
   - Pin assignments (if using different GPIO pins)
3. Flash to ESP32
4. Connect to ESP32's AP (ESP32_Config_XXXX)
5. Configure via web interface (http://192.168.4.1)

## Hardware Setup

### Pin Assignments (Default)
- **Sensors**:
  - Sensor 1: GPIO 4
  - Sensor 2: GPIO 5
  - Sensor 3: GPIO 18
  - Sensor 4: GPIO 19
- **Turnouts**:
  - Turnout 1: GPIO 21
  - Turnout 2: GPIO 22
- **Signal**:
  - Red: GPIO 23
  - Yellow: GPIO 25
  - Green: GPIO 26
- **Status LED**: GPIO 2

## MQTT Message Format

### Sensors
- Topic: `/trains/track/sensor/[1-4]`
- States: `ACTIVE` or `INACTIVE`
- Direction: ESP32 → MQTT (read-only)

### Turnouts
- Topic: `/trains/track/turnout/[1-2]`
- States: `THROWN` or `CLOSED`
- Direction: Bidirectional

### Signals
- Topic: `/trains/track/signal/1`
- States: `RED`, `YELLOW`, or `GREEN`
- Direction: Bidirectional

## Behavior Notes

### Sensor Operation
- Sensors are "truth sources" - they report actual physical state
- Only publish when physical state differs from commanded state
- Use retained messages to maintain state across restarts

### Turnout Operation
- Accepts commands from MQTT
- Publishes state changes from physical inputs
- Maintains state across power cycles via retained messages

### Signal Operation
- Three-aspect signal control
- Visual feedback via web interface
- State maintained via retained messages

### Web Interface
- Real-time updates without page refresh
- Dark/light mode persistence
- Automatic reconnection handling
- Mobile-friendly responsive design

## Version History

### 3.0.0
- Added mDNS hostname support for MQTT broker
- Added MAC address-based unique identifiers
- Improved backup/restore functionality
- Enhanced web interface with better button grouping
- Fixed MQTT topic structure
- Added configuration persistence improvements

## License

This project is open source and available under the MIT License.