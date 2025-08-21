/*
 * Example Configuration File for ESP32 JMRI MQTT Client
 * 
 * Copy this file to config.h and modify the values for your setup
 */

#ifndef CONFIG_H
#define CONFIG_H

// Firmware version
#define FIRMWARE_VERSION "4.0.18"

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

// Pin Configuration - DYNAMIC SYSTEM
// All device pins are now configured dynamically through the web interface
// No hardcoded pin definitions are needed

#define STATUS_LED 2       // Status LED pin

// System Device Limits - Adjust for your specific ESP32 board
#define MAX_TURNOUTS 26    // Maximum number of turnouts (all I/O pins)
#define MAX_LIGHTS 10      // Maximum number of lights (limited by electrical considerations)
#define MAX_SENSORS 32     // Maximum number of sensors (all available pins)

// Serial Configuration
#define SERIAL_BAUD_RATE 115200       // Serial communication baud rate

// Timing Configuration - MODIFY IF NEEDED
#define MQTT_RETRY_INTERVAL 5000      // MQTT reconnection retry interval (5 seconds)
#define STATUS_UPDATE_INTERVAL 10000   // Status update interval (10 seconds)
#define WIFI_RECONNECT_INTERVAL 30000 // WiFi reconnection interval (30 seconds)
#define WIFI_MAX_ATTEMPTS 20          // Maximum WiFi connection attempts

#endif // CONFIG_H
