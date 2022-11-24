# MQTTPubSubClient_Generic Library (MQTT Client for ESP8266, ESP32, etc.)

[![arduino-library-badge](https://www.ardu-badge.com/badge/MQTTPubSubClient_Generic.svg?)](https://www.ardu-badge.com/MQTTPubSubClient_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/MQTTPubSubClient_Generic.svg)](https://github.com/khoih-prog/MQTTPubSubClient_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/MQTTPubSubClient_Generic/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/MQTTPubSubClient_Generic.svg)](http://github.com/khoih-prog/MQTTPubSubClient_Generic/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>
<a href="https://profile-counter.glitch.me/khoih-prog/count.svg" title="Total khoih-prog Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog/count.svg" style="height: 30px;width: 200px;"></a>
<a href="https://profile-counter.glitch.me/khoih-prog-MQTTPubSubClient_Generic/count.svg" title="MQTTPubSubClient_Generic Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog-MQTTPubSubClient_Generic/count.svg" style="height: 30px;width: 200px;"></a>

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.2.1](#releases-v121)
  * [Releases v1.2.0](#releases-v120)
  * [Releases v1.1.0](#releases-v110)
  * [Releases v1.0.1](#releases-v101)
  * [Initial Releases v1.0.0](#Initial-Releases-v100)

---
---

## Changelog

### Releases v1.2.1

1. Add support to `MKRWiFi1010`, etc., using `MQTT`, `MQTT-over-WebSockets` with new [`WiFi101_Generic` library](https://github.com/khoih-prog/WiFi101_Generic) library
2. Add [WiFi101 examples](https://github.com/khoih-prog/MQTTPubSubClient_Generic/tree/main/examples/WiFi101)

### Releases v1.2.0

1. Add support to `Nano_RP2040_Connect`, `Nano_33_IoT`, using `MQTT`, `Secured MQTT`, `MQTT-over-WebSockets` or `Secured MQTT-over-WebSockets` with [`WiFiNINA_Generic` library](https://github.com/khoih-prog/WiFiNINA_Generic) library
2. Add [WiFiNINA examples](https://github.com/khoih-prog/MQTTPubSubClient_Generic/tree/main/examples/WiFiNINA)

### Releases v1.1.0

1. Add support to `RP2040W` using `MQTT`, `Secured MQTT` or `MQTT-over-WebSockets` with [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
2. Add [RP2040W examples](https://github.com/khoih-prog/MQTTPubSubClient_Generic/tree/main/examples/RP2040W)
3. Update `Packages' Patches`

### Releases v1.0.1

1. Use new [Ethernet_Generic library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
2. Add support to SPI1 for RP2040 using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
3. Rewrite all the examples to support new features
4. Use new `waitForLink()` function of QNEthernet
5. Update `Packages' Patches`

### Initial Releases v1.0.0

1. Initial porting and coding to support nRF52, SAMD21, SAMD51, STM32F/L/H/G/WB/MP1, Teensy, RP2040-based boards, besides ESP8266, ESP32 (ESP32, ESP32_S2, ESP32_S3 and ESP32_C3) and WT32_ETH01. Supporting Ethernet shields W5100, W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet/QNEthernet.


