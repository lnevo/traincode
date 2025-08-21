#ifndef HTML_CONTENT_H
#define HTML_CONTENT_H

// HTML Content for the ESP32 JMRI MQTT Client Web Interface

// Main page HTML with embedded CSS and JavaScript
const char* getMainPageHTML() {
  static const char* html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate">
    <meta http-equiv="Pragma" content="no-cache">
    <meta http-equiv="Expires" content="0">
    <title>ESP32 JMRI Client</title>
    <style>
        :root {
            --bg-primary: #ffffff;
            --bg-secondary: #f8f9fa;
            --bg-tertiary: #f5f5f5;
            --text-primary: #333333;
            --text-secondary: #666666;
            --text-muted: #999999;
            --border-color: #dee2e6;
            --shadow: 0 2px 10px rgba(0,0,0,0.1);
            --accent-primary: #007bff;
            --accent-hover: #0056b3;
            --success: #28a745;
            --danger: #dc3545;
            --warning: #ffc107;
            --info: #17a2b8;
        }

        [data-theme='dark'] {
            --bg-primary: #1a1a1a;
            --bg-secondary: #2d2d2d;
            --bg-tertiary: #333333;
            --text-primary: #ffffff;
            --text-secondary: #cccccc;
            --text-muted: #999999;
            --border-color: #444444;
            --shadow: 0 2px 10px rgba(0,0,0,0.3);
            --accent-primary: #0d6efd;
            --accent-hover: #0b5ed7;
        }

        * {
            box-sizing: border-box;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 0;
            background-color: var(--bg-tertiary);
            color: var(--text-primary);
            transition: all 0.3s ease;
        }

        .header {
            background: var(--bg-primary);
            border-bottom: 2px solid var(--border-color);
            padding: 20px;
            box-shadow: var(--shadow);
        }

        .header-content {
            max-width: 1200px;
            margin: 0 auto;
            display: flex;
            justify-content: space-between;
            align-items: center;
            flex-wrap: wrap;
        }

        .device-info h1 {
            margin: 0;
            color: var(--text-primary);
            font-size: 1.8em;
        }

        .device-status {
            text-align: right;
            font-size: 0.9em;
            color: var(--text-secondary);
        }

        .device-status div {
            margin: 2px 0;
        }

        .status-badge {
            display: inline-block;
            padding: 2px 8px;
            border-radius: 12px;
            font-size: 0.8em;
            margin-left: 5px;
        }

        .status-connected {
            background: #d4edda;
            color: #155724;
        }

        .status-disconnected {
            background: #f8d7da;
            color: #721c24;
        }

        .theme-toggle {
            background: var(--accent-primary);
            color: white;
            border: none;
            padding: 6px 12px;
            border-radius: 15px;
            cursor: pointer;
            font-size: 0.8em;
            transition: all 0.3s;
            margin-top: 15px;
        }

        .theme-toggle:hover {
            background: var(--accent-hover);
        }

        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
        }

        .tab-nav {
            display: flex;
            background: var(--bg-primary);
            border-radius: 8px;
            overflow: hidden;
            box-shadow: var(--shadow);
            margin-bottom: 20px;
        }

        .tab-btn {
            flex: 1;
            padding: 15px 20px;
            background: var(--bg-secondary);
            border: none;
            color: var(--text-secondary);
            cursor: pointer;
            font-size: 1em;
            transition: all 0.3s;
            border-right: 1px solid var(--border-color);
        }

        .tab-btn:last-child {
            border-right: none;
        }

        .tab-btn.active {
            background: var(--accent-primary);
            color: white;
        }

        .tab-btn:hover:not(.active) {
            background: var(--bg-tertiary);
        }

        .tab-content {
            display: none;
            background: var(--bg-primary);
            padding: 20px;
            border-radius: 8px;
            box-shadow: var(--shadow);
        }

        .tab-content.active {
            display: block;
        }

        .section {
            margin: 20px 0;
        }

        .form-group {
            margin-bottom: 15px;
        }

        label {
            display: block;
            margin-bottom: 5px;
            font-weight: 600;
            color: var(--text-primary);
        }

        input[type=text], input[type=password] {
            width: 100%;
            padding: 10px;
            border: 2px solid var(--border-color);
            border-radius: 6px;
            background: var(--bg-secondary);
            color: var(--text-primary);
            font-size: 1em;
            transition: border-color 0.3s;
        }

        input:focus {
            outline: none;
            border-color: var(--accent-primary);
        }

        button {
            background: var(--accent-primary);
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 6px;
            cursor: pointer;
            font-size: 1em;
            transition: all 0.3s;
        }

        button:hover {
            background: var(--accent-hover);
            transform: translateY(-1px);
        }

        .device-table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 10px;
            background: var(--bg-primary);
            border-radius: 8px;
            overflow: hidden;
            box-shadow: var(--shadow);
        }

        .device-table th, .device-table td {
            padding: 12px;
            text-align: left;
            border-bottom: 1px solid var(--border-color);
        }

        .device-table th {
            background: var(--bg-secondary);
            font-weight: 600;
            color: var(--text-primary);
        }

        .device-table tr:hover {
            background: var(--bg-secondary);
        }

        /* Button styling */
        .control-btn {
            padding: 8px 16px;
            margin: 2px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 0.9em;
            transition: all 0.3s ease;
        }
        
        .btn-active {
            background: var(--accent-primary);
            color: white;
        }
        
        .btn-inactive {
            background: var(--bg-secondary);
            color: var(--text-secondary);
        }
        
        .btn-green-active {
            background: var(--success);
            color: white;
        }
        
        .btn-red-active {
            background: var(--error);
            color: white;
        }
        
        .btn-green {
            background: var(--success);
            color: white;
        }

        .btn-red {
            background: #dc3545;
            color: white;
            opacity: 0.5;
        }

        .btn-red-active {
            background: #dc3545;
            color: white;
            opacity: 1.0;
            font-weight: bold;
        }

        .btn-yellow {
            background: #ffc107;
            color: white;
            opacity: 0.5;
        }

        .btn-yellow-active {
            background: #ffc107;
            color: white;
            opacity: 1.0;
            font-weight: bold;
        }

        .btn-green {
            background: #28a745;
            color: white;
            opacity: 0.5;
        }

        .btn-green-active {
            background: #28a745;
            color: white;
            opacity: 1.0;
            font-weight: bold;
        }

        .btn-inactive:hover {
            opacity: 1.0 !important;
            background: #dc3545 !important;
        }

        .btn-red:hover {
            opacity: 1.0 !important;
            background: #dc3545 !important;
        }

        .btn-yellow:hover {
            opacity: 1.0 !important;
            background: #ffc107 !important;
        }

        .btn-green:hover {
            opacity: 1.0 !important;
            background: #28a745 !important;
        }

        .btn-active:hover {
            background: #28a745 !important;
        }

        .btn-red-active:hover {
            background: #dc3545 !important;
        }

        .btn-yellow-active:hover {
            background: #ffc107 !important;
        }

        .btn-green-active:hover {
            background: #28a745 !important;
        }

        /* Device label styling */
        .device-label {
            font-size: 0.9em;
            text-align: center;
            transition: all 0.3s ease;
        }
        .device-label:focus {
            outline: none;
            border-color: var(--accent-primary) !important;
            box-shadow: 0 0 0 2px rgba(13, 110, 253, 0.25);
        }
        
        /* Device ID and Pin styling */
        .device-id, .device-pin {
            font-size: 0.9em;
            text-align: center;
            transition: all 0.3s ease;
        }
        .device-id:focus, .device-pin:focus {
            outline: none;
            border-color: var(--accent-primary) !important;
            box-shadow: 0 0 0 2px rgba(13, 110, 253, 0.25);
        }
        
        /* Device Type styling */
        .device-type {
            font-size: 0.9em;
            text-align: center;
            transition: all 0.3s ease;
        }
        .device-type:focus {
            outline: none;
            border-color: var(--accent-primary) !important;
            box-shadow: 0 0 0 2px rgba(13, 110, 253, 0.25);
        }
        
        /* Status display */
        .status-display {
            background: var(--bg-secondary);
            border-radius: 8px;
            padding: 20px;
            border: 1px solid var(--border-color);
        }

        .status-json {
            font-family: 'Courier New', monospace;
            font-size: 0.9em;
            white-space: pre-wrap;
            word-wrap: break-word;
            background: var(--bg-tertiary);
            padding: 15px;
            border-radius: 6px;
            max-height: 400px;
            overflow-y: auto;
            border: 1px solid var(--border-color);
        }

        .utility-classes {
            text-align: center;
            margin-bottom: 1rem;
            margin-top: 1rem;
        }

        .button-group {
            display: flex;
            gap: 10px;
            margin-bottom: 20px;
        }

        .button-group .button {
            flex: 1;
        }

        .upload-form {
            margin: 20px 0;
        }

        .progress {
            width: 100%;
            background: var(--bg-tertiary);
            border-radius: 4px;
            margin: 10px 0;
            height: 20px;
            overflow: hidden;
        }

        .progress-bar {
            height: 100%;
            background: var(--accent-primary);
            border-radius: 4px;
            width: 0%;
            transition: width 0.3s;
        }

        @media (max-width: 768px) {
            .header-content {
                flex-direction: column;
                text-align: center;
            }

            .device-status {
                text-align: center;
                margin-top: 10px;
            }

            .tab-nav {
                flex-direction: column;
            }
        }
    </style>
