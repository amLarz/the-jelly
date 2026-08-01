
#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
WebServer server(80);

#define TFT_CS    5
#define TFT_RST   4
#define TFT_DC    2
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

#include "screen.h"

const char HTML_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style> 
        body {
            background-color: #2e1a47;
            margin: 0;
            padding: 20px;
        }

        h1 {
            color: #d9b3ff;
            font-family: sans-serif;
        }

        legend {
            color: #d9b3ff;
            font-family: sans-serif;
            font-weight: bold;
            padding: 0 8px;
        }

        .widget-row1 {
            display: flex;
            gap: 20px;
            justify-content: center;
        }

        .widget-row2 {
            display: flex;
            gap: 20px;
            justify-content: center;
        }
        .gps-location {
            display: block;
            width: 30%;
            height: 200px;
            background-color: #4a3366;
            border: 1px solid #000;
            border-radius: 5px;
            margin-bottom: 20px;
            padding: 10px 15px;
        }

        .top-tourist-spots {
            display: block;
            width: 30%;
            height: 200px;
            background-color: #4a3366;
            border: 1px solid #000;
            border-radius: 5px;
            margin-bottom: 20px;
            padding: 10px 15px;
        }

        .documents {
            display: flex;
            width: 30%;
            height: 200px;
            background-color: #4a3366;
            border: 1px solid #000;
            border-radius: 5px;
            margin-bottom: 20px;
            padding: 10px 15px;
        }

        .documents form {
            display: flex;
            flex-direction: column;
            align-items: flex;
            justify-content: center;
            margin: 10px;
            height: 100%;
        }

        label {
            color: #d9b3ff;
            font-family: sans-serif;
        }

        input[type="text"] {
            background-color: #3a2657;
            color: #d9b3ff;
            border: 1px solid #000;
            border-radius: 3px;
            padding: 4px 6px;
        }

        input[type="text"]::placeholder {
            color: #b399cc;
        }

        input[type="file"] {
            color: #d9b3ff;
        }

        input[type="file"]::file-selector-button {
            background-color: #3a2657;
            color: #d9b3ff;
            border: 1px solid #000;
            border-radius: 3px;
            padding: 4px 8px;
            cursor: pointer;
        }

        button[type="submit"] {
            background-color: #3a2657;
            color: #d9b3ff;
            border: 1px solid #000;
            border-radius: 3px;
            padding: 6px 12px;
            cursor: pointer;
        }

        p {
            color: #d9b3ff;
            font-family: sans-serif;
        }
    </style>
</head>
<body>
    <center><h1>The Jelly</h1></center>

    <div class="widget-row1">

    <fieldset class="gps-location" location=center>  
        <legend>GPS Location</legend>
        <form>
            <!-- Return Latitude from GPS -->
            <p>
                <label for="latitude">Latitude:</label><br>
                <input type="text" id="latitude" name="latitude" placeholder="Fetching..." readonly>
            </p>

            <!-- Longitude return from GPS -->
            <p>
                <label for="longitude">Longitude:</label><br>
                <input type="text" id="longitude" name="longitude" placeholder="Fetching..." readonly>
            </p>

            <!-- Height return from GPS -->
            <p> 
                <label for="height">Height:</label><br>
                <input type="text" id="height" name="height" placeholder="Fetching..." readonly>
            </p>
        </form>
    </fieldset>

    <!-- Top Tourist Spots PLACEHOLDERS -->
    <fieldset class="top-tourist-spots" location=center>
        <legend>Top Tourist Spots</legend>
        <p>1. Spot A</p>
        <p>2. Spot B</p>
        <p>3. Spot C</p>
    </fieldset>
    </div>
    <div class="widget-row2">
        <fieldset class="documents" location=center>
            <legend>Documents</legend>
            <form action="/upload-endpoint" method="POST" enctype="multipart/form-data">
                <label for="document">Choose a file to upload passport:</label>
                <input type="file" id="document" name="userDocument" required>
                <button type="submit">Upload Document</button>
            </form>

            <form action="/upload-endpoint" method="POST" enctype="multipart/form-data">
                <label for="document">Choose a file to upload payment card:</label>
                <input type="file" id="document" name="userDocument" required>
                <button type="submit">Upload Document</button>
            </form>

        </fieldset>
    </div>
</body>
)rawliteral";

void handleRoot() {
    server.send(200, "text/html", HTML_PAGE);
}

void setup() {
    Serial.begin(115200);
    tft.init(240, 240);
    tft.setRotation(1);
    tft.fillScreen(ST77XX_BLACK);

    tft.drawRGBBitmap(10, 10, myImagePixels, 240, 240);  // match your real dims

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) { delay(500); }

    server.on("/", handleRoot);
    server.begin();
}

void loop() {
    server.handleClient();
}
