# MQTTPubSubClient_Generic client for ESP8266, ESP32, etc.

[![arduino-library-badge](https://www.ardu-badge.com/badge/MQTTPubSubClient_Generic.svg?)](https://www.ardu-badge.com/MQTTPubSubClient_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/MQTTPubSubClient_Generic.svg)](https://github.com/khoih-prog/MQTTPubSubClient_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/MQTTPubSubClient_Generic/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/MQTTPubSubClient_Generic.svg)](http://github.com/khoih-prog/MQTTPubSubClient_Generic/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this MQTTPubSubClient_Generic library](#why-do-we-need-this-MQTTPubSubClient_Generic-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported WiFi shields/modules](#Currently-supported-WiFi-shieldsmodules)
  * [Currently supported Ethernet shields/modules](#Currently-supported-Ethernet-shieldsmodules)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
  * [10. For RTL8720DN boards using AmebaD core](#10-for-rtl8720dn-boards-using-amebad-core)
  * [11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core](#11-For-SAMD21-and-SAMD51-boards-using-ArduinoCore-fab-sam-core)
  * [12. For Seeeduino RP2040 boards](#12-For-Seeeduino-RP2040-boards)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
  * [8. For fixing ESP8266 compile error](#8-for-fixing-esp8266-compile-error)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Usage](#Usage)
	* [MQTT](#MQTT)
  * [MQTT over WebSocket](#MQTT-over-WebSocket)
  * [MQTT with Secure Connection](#MQTT-with-Secure-Connection)
  * [Callback Signature](#Callback-Signature)
  * [Send and Receive Buffer Size Management](#Send-and-Receive-Buffer-Size-Management)
* [APIs](#APIs)
* [HOWTO use STM32F4 with LAN8720](#howto-use-stm32f4-with-lan8720)
  * [1. Wiring](#1-wiring)
  * [2. HOWTO program using STLink V-2 or V-3](#2-howto-program-using-stlink-v-2-or-v-3)
  * [3. HOWTO use Serial Port for Debugging](#3-howto-use-serial-port-for-debugging)
* [Examples](#examples)
  * [1. For Ethernet](#1-for-Ethernet)
    * [1. EtherMQTT](examples/Ethernet/EtherMQTT)
    * [2. EtherMQTToverWebSocket](examples/Ethernet/EtherMQTToverWebSocket)
  * [2. For QNEthernet](#2-for-QNEthernet)
    * [1. MQTToverWebSocket_QNEthernet](examples/QNEthernet/MQTToverWebSocket_QNEthernet)
    * [2. MQTT_QNEthernet](examples/QNEthernet/MQTT_QNEthernet)
  * [3. For STM32](#3-For-STM32)
    * [1. EtherMQTToverWebSocket_STM32](examples/STM32/EtherMQTToverWebSocket_STM32)
    * [2. EtherMQTT_STM32](examples/STM32/EtherMQTT_STM32)
  * [4. For WiFi](#4-For-WiFi)
    * [1. WiFiMQTT](examples/WiFi/WiFiMQTT)
    * [2. WiFiMQTToverWebSocket](examples/WiFi/WiFiMQTToverWebSocket)
    * [3. WiFiMQTToverWebSocketSecure](examples/WiFi/WiFiMQTToverWebSocketSecure)
    * [4. WiFiMQTTSecure](examples/WiFi/WiFiMQTTSecure)
    * [5. WiFiMQTTSecureAWS](examples/WiFi/WiFiMQTTSecureAWS)
  * [5. For RP2040W](#5-For-RP2040W) **New**
    * [1. WiFiMQTT](examples/RP2040W/WiFiMQTT)
    * [2. WiFiMQTToverWebSocket](examples/RP2040W/WiFiMQTToverWebSocket)
    * [3. WiFiMQTTSecure](examples/RP2040W/WiFiMQTTSecure)
    * [4. WiFiMQTTSecureAWS](examples/RP2040W/WiFiMQTTSecureAWS)
  * [6. For WiFiNINA](#6-For-WiFiNINA)
    * [1. WiFiNINA_MQTT](examples/WiFiNINA/WiFiNINA_MQTT)
    * [2. WiFiNINA_MQTToverWebSocket](examples/WiFiNINA/WiFiNINA_MQTToverWebSocket)
    * [3. WiFiNINA_MQTToverWebSocketSecure](examples/WiFiNINA/WiFiNINA_MQTToverWebSocketSecure)
    * [4. WiFiNINA_MQTTSecure](examples/WiFiNINA/WiFiNINA_MQTTSecure)
    * [5. WiFiNINA_MQTTSecureAWS](examples/WiFiNINA/WiFiNINA_MQTTSecureAWS)
* [Example EtherMQTToverWebSocket](#example-EtherMQTToverWebSocket)
  * [1. File EtherMQTToverWebSocket.ino](#1-file-EtherMQTToverWebSocketino)
  * [2. File defines.h](#2-file-definesh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [ 1. WiFiMQTToverWebSocket on ESP8266_NODEMCU_ESP12E](#1-WiFiMQTToverWebSocket-on-ESP8266_NODEMCU_ESP12E) 
  * [ 2. WiFiMQTToverWebSocketSecure on ESP32_DEV](#2-WiFiMQTToverWebSocketSecure-on-ESP32_DEV)
  * [ 3. WiFiMQTToverWebSocket on SAMD_NANO_33_IOT](#3-WiFiMQTToverWebSocket-on-SAMD_NANO_33_IOT) 
  * [ 4. EtherMQTToverWebSocket on NUCLEO_F767ZI](#4-EtherMQTToverWebSocket-on-NUCLEO_F767ZI)
  * [ 5. EtherMQTToverWebSocket_STM32 on NUCLEO_F767ZI](#5-EtherMQTToverWebSocket_STM32-on-NUCLEO_F767ZI)
  * [ 6. MQTToverWebSocket_QNEthernet on TEENSY 4.1](#6-MQTToverWebSocket_QNEthernet-on-TEENSY-41)
  * [ 7. EtherMQTToverWebSocket on MBED RASPBERRY_PI_PICO](#7-EtherMQTToverWebSocket-on-MBED-RASPBERRY_PI_PICO)
  * [ 8. EtherMQTToverWebSocket on RASPBERRY_PI_PICO](#8-EtherMQTToverWebSocket-on-RASPBERRY_PI_PICO)
  * [ 9. EtherMQTToverWebSocket on TEENSY 4.0](#9-EtherMQTToverWebSocket-on-TEENSY-40)
  * [10. WiFiMQTT on RASPBERRY_PI_PICO_W](#10-WiFiMQTT-on-RASPBERRY_PI_PICO_W) **New**
  * [11. WiFiMQTTSecure on RASPBERRY_PI_PICO_W](#11-WiFiMQTTSecure-on-RASPBERRY_PI_PICO_W) **New**
  * [12. WiFiMQTToverWebSocket on RASPBERRY_PI_PICO_W](#12-WiFiMQTToverWebSocket-on-RASPBERRY_PI_PICO_W) **New**
  * [13. WiFiNINA_MQTToverWebSocket on Nano_RP2040_Connect](#13-WiFiNINA_MQTToverWebSocket-on-Nano_RP2040_Connect) **New**
  * [14. WiFiNINA_MQTToverWebSocketSecure on Nano_RP2040_Connect](#14-WiFiNINA_MQTToverWebSocketSecure-on-Nano_RP2040_Connect) **New**
  * [15. WiFiNINA_MQTToverWebSocketSecure on SAMD_NANO_33_IOT](#15-WiFiNINA_MQTToverWebSocketSecure-on-SAMD_NANO_33_IOT) **New**
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [MQTTPubSubClient_Generic library](https://github.com/khoih-prog/MQTTPubSubClient_Generic)

#### Features

This [**MQTTPubSubClient_Generic library**](https://github.com/khoih-prog/MQTTPubSubClient_Generic) is based on and modified from 
- [**Joël Gähwiler's lwmqtt Library**](https://github.com/256dpi/lwmqtt)
- [**Joël Gähwiler's async-mqtt Library**](https://github.com/256dpi/arduino-mqtt)
- [**Hideaki Tai's MQTTPubSubClient Library**](https://github.com/hideakitai/MQTTPubSubClient)

 to provide support to many more boards besides ESP32/ESP8266, such as **SAMD, SAM DUE, nRF52, RP2040, STM32, Teensy 4.1, etc. boards**. Those supported boards can be used with **ESP8266/ESP32’s WiFi, WiFiNINA, CYW43439 WiFi, LAN8742A Ethernet, Teensy 4.1 QNEthernet, W5x00 Ethernet, etc.**


---

#### Currently supported Boards

This [**MQTTPubSubClient_Generic** library](https://github.com/khoih-prog/MQTTPubSubClient_Generic) currently supports these following boards:

 1. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 
 2. **SAMD21**
  - Arduino SAMD21: ZERO, MKRs, NANO_33_IOT, etc.
  - Adafruit SAMD21 (M0): ItsyBitsy M0, Feather M0, Feather M0 Express, Metro M0 Express, Circuit Playground Express, Trinket M0, PIRkey, Hallowing M0, Crickit M0, etc.
  - Seeeduino:  LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, etc.
  
 3. **SAMD51**
  - Adafruit SAMD51 (M4): Metro M4, Grand Central M4, ItsyBitsy M4, Feather M4 Express, Trellis M4, Metro M4 AirLift Lite, MONSTER M4SK Express, Hallowing M4, etc.
  - Seeeduino: Wio Terminal, Grove UI Wireless
  
 4. **Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0)**

 5. **ESP32**
 
  - ESP32 boards, such as `ESP32_DEV`, etc.
  - ESP32_S2-based boards, such as `ESP32S2_DEV`, `ESP32_S2 Saola`, etc.
  - ESP32_C3-based boards, such as `ESP32C3_DEV`, etc. **New**
  - ESP32_S3 (ESP32S3_DEV, ESP32_S3_BOX, UM TINYS3, UM PROS3, UM FEATHERS3, etc.) **New**

 6. **ESP8266**
 
 7. `RP2040-based` boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).

 8. **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet
 
 9. **STM32 boards with built-in Ethernet LAN8742A** such as :

  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet**
  - See [EthernetWebServer_STM32 Support and Test Results](https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
  
10. **STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 or ENC28J60 shields)**

	- Nucleo-144
	- Nucleo-64
	- Discovery
	- Generic STM32F0, STM32F1, STM32F2, STM32F3, STM32F4, STM32F7 (with 64+K Flash): x8 and up
	- STM32L0, STM32L1, STM32L4
	- STM32G0, STM32G4
	- STM32H7
	- STM32WB
	- STM32MP1
	- LoRa boards
	- 3-D printer boards
	- Generic Flight Controllers
	- Midatronics boards

11. **STM32 boards using Ethernet LAN8720** such as :

  - **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
  - **Discovery (DISCO_F746NG)**
  - **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

12. **RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040**, using `Ethernet` or `WiFiNINA`

13. **RP2040W boards, such as RASPBERRY_PI_PICO_W**, using `Cyw43439 WiFi` or `Ethernet`


---

#### Currently supported WiFi shields/modules

1. WiFiNINA using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. WiFi101 using [`WiFi101 library v0.16.1+`](https://github.com/arduino-libraries/WiFi101)
3. U-Blox W101, W102 using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
4. ESP8266-AT command using [`WiFiEspAT library`](https://github.com/jandrassy/WiFiEspAT)
5. ESP8266/ESP32-AT command using [`ESP_AT_Lib library`](https://github.com/khoih-prog/ESP_AT_Lib) and [`ESP8266_AT_WebServer`](ESP8266_AT_WebServer)
6. ESP32 and ESP8266 WiFi
7. **RP2040W built-in CYW43439 WiFi**

---

#### Currently supported Ethernet shields/modules

1. W5x00 using [`Ethernet_Generic`](https://github.com/khoih-prog/Ethernet_Generic) library
2. ENC28J60 using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
3. LAN8720 Ethernet used in WT32_ETH01 (ESP32 + LAN8720) boards
4. Teensy 4.1 built-in Ethernet using [`NativeEthernet`](https://github.com/vjmuzik/NativeEthernet) library
5. Teensy 4.1 built-in Ethernet using [`QNEthernet`](https://github.com/ssilverman/QNEthernet) library
6. `LAN8742A` or `LAN8720` using [`STM32Ethernet`](https://github.com/stm32duino/STM32Ethernet) and [`LwIP`](https://github.com/stm32duino/LwIP) libraries.

---
---

 
## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Teensy core v1.57+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards.
 3. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards. **Not yet**
 4. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 5. [`Adafruit SAMD core 1.7.10+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 6. [`Seeeduino SAMD core 1.8.3+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 7. [`Adafruit nRF52 v1.3.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
 8. [`ESP32 Core 2.0.5+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 9. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS.
10. [`ArduinoCore-mbed mbed_rp2040, mbed_nano, mbed_portenta core 3.3.0+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) **Portenta_H7, RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
11. [`Earle Philhower's arduino-pico core v2.6.0+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, RASPBERRY_PI_PICO_W, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
12. [`Arduino Core for STM32 v2.3.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest). Use STM32 core `v2.2.0` for LAN8720 or compile error.

13. [`WiFiNINA_Generic library v1.8.14-6+`](https://github.com/khoih-prog/WiFiNINA_Generic) if for WiFiNINA. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic).
14. [`EthernetWebServer library v2.2.3+`](https://github.com/khoih-prog/EthernetWebServer) if necessary to use Ethernet modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer)
15. [`EthernetWebServer_STM32 library v1.5.0+`](https://github.com/khoih-prog/EthernetWebServer_STM32) if necessary to use Ethernet modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32)
16. [`WebServer_WT32_ETH01 library v1.5.1+`](https://github.com/khoih-prog/WebServer_WT32_ETH01) if necessary to use WT32_ETH01 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_WT32_ETH01.svg?)](https://www.ardu-badge.com/WebServer_WT32_ETH01)
17. Depending on which Ethernet card you're using:
   - [`Ethernet_Generic library v2.6.1+`](https://github.com/khoih-prog/Ethernet_Generic) for W5100, W5200 and W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.  [![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Generic.svg)](https://github.com/khoih-prog/Ethernet_Generic/releases/latest)
   - [`EthernetENC library v2.0.3+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.12+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
   - [`STM32Ethernet library v1.3.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest). To be used with [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest).
   - [`NativeEthernet Library version stable111+`](https://github.com/vjmuzik/NativeEthernet) for Teensy 4.1 built-in Ethernet.
   - [`QNEthernet Library version v0.15.0+`](https://github.com/ssilverman/QNEthernet) Teensy 4.1 built-in Ethernet. **New**
   
18. [`WiFiWebServer library v1.9.5+`](https://github.com/khoih-prog/WiFiWebServer) if necessary to use certain WiFi/WiFiNINA features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
19. [`Modified WiFi101 Library v0.16.1+`](https://github.com/khoih-prog/WiFi101) to use SAMD MKR1000, etc. boards with WiFi101.
20. [`WebSockets_Generic library v2.16.0+`](https://github.com/khoih-prog/WebSockets_Generic) if necessary to use `MQTT-over-WebSockets` features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets_Generic.svg?)](https://www.ardu-badge.com/WebSockets_Generic)

---
---

## Installation

### Use Arduino Library Manager
The best and easiest way is to use `Arduino Library Manager`. Search for `MQTTPubSubClient_Generic`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/MQTTPubSubClient_Generic.svg?)](https://www.ardu-badge.com/MQTTPubSubClient_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**MQTTPubSubClient_Generic**](https://github.com/khoih-prog/MQTTPubSubClient_Generic) page.
2. Download the latest release `MQTTPubSubClient_Generic-master.zip`.
3. Extract the zip file to `MQTTPubSubClient_Generic-master` directory 
4. Copy whole `MQTTPubSubClient_Generic-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**MQTTPubSubClient_Generic** library](https://registry.platformio.org/libraries/khoih-prog/MQTTPubSubClient_Generic) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/MQTTPubSubClient_Generic/installation). Search for **MQTTPubSubClient_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.3.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0). 

Supposing the Adafruit nRF52 version is 1.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.19/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.19. These files must be copied into the directory:

- `./arduino-1.8.19/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.13) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.13).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.13. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.13/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.10) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.10). 

Supposing the Adafruit SAMD core version is 1.7.10. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.3) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3). 

Supposing the Seeeduino SAMD core version is 1.8.3. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.3.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.3.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.3.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.3.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.3.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/3.3.0/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/3.3.0/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/3.3.0
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 3.3.0. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/3.3.0/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


#### 10. For RTL8720DN boards using AmebaD core
 
 To avoid compile error relating to PROGMEM, you have to copy the file [Realtek AmebaD core pgmspace.h](Packages_Patches/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h) into Realtek AmebaD directory (~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h). 

Supposing the Realtek AmebaD core version is 3.1.4. This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/x.yy.zz/cores/ambd/avr/pgmspace.h`


#### 11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core
 
 To avoid compile error relating to SAMD21/SAMD51, you have to copy the file [ArduinoCore-fab-sam core pgmspace.h](Packages_Patches/Fab_SAM_Arduino/hardware/samd/1.7.0/boards.txt) into `ArduinoCore-fab-sam` samd directory (~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.7.0/boards.txt). 

Supposing the `ArduinoCore-fab-sam` samd core version is 1.7.0. This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.7.0/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/x.yy.zz/boards.txt`


#### 12. For Seeeduino RP2040 boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino RP2040 (XIAO RP2040, Wio RP2040 Mini) boards***, you have to copy the whole [Seeeduino RP2040 Packages_Patches](Packages_Patches/Seeeduino/hardware/rp2040/2.7.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2). 

Supposing the Seeeduino SAMD core version is 2.7.2. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/variants/Seeed_XIAO_RP2040/pins_arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/variants/Seeed_XIAO_RP2040/pins_arduino.h`


---
---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

You can also use the forked and modified library at [Patched Ethernet](https://github.com/khoih-prog/Ethernet)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)

You can also use the forked and modified library at [Patched EthernetLarge](https://github.com/khoih-prog/EthernetLarge)

#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

You can also use the forked and modified library at [Patched Ethernet2](https://github.com/khoih-prog/Ethernet2)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

You can also use the forked and modified library at [Patched Ethernet3](https://github.com/khoih-prog/Ethernet3)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.19/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

#### 8. For fixing ESP8266 compile error

To fix `ESP8266 compile error` such as

```
error: 'class EthernetClass' has no member named 'init'
Ethernet.init (USE_THIS_SS_PIN);
```

just rename the following file in ./arduino-1.8.19/hardware/esp8266com/esp8266/libraries/Ethernet directory

- From `Ethernet.h` to `Ethernet_ESP8266.h`


---
---


### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

    
---
---

### Usage

#### MQTT

```C++
#include <WiFi.h>
// or
// #include <Ethernet_Generic.h>
#include <MQTTPubSubClient_Generic.h>

WiFiClient client;
// or
// EthernetClient client;
MQTTPubSubClient mqttClient;

void setup()
{
  // start your network
  WiFi.begin("your-ssid", "your-password");
  // connect to host
  client.connect("public.cloud.shiftr.io", 1883);
  // initialize mqtt client
  mqttClient.begin(client);
  // connect to mqtt broker
  mqttClient.connect("arduino", "public", "public");

  // subscribe callback which is called when every packet has come
  mqttClient.subscribe([](const String & topic, const String & payload, const size_t size)
  {
    Serial.println("mqtt received: " + topic + " - " + payload);
  });

  // subscribe topic and callback which is called when /hello has come
  mqttClient.subscribe("/hello", [](const String & payload, const size_t size)
  {
    Serial.print("/hello ");
    Serial.println(payload);
  });
}

void loop()
{
  // should be called to trigger callbacks
  mqttClient.update();
  // publish message
  mqttClient.publish("/hello", "world");
  delay(1000);
}
```

#### MQTT over WebSocket

Just replace `WiFiClient` or `EthernetClient` to `WebSocketsClient`.

```C++
#include <WiFi.h>
#include <WebSocketsClient_Generic.h>  // include before MQTTPubSubClient_Generic.h
#include <MQTTPubSubClient_Generic.h>

WebSocketsClient client;
MQTTPubSubClient mqttClient;

void setup()
{
  // start your network
  WiFi.begin("your-ssid", "your-password");
  // connect to host with MQTT over WebSocket securely
  client.beginSSL("public.cloud.shiftr.io", 443);
  client.setReconnectInterval(2000);
  // initialize mqtt client
  mqttClient.begin(client);
  // connect to mqtt broker
  mqttClient.connect("arduino", "public", "public");

  // subscribe callback which is called when every packet has come
  mqttClient.subscribe([](const String & topic, const String & payload, const size_t size) 
  {
    Serial.println("mqtt received: " + topic + " - " + payload);
  });
  
  // subscribe topic and callback which is called when /hello has come
  mqttClient.subscribe("/hello", [](const String & payload, const size_t size) 
  {
    Serial.print("/hello ");
    Serial.println(payload);
  });
}

void loop() 
{
  // should be called to trigger callbacks
  mqttClient.update();
  // publish message
  mqttClient.publish("/hello", "world");
  delay(1000);
}
```

#### MQTT with Secure Connection

If your board supports secure connection with certificates, it is also supprted same as above. Please see [WiFiMQTTSecureAWS](examples/WiFi/WiFiMQTTSecureAWS) example for the detail.

```C++
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <MQTTPubSubClient_Generic.h>

const char AWS_CERT_CA[] =
  "-----BEGIN CERTIFICATE-----\n"
  "-----END CERTIFICATE-----\n";
const char AWS_CERT_PRIVATE[] =
  "-----BEGIN RSA PRIVATE KEY-----\n"
  "-----END RSA PRIVATE KEY-----\n";
const char AWS_CERT_CRT[] =
  "-----BEGIN CERTIFICATE-----\n"
  "-----END CERTIFICATE-----\n";

WiFiClientSecure client;
MQTTPubSubClient mqttClient;

void setup() 
{
  // start your network
  WiFi.begin("your-ssid", "your-password");
  // connect to aws endpoint with certificates and keys
  client.setCACert(AWS_CERT_CA);
  client.setCertificate(AWS_CERT_CRT);
  client.setPrivateKey(AWS_CERT_PRIVATE);
  client.connect("your-endpoint.iot.ap-somewhre.amazonaws.com", 8883);
  // initialize mqtt client
  mqttClient.begin(client);
  // connect to mqtt broker
  mqttClient.connect("your-device-name");

  // subscribe callback which is called when every packet has come
  mqttClient.subscribe([](const String & topic, const String & payload, const size_t size) 
  {
    Serial.println("mqtt received: " + topic + " - " + payload);
  });
  
  // subscribe topic and callback which is called when /hello has come
  mqttClient.subscribe("/hello", [](const String & payload, const size_t size) 
  {
    Serial.print("/hello ");
    Serial.println(payload);
  });
}

void loop() 
{
  // should be called to trigger callbacks
  mqttClient.update();
  // publish message
  mqttClient.publish("/hello", "aws");
  delay(1000);
}
```


#### Callback Signature

The following signature are available for callbacks.

```C++
// callback for every packet
void callback(const String& topic, const String& payload, const size_t size);
void callback(const String& topic, const char* payload, const size_t size);
void callback(const char* topic, const String& payload, const size_t size);
void callback(const const char* topic, const char* payload, const size_t size);

// callback for each topic
void callback(const String& payload, const size_t size);
void callback(const char* payload, const size_t size);
```


#### Send and Receive Buffer Size Management

The default send / receive buffer size is 128 and defined as below.

```C++
using MQTTPubSubClient = MQTTPubSub::PubSubClient<128>;
```

If you want to change the buffer, please create instance like this.

```C++
MQTTPubSub::PubSubClient<256> mqtt;
```

---

## APIs

```C++
void begin(ClientType& client);
bool connect(const String& client_id, const String& user = "", const String& pass = "");
bool disconnect();
bool update();

bool publish(const String& topic, const String& payload, const bool retained = false, int qos = 0);
bool publish(const String& topic, uint8_t* payload, const size_t length, const bool retained = false, const uint8_t qos = 0);

void subscribe(const global_callback_t& cb);
bool subscribe(const String& topic, const topic_callback_t& cb);
bool subscribe(const String& topic, const uint8_t qos, const topic_callback_t& cb);
bool unsubscribe(const String& topic);

void setClockSource(const MQTTClientClockSource& cb);
void setWill(const String& topic, const String& payload = "", const bool retained = false, const uint8_t qos = 0);
void clearWill();
void setKeepAliveSendInterval(const uint32_t ms);
void setKeepAliveTimeout(const uint16_t sec);
void setCleanSession(const bool b);
void setTimeout(const uint32_t ms);
void setOptions(const uint16_t keep_alive_timeout_sec, const bool b_clean_session, const uint32_t timeout_ms);

bool isConnected() const;
lwmqtt_err_t getLastError() const;
lwmqtt_return_code_t getReturnCode() const;
```


---
---

### HOWTO use STM32F4 with LAN8720

#### 1. Wiring

This is the Wiring for STM32F4 (BLACK_F407VE, etc.) using LAN8720


|LAN8720 PHY|<--->|STM32F4|
|:-:|:-:|:-:|
|TX1|<--->|PB_13|
|TX_EN|<--->|PB_11|
|TX0|<--->|PB_12|
|RX0|<--->|PC_4|
|RX1|<--->|PC_5|
|nINT/RETCLK|<--->|PA_1|
|CRS|<--->|PA_7|
|MDIO|<--->|PA_2|
|MDC|<--->|PC_1|
|GND|<--->|GND|
|VCC|<--->|+3.3V|

---

#### 2. HOWTO program using STLink V-2 or V-3

Connect as follows. To program, use **STM32CubeProgrammer** or Arduino IDE with 

- **U(S)ART Support: "Enabled (generic Serial)"**
- **Upload Method : "STM32CubeProgrammer (SWD)"**

- Jumper settings to program via STLInk

|From|<--->|To|
|:-:|:-:|:-:|
|BOOT0|<--->|3.3V|

- Jumper settings when running normally to avoid accidentally reprogram

|From|<--->|To|
|:-:|:-:|:-:|
|BOOT0|<--->|GND|

---

|STLink|<--->|STM32F4|
|:-:|:-:|:-:|
|SWCLK|<--->|SWCLK|
|SWDIO|<--->|SWDIO|
|RST|<--->|NRST|
|GND|<--->|GND|
|5v|<--->|5V|


<p align="center">
    <img src="https://github.com/khoih-prog/MQTTPubSubClient_Generic/blob/main/pics/STM32F407VET6.png">
</p>

---

#### 3. HOWTO use Serial Port for Debugging

Connect FDTI (USB to Serial) as follows:

|FDTI|<--->|STM32F4|
|:-:|:-:|:-:|
|RX|<--->|TX=PA_9|
|TX|<--->|RX=PA_10|
|GND|<--->|GND|



---
---

### Examples

#### 1. For Ethernet

 1. [EtherMQTT](examples/Ethernet/EtherMQTT)
 2. [EtherMQTToverWebSocket](examples/Ethernet/EtherMQTToverWebSocket)

#### 2. For QNEthernet

 1. [MQTToverWebSocket_QNEthernet](examples/QNEthernet/MQTToverWebSocket_QNEthernet)
 2. [MQTT_QNEthernet](examples/QNEthernet/MQTT_QNEthernet)

#### 3. For STM32

 1. [EtherMQTToverWebSocket_STM32](examples/STM32/EtherMQTToverWebSocket_STM32)
 2. [EtherMQTT_STM32](examples/STM32/EtherMQTT_STM32)
 
#### 4. For WiFi

 1. [WiFiMQTT](examples/WiFi/WiFiMQTT)
 2. [WiFiMQTToverWebSocket](examples/WiFi/WiFiMQTToverWebSocket)
 3. [WiFiMQTToverWebSocketSecure](examples/WiFi/WiFiMQTToverWebSocketSecure)
 4. [WiFiMQTTSecure](examples/WiFi/WiFiMQTTSecure)
 5. [WiFiMQTTSecureAWS](examples/WiFi/WiFiMQTTSecureAWS)
 
#### 5. For RP2040W

 1. [WiFiMQTT](examples/RP2040W/WiFiMQTT)
 2. [WiFiMQTToverWebSocket](examples/RP2040W/WiFiMQTToverWebSocket)
 3. [WiFiMQTTSecure](examples/RP2040W/WiFiMQTTSecure)
 4. [WiFiMQTTSecureAWS](examples/RP2040W/WiFiMQTTSecureAWS)

#### 6. For WiFiNINA

 1. [WiFiNINA_MQTT](examples/WiFiNINA/WiFiNINA_MQTT)
 2. [WiFiNINA_MQTToverWebSocket](examples/WiFiNINA/WiFiNINA_MQTToverWebSocket)
 3. [WiFiNINA_MQTToverWebSocketSecure](examples/WiFiNINA/WiFiNINA_MQTToverWebSocketSecure)
 4. [WiFiNINA_MQTTSecure](examples/WiFiNINA/WiFiNINA_MQTTSecure)
 5. [WiFiNINA_MQTTSecureAWS](examples/WiFiNINA/WiFiNINA_MQTTSecureAWS)
 
---
---

### Example [EtherMQTToverWebSocket](examples/Ethernet/EtherMQTToverWebSocket)

#### 1. File [EtherMQTToverWebSocket.ino](examples/Ethernet/EtherMQTToverWebSocket/EtherMQTToverWebSocket.ino)

https://github.com/khoih-prog/MQTTPubSubClient_Generic/blob/168f2ce72da6950d577d923e75529453c3f1ee4e/examples/Ethernet/EtherMQTToverWebSocket/EtherMQTToverWebSocket.ino#L17-L320


#### 2. File [defines.h](examples/Ethernet/EtherMQTToverWebSocket/defines.h)


https://github.com/khoih-prog/MQTTPubSubClient_Generic/blob/168f2ce72da6950d577d923e75529453c3f1ee4e/examples/Ethernet/EtherMQTToverWebSocket/defines.h#L16-L491


---
---

### Debug Terminal Output Samples

#### 1. WiFiMQTToverWebSocket on ESP8266_NODEMCU_ESP12E

This is terminal debug output when running [WiFiMQTToverWebSocket](examples/WiFi/WiFiMQTToverWebSocket) on **ESP8266_NODEMCU_ESP12E** connecting to `test.mosquitto.org` MQTT server.

```
Start WiFiMQTToverWebSocket on ESP8266_NODEMCU_ESP12E with ESP WiFi using WiFi Library
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.145
SSID: HueNet1, Signal strength (RSSI):-39 dBm
Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from ESP8266_NODEMCU_ESP12E
Subcribed to /mqttPubSub => Hello from ESP8266_NODEMCU_ESP12E
```

---

#### 2. WiFiMQTToverWebSocketSecure on ESP32_DEV

This is terminal debug output when running [WiFiMQTToverWebSocketSecure](examples/WiFi/WiFiMQTToverWebSocketSecure) on **ESP32_DEV** connecting to `public.cloud.shiftr.io:443` WebSockets server.

```
Start WiFiMQTToverWebSocketSecure on ESP32_DEV
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.93
SSID: HueNet1, Signal strength (RSSI):-35 dBm
Connecting to secured-host:port = public.cloud.shiftr.io:443
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from WiFiMQTToverWebSocketSecure on ESP32_DEV
Subcribed to /mqttPubSub => Hello from WiFiMQTToverWebSocketSecure on ESP32_DEV
```

---

#### 3. WiFiMQTToverWebSocket on SAMD_NANO_33_IOT

This is terminal debug output when running [WiFiMQTToverWebSocket](examples/WiFi/WiFiMQTToverWebSocket) on **SAMD_NANO_33_IOT** connecting to `test.mosquitto.org` MQTT server.

```
Start WiFiMQTToverWebSocket on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
WiFiWebServer v1.7.0
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.150
SSID: HueNet1, Signal strength (RSSI):-15 dBm
Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
Subcribed to /mqttPubSub => Hello from SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
```

---

#### 4. EtherMQTToverWebSocket on NUCLEO_F767ZI

This is terminal debug output when running [EtherMQTToverWebSocket](examples/Ethernet/EtherMQTToverWebSocket) on **STM32F7 NUCLEO_F767ZI** connecting to `test.mosquitto.org` MQTT server.


```
Start EtherMQTToverWebSocket_STM32 on NUCLEO_F767ZI with W5x00 using default Ethernet_Generic Library
EthernetWebServer_STM32 v1.4.0
MQTTPubSubClient_Generic v1.2.0
[EWS] Board : NUCLEO_F767ZI , setCsPin: 10
[EWS] Default SPI pinout:
[EWS] MOSI: 11
[EWS] MISO: 12
[EWS] SCK: 13
[EWS] SS: 10
[EWS] =========================
Connected! IP address: 192.168.2.135
Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from NUCLEO_F767ZI with W5x00 using default Ethernet_Generic Library
Subcribed to /mqttPubSub => Hello from NUCLEO_F767ZI with W5x00 using default Ethernet_Generic Library
MQTT received: /mqttPubSub - Hello from NUCLEO_F767ZI with W5x00 using default Ethernet_Generic Library
Subcribed to /mqttPubSub => Hello from NUCLEO_F767ZI with W5x00 using default Ethernet_Generic Library
```

---

#### 5. EtherMQTToverWebSocket_STM32 on NUCLEO_F767ZI

This is terminal debug output when running [EtherMQTToverWebSocket_STM32](examples/STM32/EtherMQTToverWebSocket_STM32) on **STM32F7 NUCLEO_F767ZI-ETH01 with LAN8742A** connecting to `test.mosquitto.org` MQTT server.


```
Start EtherMQTToverWebSocket_STM32 on NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
EthernetWebServer_STM32 v1.4.0
MQTTPubSubClient_Generic v1.2.0
Connected! IP address: 192.168.2.88
Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
Subcribed to /mqttPubSub => Hello from NUCLEO_F767ZI with LAN8742A Ethernet & STM32Ethernet Library
```

---

#### 6. MQTToverWebSocket_QNEthernet on TEENSY 4.1


This is terminal debug output when running [MQTToverWebSocket_QNEthernet](examples/QNEthernet/MQTToverWebSocket_QNEthernet) on **TEENSY 4.1 with QNEthernet** connecting to `test.mosquitto.org` MQTT server.

```
Start MQTToverWebSocket_QNEthernet on TEENSY 4.1
MQTTPubSubClient_Generic v1.2.0
=========== USE_QN_ETHERNET ===========
Initialize Ethernet using static IP => Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from TEENSY 4.1 using QNEthernet
Subcribed to /mqttPubSub => Hello from TEENSY 4.1 using QNEthernet
```

---


#### 7. EtherMQTToverWebSocket on MBED RASPBERRY_PI_PICO

This is terminal debug output when running [EtherMQTToverWebSocket](examples/Ethernet/EtherMQTToverWebSocket) on **MBED RASPBERRY_PI_PICO with W5500 Ethernet** connecting to `test.mosquitto.org` MQTT server.

```
Start EtherMQTToverWebSocket on MBED RASPBERRY_PI_PICO
EthernetWebServer v2.1.2
MQTTPubSubClient_Generic v1.2.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 17, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 17
Connected! IP address: 192.168.2.103
Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker...Done connected!
MQTT received: /mqttPubSub - Hello from MBED RASPBERRY_PI_PICO
Subcribed to /mqttPubSub => Hello from MBED RASPBERRY_PI_PICO
```

---


#### 8. EtherMQTToverWebSocket on RASPBERRY_PI_PICO


This is terminal debug output when running [EtherMQTToverWebSocket](examples/Ethernet/EtherMQTToverWebSocket) on **RASPBERRY_PI_PICO with W5500 Ethernet** connecting to `test.mosquitto.org` MQTT server.


```
Start EtherMQTToverWebSocket on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library on SPI1
EthernetWebServer v2.1.2
MQTTPubSubClient_Generic v1.2.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 15
[EWS] MISO: 12
[EWS] SCK: 14
[EWS] SS: 13
[EWS] =========================
[EWS] RPIPICO setCsPin: 13
[EWS] =========================
[EWS] Currently Used SPI pinout:
[EWS] MOSI: 15
[EWS] MISO: 12
[EWS] SCK: 14
[EWS] SS: 13
[EWS] =========================
Using mac index = 9
Connected! IP address: 192.168.2.115
Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library on SPI1
Subcribed to /mqttPubSub => Hello from RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library on SPI1
```

---


#### 9. EtherMQTToverWebSocket on TEENSY 4.0


This is terminal debug output when running [EtherMQTToverWebSocket](examples/Ethernet/EtherMQTToverWebSocket) on **TEENSY 4.0 with W5500 Ethernet** connecting to `test.mosquitto.org` MQTT server.


```
Start EtherMQTToverWebSocket on TEENSY 4.0 with W5x00 using Ethernet_Generic Library on SPI0/SPI
EthernetWebServer v2.1.2
MQTTPubSubClient_Generic v1.2.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 11
[EWS] MISO: 12
[EWS] SCK: 13
[EWS] SS: 10
[EWS] =========================
[EWS] Board : TEENSY 4.0 , setCsPin: 10
[EWS] =========================
[EWS] Currently Used SPI pinout:
[EWS] MOSI: 11
[EWS] MISO: 12
[EWS] SCK: 13
[EWS] SS: 10
[EWS] =========================
Using mac index = 4
Connected! IP address: 192.168.2.118
Connecting to WebSockets Server @ test.mosquitto.org
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from TEENSY 4.0 with W5x00 using Ethernet_Generic Library on SPI0/SPI
Subcribed to /mqttPubSub => Hello from TEENSY 4.0 with W5x00 using Ethernet_Generic Library on SPI0/SPI
```

---

#### 10. WiFiMQTT on RASPBERRY_PI_PICO_W

This is terminal debug output when running [WiFiMQTT](examples/RP2040W/WiFiMQTT) on **RASPBERRY_PI_PICO_W** connecting to `public.cloud.shiftr.io` MQTT server.

```
Start WiFiMQTT on RASPBERRY_PI_PICO_W
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.77
SSID: HueNet1, Signal strength (RSSI):0 dBm
Connecting to WebSockets Server @ public.cloud.shiftr.io, port 1883
Connected!
Connecting to mqtt broker... connected!
MQTT received: /mqttPubSub - Hello from RASPBERRY_PI_PICO_W
Subcribed to /mqttPubSub => Hello from RASPBERRY_PI_PICO_W
MQTT received: /mqttPubSub - Hello from RASPBERRY_PI_PICO_W
Subcribed to /mqttPubSub => Hello from RASPBERRY_PI_PICO_W
MQTT received: /mqttPubSub - Hello from RASPBERRY_PI_PICO_W
Subcribed to /mqttPubSub => Hello from RASPBERRY_PI_PICO_W
MQTT received: /mqttPubSub - Hello from RASPBERRY_PI_PICO_W
Subcribed to /mqttPubSub => Hello from RASPBERRY_PI_PICO_W
MQTT received: /mqttPubSub - Hello from RASPBERRY_PI_PICO_W
```

---

#### 11. WiFiMQTTSecure on RASPBERRY_PI_PICO_W

This is terminal debug output when running [WiFiMQTTSecure](examples/RP2040W/WiFiMQTTSecure) on **RASPBERRY_PI_PICO_W** connecting to `public.cloud.shiftr.io` MQTT server.

```
Start WiFiMQTTSecure on RASPBERRY_PI_PICO_W
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.77
SSID: HueNet1, Signal strength (RSSI):0 dBm
Connecting to secured-host:port = public.cloud.shiftr.io:8883

Connected!
Connecting to mqtt broker... connected!
MQTT received: /mqttPubSub - Hello from WiFiMQTTSecure on RASPBERRY_PI_PICO_W
Subcribed to /mqttPubSub => Hello from WiFiMQTTSecure on RASPBERRY_PI_PICO_W
```


---

#### 12. WiFiMQTToverWebSocket on RASPBERRY_PI_PICO_W

This is terminal debug output when running [WiFiMQTToverWebSocket](examples/RP2040W/WiFiMQTToverWebSocket) on **RASPBERRY_PI_PICO_W** connecting to `test.mosquitto.org` MQTT server.

```
Start WiFiMQTToverWebSocket on RASPBERRY_PI_PICO_W
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.77
SSID: HueNet1, Signal strength (RSSI):0 dBm
Connecting to WebSockets Server @ test.mosquitto.org, port 8080
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from RASPBERRY_PI_PICO_W
Subcribed to /mqttPubSub => Hello from RASPBERRY_PI_PICO_W
```


---

#### 13. WiFiNINA_MQTToverWebSocket on Nano_RP2040_Connect

This is terminal debug output when running [WiFiNINA_MQTToverWebSocket](examples/WiFiNINA/WiFiNINA_MQTToverWebSocket) on **NANO_RP2040_CONNECT**, with WiFiNINA using `WiFiNINA_Generic` Library and `arduino-pico` core, connecting to `test.mosquitto.org` MQTT server.

```
Start WiFiNINA_MQTToverWebSocket on NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
WiFiNINA_Generic v1.8.14-6
WiFiWebServer v1.9.5
WebSockets_Generic v2.16.0
MQTTPubSubClient_Generic v1.2.0
Please upgrade the firmware
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.105
SSID: HueNet1, Signal strength (RSSI):-27 dBm
Connecting to WebSockets Server @ test.mosquitto.org, port 8080
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
Subcribed to /mqttPubSub => Hello from NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
```

---

#### 14. WiFiNINA_MQTToverWebSocketSecure on Nano_RP2040_Connect

This is terminal debug output when running [WiFiNINA_MQTToverWebSocketSecure](examples/WiFiNINA/WiFiNINA_MQTToverWebSocketSecure) on **NANO_RP2040_CONNECT**, with WiFiNINA using `WiFiNINA_Generic` Library and `Arduino mbed_nano` core, connecting to `public.cloud.shiftr.io` Secured MQTT server.


```
Start WiFiNINA_MQTToverWebSocketSecure on Nano RP2040 Connect
WiFiNINA_Generic v1.8.14-6
WebSockets_Generic v2.16.0
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.105
SSID: HueNet1, Signal strength (RSSI):-30 dBm
Connecting to secured-host:port = public.cloud.shiftr.io:443
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from WiFiMQTToverWebSocketSecure on Nano RP2040 Connect
Subcribed to /mqttPubSub => Hello from WiFiMQTToverWebSocketSecure on Nano RP2040 Connect
```


---

#### 15. WiFiNINA_MQTToverWebSocketSecure on SAMD_NANO_33_IOT

This is terminal debug output when running [WiFiNINA_MQTToverWebSocketSecure](examples/WiFiNINA/WiFiNINA_MQTToverWebSocketSecure) on **SAMD_NANO_33_IOT**, with WiFiNINA using `WiFiNINA_Generic` Library, connecting to `public.cloud.shiftr.io` Secured MQTT server.

```
Start WiFiNINA_MQTToverWebSocketSecure on Nano RP2040 Connect
WiFiNINA_Generic v1.8.14-6
WebSockets_Generic v2.16.0
MQTTPubSubClient_Generic v1.2.0
Connecting to SSID: HueNet1
You're connected to the network, IP = 192.168.2.105
SSID: HueNet1, Signal strength (RSSI):-30 dBm
Connecting to secured-host:port = public.cloud.shiftr.io:443
Connecting to mqtt broker.... connected!
MQTT received: /mqttPubSub - Hello from WiFiMQTToverWebSocketSecure on Nano RP2040 Connect
Subcribed to /mqttPubSub => Hello from WiFiMQTToverWebSocketSecure on Nano RP2040 Connect
```


---
---

### Debug

Debug is enabled by default on Serial. Debug Level from 0 to 4. To disable, change the _MQTT_PUBSUB_LOGLEVEL_ to 0

```cpp
#define MQTT_PUBSUB_DEBUG_PORT              Serial

// Debug Level from 0 to 4
#define _MQTT_PUBSUB_LOGLEVEL_              1
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---


### Issues ###

Submit issues to: [MQTTPubSubClient_Generic issues](https://github.com/khoih-prog/MQTTPubSubClient_Generic/issues)

---
---

### TO DO

 1. Support Portenta_H7, SAM-DUE, megaAVR, etc.
 2. Bug fixing.

---

### DONE

 1. Add support to **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**
 2. Add support to **Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.)**.
 3. Add support to **Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**.
 5. Add support to Ethernet W5x00, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/adafruit/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 6. Add support to Ethernet ENC28J60, using [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
 7. Add support to ESP32 and ESP8266
 8. Add support to Seeeduino SAMD21/SAMD51: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, Wio Terminal, Grove UI Wireless
 9. Add support to [`EthernetENC`](https://github.com/jandrassy/EthernetENC)
10. Add support to RP2040-based boards such as RASPBERRY_PI_PICO, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)
11. Add support to RP2040-based boards such as RASPBERRY_PI_PICO, using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico)
12. Add support to Teensy 4.1 built-in Ethernet using [`NativeEthernet`](https://github.com/vjmuzik/NativeEthernet) library
13. Add support to Teensy 4.1 built-in Ethernet using [`QNEthernet`](https://github.com/ssilverman/QNEthernet) library
14. Add support to SAMD21/SAMD51 boards using [Fab_SAM_Arduino core](https://github.com/qbolsee/ArduinoCore-fab-sam)
15. Use new [**Ethernet_Generic** library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
16. Support **SPI2 for ESP32**
17. Add support to **SPI1 for RP2040** using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
18. Use new `waitForLink()` function of QNEthernet
19. Add support to `RP2040W` using `MQTT`, `Secured MQTT` or `MQTT-over-WebSockets` with [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
20. Add support to `Nano_RP2040_Connect`, `Nano_33_IoT`, using `MQTT`, `Secured MQTT`, `MQTT-over-WebSockets` or `Secured MQTT-over-WebSockets` with [`WiFiNINA_Generic` library](https://github.com/khoih-prog/WiFiNINA_Generic) library

---
---

### Contributions and Thanks

1. Based on and modified from 

- [**Joël Gähwiler's lwmqtt Library**](https://github.com/256dpi/lwmqtt)
- [**Joël Gähwiler's async-mqtt Library**](https://github.com/256dpi/arduino-mqtt)
- [**Hideaki Tai's MQTTPubSubClient Library**](https://github.com/hideakitai/MQTTPubSubClient)


<table>
  <tr>
    <td align="center"><a href="https://github.com/256dpi"><img src="https://github.com/256dpi.png" width="100px;" alt="256dpi"/><br /><sub><b>⭐️ Joël Gähwiler</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/hideakitai"><img src="https://github.com/hideakitai.png" width="100px;" alt="hideakitai"/><br /><sub><b>⭐️ Hideaki Tai</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---
---

### License

- Many of the credits go to original authors 
	- [Joël Gähwiler](https://github.com/256dpi)
	- [Hideaki Tai](https://github.com/hideakitai)

- The library is licensed under [MIT](https://github.com/khoih-prog/MQTTPubSubClient_Generic/blob/main/LICENSE)

---

## Copyright

1. Copyright (c) 2017- Joël Gähwiler
2. Copyright (c) 2021- Hideaki Tai
3. Copyright (c) 2022- Khoi Hoang

