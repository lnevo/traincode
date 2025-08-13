#!/bin/bash

echo "=== Setting up Git Repository for TrainCode ==="
echo ""

# Check if git is configured
if [ -z "$(git config --global user.name)" ]; then
    echo "Git user.name not configured. Please set it:"
    echo "git config --global user.name \"Your Name\""
    echo ""
fi

if [ -z "$(git config --global user.email)" ]; then
    echo "Git user.email not configured. Please set it:"
    echo "git config --global user.email \"your.email@example.com\""
    echo ""
fi

echo "Current git status:"
git status

echo ""
echo "=== Next Steps ==="
echo "1. Configure git (if needed):"
echo "   git config --global user.name \"Your Name\""
echo "   git config --global user.email \"your.email@example.com\""
echo ""
echo "2. Create a new repository on GitHub called 'traincode'"
echo "3. Add the remote origin:"
echo "   git remote add origin https://github.com/YOUR_USERNAME/traincode.git"
echo "4. Push to GitHub:"
echo "   git push -u origin main"
echo ""
echo "=== Repository Information ==="
echo "Repository: traincode"
echo "Description: ESP32 JMRI MQTT Client for Model Railroad Control"
echo "Main features: WiFi config, MQTT config, sensor feedback, turnout control, signal control, OTA updates"
echo ""
echo "Files included:"
echo "- esp32_jmri_mqtt_client.ino (main sketch)"
echo "- config.example.h (example configuration)"
echo "- README.md (comprehensive documentation)"
echo "- WIRING_DIAGRAM.md (hardware setup guide)"
echo "- platformio.ini (PlatformIO configuration)"
echo "- .gitignore (excludes build files and user configs)"
echo ""
echo "Note: config.h (your personal configuration) is excluded from git"
echo "Users should copy config.example.h to config.h and modify as needed"
