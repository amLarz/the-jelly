# The Jelly
A small personal travel buddy.


<img width="1440" height="2560" alt="11583" src="https://github.com/user-attachments/assets/27958890-935b-4b99-b3d9-dc18abda375a" />

## What is this?
The jelly is a travel buddy that can host it's own website with WiFi from your phone. 
You can both view information on your phone or on the device itself.

## How is this made?
For this project we mainly used ESP32 as the micro controller connected to hardware that can take data and place it on a screen or a website.
This project is coded heavily in C++ inside the Arduino IDE but code is kept in GitHub for version control.

## Features
Here are the features included for this project:
GPS
- Takes the location of the device and displays it (both natively and on the self-hosted website)
      
NFC reader
- Keep payment cards and save them on the device
- Save other types of documents that may use NFC technology

Lists of Tourist Spots
- Include places based from the coordinates of the person

## Controls
The device will have a screen and 3 buttons: down, up, select/return; respectively.

- `down` button - navigating down
- `up` button - navigating up
- `select/return` button (when clicked) - selects item
- `select/return` button (when held down - returns to previous frame

## Tech Stack 
Hardware: 
- ESP32
- ST7789
- 1.54
- MOMENTARY PUSH BUTTONS
- PN532
- NEO 6M GPS

Programming Language/Firmware:
- C++
- HTML5

Development Software/Testing:
- Arduino IDE
- VSCode
- Git and GitHub 






