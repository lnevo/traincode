/*
 * Example Configuration File for ESP32 JMRI MQTT Client
 * 
 * Copy this file to config.h and modify the values for your setup
 */

#ifndef CONFIG_H
#define CONFIG_H

// Firmware version
#define FIRMWARE_VERSION "4.0.6"

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

// Pin definitions
#define TURNOUT_PIN_1 2    // Turnout 1 control pin
#define TURNOUT_PIN_2 4    // Turnout 2 control pin

// Individual Light pins (6 lights)
#define LIGHT_PIN_1 5      // Light 1
#define LIGHT_PIN_2 18     // Light 2
#define LIGHT_PIN_3 19     // Light 3
#define LIGHT_PIN_4 21     // Light 4
#define LIGHT_PIN_5 22     // Light 5
#define LIGHT_PIN_6 23     // Light 6

// Sensor pins (track occupancy and turnout feedback)
#define SENSOR_PIN_1 25    // Sensor 1 (track occupancy)
#define SENSOR_PIN_2 26    // Sensor 2 (turnout feedback)
#define SENSOR_PIN_3 27    // Sensor 3 (additional track occupancy)
#define SENSOR_PIN_4 32    // Sensor 4 (additional track occupancy)

#define STATUS_LED 2       // Status LED (shared with TURNOUT_PIN_1)

// Serial Configuration
#define SERIAL_BAUD_RATE 115200       // Serial communication baud rate

// Timing Configuration - MODIFY IF NEEDED
#define MQTT_RETRY_INTERVAL 5000      // MQTT reconnection retry interval (5 seconds)
#define STATUS_UPDATE_INTERVAL 10000   // Status update interval (10 seconds)
#define WIFI_RECONNECT_INTERVAL 30000 // WiFi reconnection interval (30 seconds)
#define WIFI_MAX_ATTEMPTS 20          // Maximum WiFi connection attempts

#endif // CONFIG_H
