# ESP32 JMRI MQTT Client - Wiring Diagram

This document provides detailed wiring information for connecting the ESP32 to sensors, turnouts, and signals.

## Power Supply

```
Power Supply (5V or 3.3V)
├── VIN (ESP32) - Main power input
├── 3.3V (ESP32) - 3.3V output for sensors
├── GND (ESP32) - Common ground
└── GND (Power Supply) - Common ground
```

## Sensor Connections

### Sensor 1 (GPIO 4)
```
Sensor 1 (e.g., IR sensor, magnetic sensor, contact switch)
├── VCC → 3.3V (ESP32)
├── GND → GND (ESP32)
└── Signal → GPIO 4 (ESP32)
```

### Sensor 2 (GPIO 5)
```
Sensor 2 (e.g., IR sensor, magnetic sensor, contact switch)
├── VCC → 3.3V (ESP32)
├── GND → GND (ESP32)
└── Signal → GPIO 5 (ESP32)
```

### Sensor 3 (GPIO 18)
```
Sensor 3 (e.g., IR sensor, magnetic sensor, contact switch)
├── VCC → 3.3V (ESP32)
├── GND → GND (ESP32)
└── Signal → GPIO 18 (ESP32)
```

### Sensor 4 (GPIO 19)
```
Sensor 4 (e.g., IR sensor, magnetic sensor, contact switch)
├── VCC → 3.3V (ESP32)
├── GND → GND (ESP32)
└── Signal → GPIO 19 (ESP32)
```

## Turnout Control Connections

### Turnout 1 (GPIO 21)
```
Turnout 1 Control
├── VCC → 5V (Power Supply) - For relay or motor
├── GND → GND (Power Supply)
└── Control → GPIO 21 (ESP32) via relay or transistor
```

**Note**: For turnout control, you may need:
- Relay module (recommended for high-power motors)
- Transistor circuit (for low-power applications)
- Motor driver board (for servo motors)

### Turnout 2 (GPIO 22)
```
Turnout 2 Control
├── VCC → 5V (Power Supply) - For relay or motor
├── GND → GND (Power Supply)
└── Control → GPIO 22 (ESP32) via relay or transistor
```

## Signal Control Connections

### Signal Red (GPIO 23)
```
Signal Red LED
├── Anode (+) → GPIO 23 (ESP32) via current-limiting resistor (220Ω)
└── Cathode (-) → GND (ESP32)
```

### Signal Yellow (GPIO 25)
```
Signal Yellow LED
├── Anode (+) → GPIO 25 (ESP32) via current-limiting resistor (220Ω)
└── Cathode (-) → GND (ESP32)
```

### Signal Green (GPIO 26)
```
Signal Green LED
├── Anode (+) → GPIO 26 (ESP32) via current-limiting resistor (220Ω)
└── Cathode (-) → GND (ESP32)
```

## Status LED

```
Status LED (Built-in on most ESP32 boards)
├── Anode (+) → GPIO 2 (ESP32) - Usually built-in
└── Cathode (-) → GND (ESP32) - Usually built-in
```

## Complete Wiring Diagram

```
Power Supply (5V/3.3V)
│
├── ESP32
│   ├── VIN → 5V (Power Supply)
│   ├── 3.3V → Sensors VCC
│   ├── GND → Common Ground
│   │
│   ├── GPIO 4 → Sensor 1 Signal
│   ├── GPIO 5 → Sensor 2 Signal
│   ├── GPIO 18 → Sensor 3 Signal
│   ├── GPIO 19 → Sensor 4 Signal
│   ├── GPIO 21 → Turnout 1 Control
│   ├── GPIO 22 → Turnout 2 Control
│   ├── GPIO 23 → Signal Red (via 220Ω resistor)
│   ├── GPIO 25 → Signal Yellow (via 220Ω resistor)
│   ├── GPIO 26 → Signal Green (via 220Ω resistor)
│   └── GPIO 2 → Status LED (built-in)
│
├── Sensors (4x)
│   ├── VCC → 3.3V (ESP32)
│   ├── GND → GND (ESP32)
│   └── Signal → Respective GPIO pins
│
├── Turnouts (2x)
│   ├── VCC → 5V (Power Supply)
│   ├── GND → GND (Power Supply)
│   └── Control → Respective GPIO pins (via relay/transistor)
│
└── Signals (3x LEDs)
    ├── Anode → Respective GPIO pins (via 220Ω resistors)
    └── Cathode → GND (ESP32)
```

## Component Recommendations

### Sensors
- **IR Sensors**: TCRT5000, QRE1113 (good for detecting train presence)
- **Magnetic Sensors**: Hall effect sensors (good for magnetic detection)
- **Contact Switches**: Micro switches (good for mechanical detection)

### Turnout Control
- **Relay Module**: 5V relay module with optocoupler isolation
- **Transistor**: 2N2222 or similar for low-power applications
- **Motor Driver**: L298N for DC motors, PCA9685 for servo motors

### Signal LEDs
- **Standard LEDs**: 3mm or 5mm LEDs with appropriate current rating
- **Current Limiting**: 220Ω resistors (for 3.3V operation)
- **Brightness**: High-brightness LEDs for good visibility

### Power Supply
- **Voltage**: 5V for relays/motors, 3.3V for sensors
- **Current**: Minimum 1A for basic setup, 2A+ for multiple motors
- **Regulation**: Use regulated power supply for stable operation

## Safety Considerations

1. **Voltage Isolation**: Use optocoupler relays for high-voltage turnout control
2. **Current Limiting**: Always use current-limiting resistors for LEDs
3. **Ground Connection**: Ensure all components share a common ground
4. **Power Rating**: Verify components can handle the required power
5. **Reverse Protection**: Consider adding reverse polarity protection diodes

## Testing the Connections

1. **Power Test**: Verify ESP32 powers up and Serial Monitor shows startup messages
2. **Sensor Test**: Check Serial Monitor for sensor state changes
3. **Turnout Test**: Use MQTT commands to test turnout control
4. **Signal Test**: Use MQTT commands to test signal control
5. **Status Test**: Verify status LED indicates proper operation

## Troubleshooting Tips

1. **No Power**: Check power supply voltage and connections
2. **Sensors Not Working**: Verify sensor power and signal connections
3. **Turnouts Not Moving**: Check power supply and control signal connections
4. **Signals Not Lighting**: Verify LED polarity and resistor values
5. **Communication Issues**: Check WiFi and MQTT broker connectivity
