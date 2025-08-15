/*
 * Example Configuration File for ESP32 JMRI MQTT Client
 * 
 * Copy this file to config.h and modify the values for your setup
 */

#ifndef CONFIG_H
#define CONFIG_H

// Firmware version
#define FIRMWARE_VERSION "3.1.0"

// Device configuration
#define DEVICE_NAME "ESP32_JMRI_Client"

// MQTT Configuration - MODIFY THESE FOR YOUR SETUP
#define MQTT_BROKER "192.168.1.100"  // Change to your MQTT broker IP address or hostname (e.g., "rpi-jmri.local")
#define MQTT_PORT 1883               // MQTT broker port (usually 1883 for non-SSL)
#define MQTT_CLIENT_ID "esp32_jmri_client"
#define MQTT_CHANNEL_NAME "/trains/" // Channel name prefix (matches JMRI defaults)
#define MQTT_TOPIC_PREFIX "track"    // Base topic prefix for MQTT messages

// WiFi Configuration - MODIFY THESE FOR YOUR SETUP
#define DEFAULT_SSID "ESP32_Config"   // SSID for configuration mode
#define DEFAULT_PASSWORD "12345678"    // Password for configuration mode

// Pin Definitions - MODIFY IF USING DIFFERENT GPIO PINS
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

// Serial Configuration
#define SERIAL_BAUD_RATE 115200       // Serial communication baud rate

// Timing Configuration - MODIFY IF NEEDED
#define MQTT_RETRY_INTERVAL 5000      // MQTT reconnection retry interval (5 seconds)
#define STATUS_UPDATE_INTERVAL 10000   // Status update interval (10 seconds)
#define WIFI_RECONNECT_INTERVAL 30000 // WiFi reconnection interval (30 seconds)
#define WIFI_MAX_ATTEMPTS 20          // Maximum WiFi connection attempts

#endif // CONFIG_H
