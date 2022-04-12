/****************************************************************************************************************************
  defines.h
  MQTT and MQTT over WebSoket Client for Arduino
  
  For nRF52, SAMD21, SAMD51, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, RP2040-based boards, besides ESP8266, 
  ESP32 (ESP32, ESP32_S2, ESP32_S3 and ESP32_C3) and WT32_ETH01
  
  Ethernet shields W5100, W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet/QNEthernet.
   
  Based on and modified from MQTTPubSubClient Library (https://github.com/hideakitai/MQTTPubSubClient)
  
  Built by Khoi Hoang https://github.com/khoih-prog/MQTTPubSubClient_Generic
  Licensed under MIT license
 ***************************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(CORE_TEENSY) && defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) ) 
  // For Teensy 4.1
  #define BOARD_TYPE      "TEENSY 4.1"
  // Use true for NativeEthernet Library, false if using other Ethernet libraries
  #define USE_NATIVE_ETHERNET     false
  #define USE_QN_ETHERNET         true
#else
  #error Only Teensy 4.1 supported
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     1

// Only one of the following to be true.
// Only one of the following to be true.
#define USE_ETHERNET_GENERIC      false
#define USE_ETHERNET_ESP8266      false
#define USE_ETHERNET_ENC          false
#define USE_ETHERNET_LAN8742A     false
#define USE_UIP_ETHERNET          false
#define USE_CUSTOM_ETHERNET       false

#if USE_NATIVE_ETHERNET
  #define WEBSOCKETS_NETWORK_TYPE   NETWORK_NATIVEETHERNET
  
  #include "NativeEthernet.h"
  #warning Using NativeEthernet lib for Teensy 4.1. Must also use Teensy Packages Patch or error
  #define SHIELD_TYPE           "using NativeEthernet"
#elif USE_QN_ETHERNET
  #define WEBSOCKETS_NETWORK_TYPE   NETWORK_QN_ETHERNET
  
  #include "QNEthernet.h"       // https://github.com/ssilverman/QNEthernet
  using namespace qindesign::network;
  #warning Using QNEthernet lib for Teensy 4.1. Must also use Teensy Packages Patch or error
  #define SHIELD_TYPE           "using QNEthernet"  
#endif

#if USE_NATIVE_ETHERNET
  // Enter a MAC address and IP address for your controller below.
  #define NUMBER_OF_MAC      20
  
  byte mac[][NUMBER_OF_MAC] =
  {
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
  };

#else

  #define USING_DHCP    false   //true
  
  #if !USING_DHCP
    // Set the static IP address to use if the DHCP fails to assign
    IPAddress myIP(192, 168, 2, 222);
    IPAddress myNetmask(255, 255, 255, 0);
    IPAddress myGW(192, 168, 2, 1);
    //IPAddress mydnsServer(192, 168, 2, 1);
    IPAddress mydnsServer(8, 8, 8, 8);
  #endif

#endif

#else

#if ( defined(CORE_TEENSY) && defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) ) 
  // For Teensy 4.1
  #define BOARD_TYPE      "TEENSY 4.1"
  // Use true for NativeEthernet Library, false if using other Ethernet libraries
  #define USE_NATIVE_ETHERNET     false
  #define USE_QN_ETHERNET         true
#else
  #error Only Teensy 4.1 supported
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define USE_ETHERNET_WRAPPER    false

// Use true  for ENC28J60 and UIPEthernet library (https://github.com/UIPEthernet/UIPEthernet)
// Use false for W5x00 and Ethernetx library      (https://www.arduino.cc/en/Reference/Ethernet)

#define USE_UIP_ETHERNET      false
#define USE_ETHERNET          false
#define USE_ETHERNET2         false
#define USE_ETHERNET3         false
#define USE_ETHERNET_LARGE    false
#define USE_ETHERNET_ESP8266  false 
#define USE_ETHERNET_ENC      false
#define USE_CUSTOM_ETHERNET   false

#if USE_NATIVE_ETHERNET
  #include "NativeEthernet.h"
  #warning Using NativeEthernet lib for Teensy 4.1. Must also use Teensy Packages Patch or error
  #define SHIELD_TYPE           "using NativeEthernet"
#elif USE_QN_ETHERNET
  #include "QNEthernet.h"       // https://github.com/ssilverman/QNEthernet
  using namespace qindesign::network;
  #warning Using QNEthernet lib for Teensy 4.1. Must also use Teensy Packages Patch or error
  #define SHIELD_TYPE           "using QNEthernet"  
#endif
  
#include <EthernetWebServer.h>

#if USE_NATIVE_ETHERNET
  // Enter a MAC address and IP address for your controller below.
  #define NUMBER_OF_MAC      20
  
  byte mac[][NUMBER_OF_MAC] =
  {
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
    { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
  };

#endif

#endif    //defines_h
