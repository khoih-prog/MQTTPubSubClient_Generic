# MQTTPubSubClient_Generic client for ESP8266, ESP32, etc.

[![arduino-library-badge](https://www.ardu-badge.com/badge/MQTTPubSubClient_Generic.svg?)](https://www.ardu-badge.com/MQTTPubSubClient_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/MQTTPubSubClient_Generic.svg)](https://github.com/khoih-prog/MQTTPubSubClient_Generic/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/MQTTPubSubClient_Generic.svg)](http://github.com/khoih-prog/MQTTPubSubClient_Generic/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.0.1](#releases-v101)
  * [Initial Releases v1.0.0](#Initial-Releases-v100)

---
---

## Changelog

### Releases v1.0.1

1. Use new [Ethernet_Generic library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
2. Add support to SPI1 for RP2040 using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
3. Rewrite all the examples to support new features
4. Use new `waitForLink()` function of QNEthernet
5. Update `Packages' Patches`

### Initial Releases v1.0.0

1. Initial porting and coding to support nRF52, SAMD21, SAMD51, STM32F/L/H/G/WB/MP1, Teensy, RP2040-based boards, besides ESP8266, ESP32 (ESP32, ESP32_S2, ESP32_S3 and ESP32_C3) and WT32_ETH01. Spporting Ethernet shields W5100, W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet/QNEthernet.


