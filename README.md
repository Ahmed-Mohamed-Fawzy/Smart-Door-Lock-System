# Smart-Door-Lock-System
Project Overview: The Security Door Lock System is designed to enhance home security by providing a robust and secure mechanism for unlocking doors using a password. Let’s dive into the details:

Components:
The system is powered by the AT89S52 Microcontroller, which acts as the brain of the system controlling all processes. The HMI_ECU (Human Machine Interface) is equipped with a 2x16 LCD for displaying messages and a 4x4 keypad for user input. The Control_ECU incorporates an EEPROM for data storage, a Buzzer for alarms, and drives a DC-Motor for door control.

Functionality:
The system is triggered by the infrared (IR) sensor detecting an object. The LCD screen prompts the user to enter a password. The user has three attempts to enter the correct password. After three failed attempts, the system activates safety measures.

Access Control:
If the user enters the correct password, the microcontroller compares it with the initially saved password. If the comparison is successful, the system opens the door and communicates with the ATMEGA32.

Smart Home Features:
Users with access can turn lights on/off with adjustable modes and control the air conditioner.