</head>
<body>
    <div class="header">
        <div class="header-content">
            <div class="device-info">
                <h1>ESP32 JMRI Client</h1>
                <p style="margin:5px 0 0 0;color:var(--text-secondary);font-size:0.9em;">Client ID: CLIENT_ID_PLACEHOLDER</p>
                <p style="margin:2px 0 0 0;color:var(--text-secondary);font-size:0.8em;">Firmware: FIRMWARE_VERSION_PLACEHOLDER</p>
            </div>
            <div class="device-status">
                <div>IP: IP_ADDRESS_PLACEHOLDER
                    WIFI_STATUS_PLACEHOLDER
                </div>
                <div>MQTT: MQTT_BROKER_PLACEHOLDER
                    MQTT_STATUS_PLACEHOLDER
                </div>
                <div>Hostname: HOSTNAME_PLACEHOLDER
                </div>
                <button class="theme-toggle" onclick="toggleTheme()">Light Mode</button>
            </div>
        </div>
    </div>

    <div class="container">
        <div class="tab-nav">
            <button class="tab-btn active" onclick="showTab('main', event)">Device Status</button>
            <button class="tab-btn" onclick="showTab('setup', event)">Setup</button>
            <button class="tab-btn" onclick="showTab('firmware', event)">Firmware</button>
        </div>

        <div id="main-tab" class="tab-content active">
            <div class="section">
                <h2>Device Control Panel</h2>
                <table class="device-table">
                    <thead>
                        <tr>
                            <th>Type</th>
                            <th>ID</th>
                            <th>Pin</th>
                            <th>Capabilities</th>
                            <th>State</th>
                            <th>Label</th>
                            <th>Control</th>
                        </tr>
                    </thead>
                    <tbody id="device-table-body">
                        <tr><td colspan="7" style="text-align:center;color:var(--text-secondary);">Loading device status...</td></tr>
                    </tbody>
                </table>
                <div style="text-align: left; margin-top: 20px;">
                    <button id="saveDeviceSettings" style="background: var(--accent-primary); color: white; padding: 12px 24px; border: none; border-radius: 6px; cursor: pointer; font-size: 1em; transition: all 0.3s;">Save Device Settings</button>
                </div>
            </div>

            <div class="section">
                <h2>System Status</h2>
                <div class="status-display">
                    <div id="status"></div>
                    <div class="button-group utility-classes">
                        <button onclick="checkStatus()">Refresh Status JSON</button>
                    </div>
                </div>
            </div>
        </div>

        <div id="setup-tab" class="tab-content">
            <div class="section">
                <h2>WiFi Configuration</h2>
                <form id="wifiForm">
                    <div class="form-group">
                        <label for="ssid">WiFi SSID:</label>
                        <input type="text" id="ssid" name="ssid" value="WIFI_SSID_PLACEHOLDER" required>
                    </div>
                    <div class="form-group">
                        <label for="password">WiFi Password:</label>
                        <input type="password" id="password" name="password" value="WIFI_PASSWORD_PLACEHOLDER" required>
                    </div>
                    <button type="submit">Update WiFi</button>
                </form>
            </div>

            <div class="section">
                <h2>MQTT Configuration</h2>
                <form id="mqttForm">
                    <div class="form-group">
                        <label for="mqtt_broker">MQTT Broker IP:</label>
                        <input type="text" id="mqtt_broker" name="mqtt_broker" value="MQTT_BROKER_PLACEHOLDER" required>
                    </div>
                    <div class="form-group">
                        <label for="mqtt_port">MQTT Port:</label>
                        <input type="text" id="mqtt_port" name="mqtt_port" value="MQTT_PORT_PLACEHOLDER" required>
                    </div>
                    <div class="form-group">
                        <label for="mqtt_client_id">Client ID:</label>
                        <input type="text" id="mqtt_client_id" name="mqtt_client_id" value="MQTT_CLIENT_ID_PLACEHOLDER" required>
                    </div>
                    <div class="form-group">
                        <label for="mqtt_channel_name">Channel Name:</label>
                        <input type="text" id="mqtt_channel_name" name="mqtt_channel_name" value="MQTT_CHANNEL_NAME_PLACEHOLDER" required>
                    </div>
                    <div class="form-group">
                        <label for="mqtt_topic_prefix">Topic Prefix:</label>
                        <input type="text" id="mqtt_topic_prefix" name="mqtt_topic_prefix" value="MQTT_TOPIC_PREFIX_PLACEHOLDER" required>
                    </div>
                    <button type="submit">Update MQTT</button>
                </form>
            </div>
        </div>

        <div id="firmware-tab" class="tab-content">
            <div class="section">
                <h2>Firmware Management</h2>
                <p id="firmware-version" style="color:var(--text-secondary);margin-bottom:20px;">Current Version: FIRMWARE_VERSION_PLACEHOLDER</p>

                <div class="section">
                    <h3>Upload New Firmware</h3>
                    <div class="upload-form">
                        <input type="file" id="firmware" accept=".bin" onchange="validateFile(this)" style="width:100%;padding:10px;margin:10px 0;border:2px dashed var(--border-color);border-radius:4px;background:var(--bg-secondary);color:var(--text-primary);">
                        <p style="color:var(--text-secondary);font-size:0.9em;margin:5px 0;">Note: Upload the compiled .bin file from Arduino IDE (Sketch > Export Compiled Binary). Do not use .ino.merged.bin files.</p>
                        <div style="display:flex;gap:10px;">
                            <button onclick="uploadFirmware()" id="uploadBtn" disabled style="flex:1;margin:10px 0;">Upload Firmware</button>
                            <button onclick="cancelUpload()" id="cancelBtn" disabled style="background:var(--danger);flex:0 0 100px;margin:10px 0;">Cancel</button>
                        </div>
                    </div>
                    <div class="progress">
                        <div class="progress-bar" id="progressBar"></div>
                    </div>
                    <div id="uploadStatus"></div>
                </div>

                <div class="section">
                    <h3>Device Management</h3>
                    <div class="button-group">
                        <button onclick="restartDevice()" style="background:var(--accent-primary);">Restart Device</button>
                        <span style="width:20px;"></span>
                        <button onclick="downloadBackup()" style="background:var(--accent-primary);">Download Backup</button>
                        <button onclick="restoreConfig()" id="restoreBtn" disabled style="background:var(--accent-primary);">Restore Configuration</button>
                        <span style="width:20px;"></span>
                        <button onclick="resetSavedVariables()" style="background:var(--danger);">Reset Saved Variables</button>
                    </div>
                    <div class="upload-form">
                        <input type="file" id="configFile" accept=".json" onchange="validateConfigFile(this)" style="width:100%;padding:10px;margin:10px 0;border:2px dashed var(--border-color);border-radius:4px;background:var(--bg-secondary);color:var(--text-primary);">
                    </div>
                    <p style="color:var(--text-secondary);font-size:0.9em;margin-top:10px;">Backup includes all WiFi, MQTT, and device settings. Reset will clear all saved settings. Device will restart after restore or reset.</p>
                </div>
            </div>
        </div>
    </div>

    <script>
        let currentTheme = localStorage.getItem('theme') || 'dark';
        let activeTab = localStorage.getItem('activeTab') || 'main';
        let currentUpload = null;
        let versionPolling = false;

        // Initialize theme from localStorage (default to dark)
        const savedTheme = localStorage.getItem('theme') || 'dark';
        document.body.setAttribute('data-theme', savedTheme);
        document.querySelector('.theme-toggle').textContent = savedTheme === 'dark' ? 'Light Mode' : 'Dark Mode';
        
        // Wait for DOM to be fully ready before setting up tabs
        document.addEventListener('DOMContentLoaded', function() {
            // Set the first tab as active by default
            const firstTabBtn = document.querySelector('.tab-btn');
            if (firstTabBtn) {
                firstTabBtn.classList.add('active');
                // Also show the main tab content
                const mainTab = document.getElementById('main-tab');
                if (mainTab) {
                    mainTab.classList.add('active');
                }
            }
        });
        
        // Auto-refresh functionality
        let lastHash = '';
        let isUpdating = false;
        
        function checkChanges() {
            if (isUpdating) return; // Prevent multiple simultaneous requests
            isUpdating = true;
            
            console.log('Fetching status from /status endpoint...');
            fetch('/status').then(r => {
                console.log('Response status:', r.status, 'ok:', r.ok);
                if (!r.ok) {
                    throw new Error('Server responded with status: ' + r.status);
                }
                return r.json();
            }).then(d => {
                console.log('Status data received:', d);
                let h = '';
                if(d.sensor_states) {
                    d.sensor_states.forEach(s => h += s.state);
                    console.log('Sensor states:', d.sensor_states.map(s => s.state));
                }
                if(d.turnout_states) {
                    d.turnout_states.forEach(t => h += t.position);
                    console.log('Turnout states:', d.turnout_states.map(t => t.position));
                }
                // Hash calculation for lights - add individual light states
                if(d.lights) {
                    d.lights.forEach(l => h += l.state);
                    console.log('Light states:', d.lights.map(l => l.state));
                }
                console.log('Status check - Hash:', h, 'Last hash:', lastHash);
                if(lastHash && lastHash !== h) {
                    console.log('Status changed, updating device table');
                    updateDeviceTable(d);
                } else if (!lastHash) {
                    console.log('First status load, updating device table');
                    updateDeviceTable(d);
                } else {
                    console.log('No status change detected');
                }
                lastHash = h;
                isUpdating = false;
            }).catch((error) => {
                console.log('Status check failed:', error);
                isUpdating = false;
                // Show error in the table
                const table = document.getElementById('device-table-body');
                if (table) {
                    table.innerHTML = '<tr><td colspan="6" style="text-align:center;color:var(--danger);">Error loading status: ' + error.message + '</td></tr>';
                }
            });
        }
        
        // Load initial status immediately
        console.log('Page loaded, attempting to load initial status...');
        checkChanges();
        
        // Load configuration for form fields
        loadConfiguration();
        
        // Set up auto-refresh interval (more efficient than 3 seconds)
        setInterval(checkChanges, 2000); // Check every 2 seconds for better responsiveness
        
        // Fallback tab setup in case DOMContentLoaded doesn't fire
        setTimeout(() => {
            const firstTabBtn = document.querySelector('.tab-btn');
            if (firstTabBtn && !firstTabBtn.classList.contains('active')) {
                firstTabBtn.classList.add('active');
                const mainTab = document.getElementById('main-tab');
                if (mainTab) {
                    mainTab.classList.add('active');
                }
            }
        }, 100);
        
        // Enhanced device table update function - simplified version
        function updateDeviceTable(data) {
            console.log('Updating device table with new data');
            console.log('Data received:', data);
            
            const table = document.getElementById('device-table-body');
            if (!table) {
                console.log('Device table not found, doing full reload');
                location.reload();
                return;
            }
            let tableHtml = '';
            
                            // Add sensors
                if (data.sensor_states) {
                    data.sensor_states.forEach(function(sensor, i) {
                        tableHtml += '<tr data-device-type="sensor" data-device-num="' + (i + 1) + '" data-pin="' + sensor.pin + '">';
                        tableHtml += '<td><select class="device-type" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"><option value="unused">Unused</option><option value="sensor" selected>Sensor</option><option value="turnout">Turnout</option><option value="light">Light</option></select></td>';
                        tableHtml += '<td><input type="number" class="device-id" value="' + (sensor.id || (i + 1)) + '" min="1" max="99" style="width: 60px; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary); text-align: center;"></td>';
                        tableHtml += '<td>GPIO' + sensor.pin + '</td>';
                        tableHtml += '<td>Input Only</td>';
                        tableHtml += '<td>' + sensor.state + '</td>';
                        tableHtml += '<td><input type="text" class="device-label" value="' + (sensor.label || 'Sensor ' + (i + 1)) + '" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"></td>';
                        tableHtml += '<td><button disabled>' + sensor.state + '</button></td>';
                        tableHtml += '</tr>';
                    });
                }
            
                            // Add turnouts
                if (data.turnout_states) {
                    data.turnout_states.forEach(function(turnout, i) {
                        tableHtml += '<tr data-device-type="turnout" data-device-num="' + (i + 1) + '" data-pin="' + turnout.pin + '">';
                        tableHtml += '<td><select class="device-type" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"><option value="unused">Unused</option><option value="sensor">Sensor</option><option value="turnout" selected>Turnout</option><option value="light">Light</option></select></td>';
                        tableHtml += '<td><input type="number" class="device-id" value="' + (turnout.id || (i + 1)) + '" min="1" max="99" style="width: 60px; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary); text-align: center;"></td>';
                        tableHtml += '<td>GPIO' + turnout.pin + '</td>';
                        tableHtml += '<td>Output Only</td>';
                        tableHtml += '<td>' + turnout.position + '</td>';
                        tableHtml += '<td><input type="text" class="device-label" value="' + (turnout.label || 'Turnout ' + (i + 1)) + '" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"></td>';
                        tableHtml += '<td><button onclick="controlTurnout(' + (i + 1) + ')">' + turnout.position + '</button></td>';
                        tableHtml += '</tr>';
                    });
                }
            
                            // Add lights
                if (data.lights) {
                    data.lights.forEach(function(light, i) {
                        tableHtml += '<tr data-device-type="light" data-device-num="' + (i + 1) + '" data-pin="' + light.pin + '">';
                        tableHtml += '<td><select class="device-type" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"><option value="unused">Unused</option><option value="sensor">Sensor</option><option value="turnout">Turnout</option><option value="light" selected>Light</option></select></td>';
                        tableHtml += '<td><input type="number" class="device-id" value="' + (light.id || (i + 1)) + '" min="1" max="99" style="width: 60px; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary); text-align: center;"></td>';
                        tableHtml += '<td>GPIO' + light.pin + '</td>';
                        tableHtml += '<td>Output + PWM</td>';
                        tableHtml += '<td>' + light.state + '</td>';
                        tableHtml += '<td><input type="text" class="device-label" value="' + (light.label || 'Light ' + (i + 1)) + '" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"></td>';
                        tableHtml += '<td><button onclick="controlLight(' + (i + 1) + ')">' + light.state + '</button></td>';
                        tableHtml += '</tr>';
                    });
                }
            
            // Add unused pins at the bottom (sorted by GPIO)
            if (data.all_pins) {
                // Get list of used pins for comparison
                const usedPins = new Set();
                
                if (data.sensor_states) {
                    data.sensor_states.forEach(sensor => {
                        if (sensor.pin && sensor.pin !== 'N/A') {
                            usedPins.add(parseInt(sensor.pin));
                        }
                    });
                }
                
                if (data.turnout_states) {
                    data.turnout_states.forEach(turnout => {
                        if (turnout.pin && turnout.pin !== 'N/A') {
                            usedPins.add(parseInt(turnout.pin));
                        }
                    });
                }
                
                if (data.lights) {
                    data.lights.forEach(light => {
                        if (light.pin && light.pin !== 'N/A') {
                            usedPins.add(parseInt(light.pin));
                        }
                    });
                }
                
                // Filter and sort unused pins
                const unusedPins = data.all_pins
                    .filter(pin => !usedPins.has(pin.pin) && pin.device_type === 'unused')
                    .sort((a, b) => a.pin - b.pin);
                
                // Add unused pins to table
                unusedPins.forEach(function(pin) {
                    const capabilities = pin.description || 'I/O';
                    tableHtml += '<tr data-device-type="unused" data-device-num="0" data-pin="' + pin.pin + '" style="opacity: 0.6;">';
                    tableHtml += '<td><select class="device-type" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"><option value="unused">Unused</option><option value="sensor">Sensor</option><option value="turnout">Turnout</option><option value="light">Light</option></select></td>';
                    tableHtml += '<td><input type="number" class="device-id" value="" placeholder="ID" min="1" max="99" style="width: 60px; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary); text-align: center;"></td>';
                    tableHtml += '<td>GPIO' + pin.pin + '</td>';
                    tableHtml += '<td>' + capabilities + '</td>';
                    tableHtml += '<td>Available</td>';
                    tableHtml += '<td><input type="text" class="device-label" value="" placeholder="Enter label" style="width: 100%; padding: 4px; border: 1px solid var(--border-color); border-radius: 3px; background: var(--bg-primary); color: var(--text-primary);"></td>';
                    tableHtml += '<td><span style="color: var(--text-muted);">Available</span></td>';
                    tableHtml += '</tr>';
                });
            }
            
            table.innerHTML = tableHtml;
            console.log('Device table updated successfully');
        }
        
        const savedTab = localStorage.getItem('activeTab');
        if (savedTab) {
            setTimeout(() => {
                showTab(savedTab);
                localStorage.removeItem('activeTab');
            }, 200);
        }

        // Theme toggle function
        function toggleTheme() {
            const body = document.body;
            const isDark = body.getAttribute('data-theme') === 'dark';
            body.setAttribute('data-theme', isDark ? 'light' : 'dark');
            const btn = document.querySelector('.theme-toggle');
            btn.textContent = isDark ? 'Dark Mode' : 'Light Mode';
            localStorage.setItem('theme', isDark ? 'light' : 'dark');
        }

        // Tab switching function
        function showTab(tabName, event = null) {
            // Hide all tab contents
            document.querySelectorAll('.tab-content').forEach(tab => tab.classList.remove('active'));
            // Remove active class from all tab buttons
            document.querySelectorAll('.tab-btn').forEach(btn => btn.classList.remove('active'));
            
            // Show the selected tab content
            const selectedTab = document.getElementById(tabName + '-tab');
            if (selectedTab) {
                selectedTab.classList.add('active');
            }
            
            // Highlight the correct tab button
            if (event && event.target) {
                // If called from a click event, highlight the clicked button
                event.target.classList.add('active');
            } else {
                // If called programmatically, find and highlight the button for this tab
                const tabButtons = document.querySelectorAll('.tab-btn');
                tabButtons.forEach(btn => {
                    if (btn.getAttribute('onclick') && btn.getAttribute('onclick').includes(tabName)) {
                        btn.classList.add('active');
                    }
                });
            }
            
            // Save the active tab to localStorage
            localStorage.setItem('activeTab', tabName);
        }

        // Form handlers
        document.getElementById('wifiForm').onsubmit = function(e) {
            e.preventDefault();
            const formData = new FormData();
            formData.append('ssid', document.getElementById('ssid').value);
            formData.append('password', document.getElementById('password').value);
            fetch('/configure', { method: 'POST', body: formData })
            .then(response => response.text())
            .then(data => {
                document.getElementById('status').innerHTML = '<div class="status success">' + data + '</div>';
            })
            .catch(error => {
                document.getElementById('status').innerHTML = '<div class="status error">Error: ' + error + '</div>';
            });
        };

        document.getElementById('mqttForm').onsubmit = function(e) {
            e.preventDefault();
            const formData = new FormData();
            formData.append('mqtt_broker', document.getElementById('mqtt_broker').value);
            formData.append('mqtt_port', document.getElementById('mqtt_port').value);
            formData.append('mqtt_client_id', document.getElementById('mqtt_client_id').value);
            formData.append('mqtt_channel_name', document.getElementById('mqtt_channel_name').value);
            formData.append('mqtt_topic_prefix', document.getElementById('mqtt_topic_prefix').value);
            fetch('/configure_mqtt', { method: 'POST', body: formData })
            .then(response => response.text())
            .then(data => {
                document.getElementById('status').innerHTML = '<div class="status success">' + data + '</div>';
            })
            .catch(error => {
                document.getElementById('status').innerHTML = '<div class="status error">Error: ' + error + '</div>';
            });
        };

        // Status check function
        function checkStatus() {
            fetch('/status')
            .then(response => response.json())
            .then(data => {
                const prettyJson = JSON.stringify(data, null, 2);
                document.getElementById('status').innerHTML = '<div class="status success"><h3>Device Status JSON</h3><pre class="status-json">' + prettyJson + '</pre></div>';
            })
            .catch(error => {
                document.getElementById('status').innerHTML = '<div class="status error">Error: ' + error + '</div>';
            });
        }

        // Firmware upload functions
        function validateFile(input) {
            const file = input.files[0];
            const uploadBtn = document.getElementById('uploadBtn');
            const statusDiv = document.getElementById('uploadStatus');
            if (file && file.name.endsWith('.bin')) {
                uploadBtn.disabled = false;
                statusDiv.innerHTML = '<div style="color:var(--success);padding:10px;border-radius:4px;background:var(--bg-secondary);">File selected: ' + file.name + ' (' + (file.size/1024).toFixed(1) + ' KB)</div>';
            } else {
                uploadBtn.disabled = true;
                statusDiv.innerHTML = '<div style="color:var(--danger);padding:10px;border-radius:4px;background:var(--bg-secondary);">Please select a .bin file</div>';
            }
        }

        function uploadFirmware() {
            const fileInput = document.getElementById('firmware');
            const file = fileInput.files[0];
            const uploadBtn = document.getElementById('uploadBtn');
            const cancelBtn = document.getElementById('cancelBtn');
            const progressBar = document.getElementById('progressBar');
            const statusDiv = document.getElementById('uploadStatus');
            if (!file) return;
            if (currentUpload || versionPolling) {
                console.log('Upload already in progress, ignoring...');
                return;
            }
            uploadBtn.disabled = true;
            cancelBtn.disabled = false;
            progressBar.style.width = '0%';
            versionPolling = false;
            statusDiv.innerHTML = '<div style="color:var(--info);padding:10px;border-radius:4px;background:var(--bg-secondary);">Preparing upload...</div>';
            const formData = new FormData();
            formData.append('firmware', file);
            const xhr = new XMLHttpRequest();
            currentUpload = xhr;
            xhr.upload.addEventListener('progress', function(e) {
                if (e.lengthComputable) {
                    const percentComplete = (e.loaded / e.total) * 100;
                    progressBar.style.width = percentComplete + '%';
                    statusDiv.innerHTML = '<div style="color:var(--info);padding:10px;border-radius:4px;background:var(--bg-secondary);">Uploading: ' + Math.round(percentComplete) + '%</div>';
                }
            });
            xhr.addEventListener('load', function() {
                currentUpload = null;
                cancelBtn.disabled = true;
                if (xhr.status === 200) {
                    console.log('Upload completed successfully');
                    statusDiv.innerHTML = '<div style="color:var(--success);padding:10px;border-radius:4px;background:var(--bg-secondary);">Upload completed! Device rebooting... Checking for new version...</div>';
                    progressBar.style.width = '100%';
                    startVersionPolling();
                } else {
                    console.log('Upload response error, status:', xhr.status);
                    statusDiv.innerHTML = '<div style="color:var(--warning);padding:10px;border-radius:4px;background:var(--bg-secondary);">Upload may have completed (connection reset). Checking for new version...</div>';
                    progressBar.style.width = '100%';
                    startVersionPolling();
                }
            });
            xhr.addEventListener('error', function() {
                currentUpload = null;
                cancelBtn.disabled = true;
                console.log('Upload network error (likely device reboot)');
                statusDiv.innerHTML = '<div style="color:var(--warning);padding:10px;border-radius:4px;background:var(--bg-secondary);">Upload completed (connection reset). Device rebooting... Checking for new version...</div>';
                progressBar.style.width = '100%';
                startVersionPolling();
            });
            xhr.open('POST', '/doUpdate');
            xhr.send(formData);
        }

        function cancelUpload() {
            if (currentUpload) {
                currentUpload.abort();
                currentUpload = null;
                const uploadBtn = document.getElementById('uploadBtn');
                const cancelBtn = document.getElementById('cancelBtn');
                const progressBar = document.getElementById('progressBar');
                const statusDiv = document.getElementById('uploadStatus');
                uploadBtn.disabled = false;
                cancelBtn.disabled = true;
                progressBar.style.width = '0%';
                statusDiv.innerHTML = '<div style="color:var(--warning);padding:10px;border-radius:4px;background:var(--bg-secondary);">Upload cancelled</div>';
            }
        }

        function restartDevice() {
            if (confirm('Are you sure you want to restart the device?')) {
                fetch('/restart', { method: 'POST' })
                    .then(() => {
                        alert('Device is restarting... Please wait a moment and refresh the page.');
                        setTimeout(() => location.reload(), 10000);
                    })
                    .catch(error => alert('Restart request failed: ' + error));
            }
        }

        function resetSavedVariables() {
            if (confirm('WARNING: This will delete ALL saved settings (WiFi, MQTT, etc.) and restart with defaults. Are you sure?')) {
                if (confirm('This action cannot be undone. The device will lose all configuration. Continue?')) {
                    fetch('/reset', { method: 'POST' })
                    .then(() => {
                        alert('All saved variables cleared! Device is restarting with default settings. You may need to reconfigure WiFi.');
                        setTimeout(() => location.reload(), 15000);
                    })
                    .catch(error => alert('Reset request failed: ' + error));
                }
            }
        }

        function validateConfigFile(input) {
            const file = input.files[0];
            const restoreBtn = document.getElementById('restoreBtn');
            if (file && file.name.endsWith('.json')) {
                restoreBtn.disabled = false;
            } else {
                restoreBtn.disabled = true;
                alert('Please select a valid backup file (.json)');
            }
        }

        function restoreConfig() {
            const fileInput = document.getElementById('configFile');
            const file = fileInput.files[0];
            if (!file) return;
            if (!confirm('This will overwrite all current settings and restart the device. Continue?')) return;
            
            // Read the file to extract device settings before sending to ESP32
            const reader = new FileReader();
            reader.onload = function(e) {
                try {
                    const config = JSON.parse(e.target.result);
                    
                    // Restore device settings if they exist in the backup
                    if (config.device_settings && typeof config.device_settings === 'object') {
                        restoreDeviceSettings(config.device_settings);
                        console.log('Device settings restored from backup');
                    }
                    
                    // Legacy support: also check for old device_labels format
                    if (config.device_labels && typeof config.device_labels === 'object') {
                        restoreDeviceLabels(config.device_labels);
                        console.log('Legacy device labels restored from backup');
                    }
                    
                    // Send the config to ESP32 for restore
                    const formData = new FormData();
                    formData.append('config', file);
                    fetch('/restore', { method: 'POST', body: formData })
                    .then(response => {
                        if (response.ok) {
                            alert('Configuration restored! Device is restarting...');
                            setTimeout(() => location.reload(), 15000);
                        } else {
                            throw new Error('Restore failed');
                        }
                    })
                    .catch(error => alert('Restore failed: ' + error));
                    
                } catch (error) {
                    alert('Invalid backup file format: ' + error.message);
                }
            };
            reader.readAsText(file);
        }

        function controlDevice(event, type, number, action) {
            event.preventDefault();
            const formData = new FormData();
            formData.append('type', type);
            formData.append('number', number);
            formData.append('action', action);
            fetch('/control', { method: 'POST', body: formData })
            .then(response => {
                if (response.ok) {
                    console.log(type + ' ' + number + ' set to ' + action);
                    
                    // Refresh the GUI to show the new state
                    // Single call to avoid duplicate MQTT sends
                    checkChanges();
                    
                } else {
                    console.error('Control request failed');
                }
            })
            .catch(error => console.error('Control request error:', error));
        }

        function controlLight(event, lightNumber) {
            event.preventDefault();
            
            // Toggle the light state (ON/OFF)
            const formData = new FormData();
            formData.append('type', 'light');
            formData.append('number', lightNumber);
            formData.append('action', 'toggle');
            
            fetch('/control', { method: 'POST', body: formData })
            .then(response => {
                if (response.ok) {
                    console.log('Light ' + lightNumber + ' toggled');
                    
                    // Refresh the GUI to show the new state
                    // Single call to avoid duplicate MQTT sends
                    checkChanges();
                    
                } else {
                    console.error('Light control request failed');
                }
            })
            .catch(error => console.error('Light control request error:', error));
        }
        
        function updateDeviceLabel(type, number, newLabel) {
            const key = `${type}_${number}_label`;
            localStorage.setItem(key, newLabel);
            
            // Find the row and update the input field
            const selector = `tr[data-device-type="${type}"][data-device-num="${number}"]`;
            const row = document.querySelector(selector);
            if (row) {
                const input = row.querySelector('.device-label');
                if (input) {
                    input.value = newLabel;
                    console.log('Updated form field for device label:', newLabel);
                }
            }
            
            console.log('Device label saved:', key, '=', newLabel);
        }
        
        function updateDeviceId(type, number, newId) {
            const key = `${type}_${number}_id`;
            localStorage.setItem(key, newId);
            
            // Find the row and update the input field
            const selector = `tr[data-device-type="${type}"][data-device-num="${number}"]`;
            const row = document.querySelector(selector);
            if (row) {
                const input = row.querySelector('.device-id');
                if (input) {
                    input.value = newId;
                    console.log('Updated form field for device ID:', newId);
                }
            }
            
            console.log('Device ID updated:', key, '=', newId);
        }
        
        function updateDevicePin(type, number, newPin) {
            const key = `${type}_${number}_pin`;
            localStorage.setItem(key, newPin);
            
            // Find the row and update the input field
            const selector = `tr[data-device-type="${type}"][data-device-num="${number}"]`;
            const row = document.querySelector(selector);
            if (row) {
                const input = row.querySelector('.device-pin');
                if (input) {
                    input.value = newPin;
                    console.log('Updated form field for device pin:', newPin);
                }
            }
            
            console.log('Device pin updated:', key, '=', newPin);
        }
        
        function updateDeviceType(type, number, newType) {
            const key = `${type}_${number}_type`;
            localStorage.setItem(key, newType);
            
            // Find the row and update both the dropdown and the data attribute
            const selector = `tr[data-device-type="${type}"][data-device-num="${number}"]`;
            const row = document.querySelector(selector);
            if (row) {
                // Update the dropdown value
                const select = row.querySelector('.device-type');
                if (select) {
                    select.value = newType;
                    console.log('Updated dropdown value:', newType);
                }
                
                // Update the row's data-device-type attribute
                row.setAttribute('data-device-type', newType);
                console.log('Updated row data-device-type attribute to:', newType);
            }
            
            console.log('Device type updated:', key, '=', newType);
        }
        
        function getDeviceLabel(type, number) {
            const key = `${type}_${number}_label`;
            return localStorage.getItem(key) || `${type} ${number}`;
        }
        
        function getAllDeviceLabels() {
            const labels = {};
            const deviceInputs = document.querySelectorAll('.device-label');
            
            deviceInputs.forEach((input) => {
                const row = input.closest('tr');
                const deviceType = row.getAttribute('data-device-type');
                const deviceNum = row.getAttribute('data-device-num');
                
                if (deviceType && deviceNum) {
                    const key = deviceType + '_' + deviceNum;
                    labels[key] = input.value || `${deviceType.charAt(0).toUpperCase() + deviceType.slice(1)} ${deviceNum}`;
                }
            });
            
            return labels;
        }
        
        function getAllDeviceSettings() {
            const settings = {};
            const deviceInputs = document.querySelectorAll('.device-label, .device-id, .device-pin, .device-type');
            
            deviceInputs.forEach((input) => {
                const row = input.closest('tr');
                const deviceType = row.getAttribute('data-device-type');
                const deviceNum = row.getAttribute('data-device-num');
                
                if (!deviceType || !deviceNum) {
                    console.warn('Row missing data attributes:', row);
                    return;
                }
                
                if (input.classList.contains('device-label')) {
                    const key = `${deviceType}_${deviceNum}_label`;
                    settings[key] = input.value || `${deviceType.charAt(0).toUpperCase() + deviceType.slice(1)} ${deviceNum}`;
                } else if (input.classList.contains('device-id')) {
                    const key = `${deviceType}_${deviceNum}_id`;
                    settings[key] = input.value || deviceNum;
                } else if (input.classList.contains('device-pin')) {
                    const key = `${deviceType}_${deviceNum}_pin`;
                    settings[key] = input.value || 'N/A';
                } else if (input.classList.contains('device-type')) {
                    const key = `${deviceType}_${deviceNum}_type`;
                    settings[key] = input.value || deviceType;
                }
            });
            
            return settings;
        }
        
        function restoreDeviceLabels(labels) {
            for (const [key, value] of Object.entries(labels)) {
                // Extract type and number from the key (e.g., "sensor_1" -> type="sensor", number=1)
                const match = key.match(/^(\w+)_(\d+)$/);
                if (match) {
                    const type = match[1];
                    const number = parseInt(match[2], 10);
                    updateDeviceLabel(type, number, value);
                }
            }
            console.log('Device labels restored:', labels);
        }
        
        function restoreDeviceSettings(settings) {
            for (const [key, value] of Object.entries(settings)) {
                // Extract type, number, and attribute name from the key
                const match = key.match(/^(\w+)_(\d+)_(id|pin|label|type)$/);
                if (match) {
                    const type = match[1];
                    const number = parseInt(match[2], 10);
                    const attr = match[3];

                    if (attr === 'id') {
                        updateDeviceId(type, number, value);
                    } else if (attr === 'pin') {
                        updateDevicePin(type, number, value);
                    } else if (attr === 'label') {
                        updateDeviceLabel(type, number, value);
                    } else if (attr === 'type') {
                        updateDeviceType(type, number, value);
                    }
                }
            }
            console.log('Device settings restored:', settings);
        }
        
        function downloadBackup() {
            // First get the ESP32 backup
            fetch('/backup')
            .then(response => response.json())
            .then(data => {
                // Add current device settings from the form (labels, IDs, pins)
                data.device_settings = getAllDeviceSettings();
                
                // Convert to JSON string
                const jsonStr = JSON.stringify(data, null, 2);
                
                // Create and download the file
                const blob = new Blob([jsonStr], { type: 'application/json' });
                const url = URL.createObjectURL(blob);
                const a = document.createElement('a');
                a.href = url;
                a.download = data.mqtt_client_id + '_backup_with_settings_' + Date.now() + '.json';
                document.body.appendChild(a);
                a.click();
                document.body.removeChild(a);
                URL.revokeObjectURL(url);
                
                console.log('Backup downloaded with device settings');
            })
            .catch(error => {
                console.error('Backup download failed:', error);
                alert('Backup download failed: ' + error.message);
            });
        }

        function startVersionPolling() {
            if (versionPolling) return;
            versionPolling = true;
            console.log('Starting version polling - device is rebooting...');
            const statusDiv = document.getElementById('uploadStatus');
            let attempts = 0;
            const maxAttempts = 60;
            statusDiv.innerHTML = '<div style="color:var(--info);padding:10px;border-radius:4px;background:var(--bg-secondary);">Network timed out during upload. Reestablishing connection...</div>';
            const pollInterval = setInterval(() => {
                attempts++;
                console.log('Polling attempt', attempts, '- Checking if device is back online...');
                statusDiv.innerHTML = '<div style="color:var(--info);padding:10px;border-radius:4px;background:var(--bg-secondary);">Reestablishing connection... (attempt ' + attempts + '/' + maxAttempts + ')</div>';
                fetch('/status', { cache: 'no-cache' }).then(response => {
                    if (response.ok) {
                        return response.json();
                    }
                    throw new Error('Device not ready');
                }).then(data => {
                    console.log('Device is back online! Full response:', data);
                    console.log('Version field specifically:', data.version);
                    clearInterval(pollInterval);
                    versionPolling = false;
                    const newVersion = data.version || data.firmware_version || Object.keys(data).find(k => k.includes('version')) ? data[Object.keys(data).find(k => k.includes('version'))] : 'Debug: ' + JSON.stringify(Object.keys(data));
                    statusDiv.innerHTML = '<div style="color:var(--success);padding:10px;border-radius:4px;background:var(--bg-secondary);">Update successful! New firmware version: ' + newVersion + '</div>';
                    const versionDisplay = document.getElementById('firmware-version');
                    if (versionDisplay) {
                        versionDisplay.textContent = 'Current Version: ' + newVersion;
                        versionDisplay.style.color = 'var(--success)';
                        versionDisplay.style.fontWeight = 'bold';
                        console.log('Version display updated to:', newVersion);
                        setTimeout(() => {
                            versionDisplay.style.color = 'var(--text-secondary)';
                            versionDisplay.style.fontWeight = 'normal';
                        }, 3000);
                    }
                    uploadBtn.disabled = false;
                }).catch(error => {
                    console.log('Attempt', attempts, '- Device not ready yet');
                    if (attempts >= maxAttempts) {
                        console.log('Max attempts reached, stopping polling');
                        clearInterval(pollInterval);
                        versionPolling = false;
                        statusDiv.innerHTML = '<div style="color:var(--warning);padding:10px;border-radius:4px;background:var(--bg-secondary);">Update may have completed. <button onclick="localStorage.setItem(\'activeTab\',\'firmware\');location.reload()" style="margin-left:10px;padding:5px 10px;background:var(--accent-primary);color:white;border:none;border-radius:3px;cursor:pointer;">Refresh to Firmware Tab</button></div>';
                    }
                });
            }, 2000);
        }

        function saveAllDeviceSettings(event) {
            if (event && event.target) {
                event.preventDefault();
            }
            
            const rows = document.querySelectorAll('#device-table-body tr[data-device-type]');
            console.log('Found rows:', rows.length);
            const deviceSettings = {};
            
            rows.forEach((row, index) => {
                const deviceType = row.getAttribute('data-device-type');
                const deviceNum = row.getAttribute('data-device-num');
                const pinNum = row.getAttribute('data-pin');
                
                console.log(`Row ${index}: deviceType=${deviceType}, deviceNum=${deviceNum}, pinNum=${pinNum}`);
                console.log(`Row ${index} attributes:`, {
                    'data-device-type': row.getAttribute('data-device-type'),
                    'data-device-num': row.getAttribute('data-device-num'),
                    'data-pin': row.getAttribute('data-pin')
                });
                
                if (deviceType && deviceNum && pinNum) {
                    const label = row.querySelector('.device-label').value;
                    const id = row.querySelector('.device-id').value;
                    const type = row.querySelector('.device-type').value;
                    
                    // Create a unique key using the pin number for consistency
                    const deviceKey = `pin_${pinNum}`;
                    
                    deviceSettings[deviceKey] = {
                        label: label,
                        id: id,
                        pin: parseInt(pinNum),
                        type: type
                    };
                    
                    console.log('Collected settings for:', deviceKey, deviceSettings[deviceKey]);
                }
            });
            
            console.log('All device settings:', deviceSettings);
            console.log('Device settings JSON:', JSON.stringify(deviceSettings, null, 2));
            
            // Send to ESP32
            fetch('/save_device_settings', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ device_settings: deviceSettings })
            })
            .then(response => response.text())
            .then(data => {
                console.log('Save response:', data);
                alert('Device settings saved successfully!');
            })
            .catch(error => {
                console.error('Error saving device settings:', error);
                alert('Failed to save device settings: ' + error.message);
            });
        }

        function loadConfiguration() {
            fetch('/config')
                .then(response => response.json())
                .then(data => {
                    // Populate WiFi form fields
                    const ssidField = document.getElementById('ssid');
                    const passwordField = document.getElementById('password');
                    if (ssidField) ssidField.value = data.wifi_ssid || '';
                    if (passwordField) passwordField.value = data.wifi_password || '';
                    
                    // Populate MQTT form fields
                    const brokerField = document.getElementById('mqtt_broker');
                    const portField = document.getElementById('mqtt_port');
                    const clientIdField = document.getElementById('mqtt_client_id');
                    const channelField = document.getElementById('mqtt_channel_name');
                    const topicField = document.getElementById('mqtt_topic_prefix');
                    
                    if (brokerField) brokerField.value = data.mqtt_broker || '';
                    if (portField) portField.value = data.mqtt_port || '';
                    if (clientIdField) clientIdField.value = data.mqtt_client_id || '';
                    if (channelField) channelField.value = data.mqtt_channel_name || '';
                    if (topicField) topicField.value = data.mqtt_topic_prefix || '';
                    
                    console.log('Configuration loaded from /config:', data);
                })
                .catch(error => {
                    console.error('Failed to load configuration from /config:', error);
                });
        }
    </script>
</body>
</html>
)rawliteral";
  return html;
}

// Device table HTML generation
const char* getDeviceTableHTML() {
  static const char* html = R"rawliteral(
<table class="device-table">
    <thead>
        <tr>
            <th>Type</th>
            <th>ID</th>
            <th>Pin</th>
            <th>State</th>
            <th>Label</th>
            <th>Control</th>
        </tr>
    </thead>
    <tbody id="device-table-body">
        <tr><td colspan="6" style="text-align:center;color:var(--text-secondary);">Loading device status...</td></tr>
    </tbody>
</table>
)rawliteral";
  return html;
}

#endif // HTML_CONTENT_H
