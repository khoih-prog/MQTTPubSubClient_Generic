/****************************************************************************************************************************
  MQTTPubSubClient_Generic_Debug.h
  
  MQTT and MQTT over WebSoket Client for Arduino
  
  For nRF52, SAMD21, SAMD51, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, RP2040-based boards, besides ESP8266, 
  ESP32 (ESP32, ESP32_S2, ESP32_S3 and ESP32_C3) and WT32_ETH01
  
  Ethernet shields W5100, W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet/QNEthernet.
   
  Based on and modified from MQTTPubSubClient Library (https://github.com/hideakitai/MQTTPubSubClient)
  
  Built by Khoi Hoang https://github.com/khoih-prog/MQTTPubSubClient_Generic
  Licensed under MIT license
  
  Version: 1.2.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0    K Hoang     23/03/2022 Initial porting and coding to add support to many boards, using Ethernet or WiFi
  1.0.1    K Hoang     11/04/2022 Use Ethernet_Generic library as default. Support SPI1/SPI2 for RP2040/ESP32
  1.1.0    K Hoang     13/10/2022 Add support to RP2040W using CYW43439 WiFi
  1.2.0    K Hoang     14/10/2022 Add support to Nano_RP2040_Connect using WiFiNINA
 *****************************************************************************************************************************/

#pragma once

#ifndef MQTT_PUBSUB_CLIENT_DEBUG_H
#define MQTT_PUBSUB_CLIENT_DEBUG_H

#ifdef MQTT_PUBSUB_DEBUG_PORT
  #define DBG_PORT_MQTT      MQTT_PUBSUB_DEBUG_PORT
#else
  #define DBG_PORT_MQTT      Serial
#endif

// Change _MQTT_PUBSUB_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _MQTT_PUBSUB_LOGLEVEL_
  #define _MQTT_PUBSUB_LOGLEVEL_       1
#endif

/////////////////////////////////////////////////////////

#define MQTT_PRINT_MARK      MQTT_PRINT("[MQTT] ")
#define MQTT_PRINT_SP        DBG_PORT_MQTT.print(" ")
#define MQTT_PRINT_SP0X      DBG_PORT_MQTT.print(" 0x")

#define MQTT_PRINT           DBG_PORT_MQTT.print
#define MQTT_PRINTLN         DBG_PORT_MQTT.println
#define MQTT_PRINTF          DBG_PORT_MQTT.printf

/////////////////////////////////////////////////////////

#define MQTT_DEBUG(...) 				if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINTF(__VA_ARGS__); }
#define MQTT_SSL_DEBUG(...) 		if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINTF(__VA_ARGS__); }

#define MQTT_ASSERT( a )        do{ if(!(a)){MQTT_PRINTF("ASSERT: %s %u \n", __FILE__, __LINE__);}}while(0)

/////////////////////////////////////////////////////////

#define MQTT_LOGERROR(x)         if(_MQTT_PUBSUB_LOGLEVEL_>0) { MQTT_PRINT_MARK; MQTT_PRINTLN(x); }
#define MQTT_LOGERROR0(x)        if(_MQTT_PUBSUB_LOGLEVEL_>0) { MQTT_PRINT(x); }
#define MQTT_LOGERROR1(x,y)      if(_MQTT_PUBSUB_LOGLEVEL_>0) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINTLN(y); }
#define MQTT_HEXLOGERROR1(x,y)   if(_MQTT_PUBSUB_LOGLEVEL_>0) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINTLN(y, HEX); }
#define MQTT_LOGERROR2(x,y,z)    if(_MQTT_PUBSUB_LOGLEVEL_>0) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINTLN(z); }
#define MQTT_HEXLOGERROR2(x,y,z) if(_MQTT_PUBSUB_LOGLEVEL_>0) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINT(y, HEX); MQTT_PRINT_SP0X; MQTT_PRINTLN(z, HEX); }
#define MQTT_LOGERROR3(x,y,z,w)  if(_MQTT_PUBSUB_LOGLEVEL_>0) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINT(z); MQTT_PRINT_SP; MQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define MQTT_LOGWARN(x)          if(_MQTT_PUBSUB_LOGLEVEL_>1) { MQTT_PRINT_MARK; MQTT_PRINTLN(x); }
#define MQTT_LOGWARN0(x)         if(_MQTT_PUBSUB_LOGLEVEL_>1) { MQTT_PRINT(x); }
#define MQTT_LOGWARN1(x,y)       if(_MQTT_PUBSUB_LOGLEVEL_>1) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINTLN(y); }
#define MQTT_HEXLOGWARN1(x,y)    if(_MQTT_PUBSUB_LOGLEVEL_>1) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINTLN(y, HEX); }
#define MQTT_LOGWARN2(x,y,z)     if(_MQTT_PUBSUB_LOGLEVEL_>1) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINTLN(z); }
#define MQTT_HEXLOGWARN2(x,y,z)  if(_MQTT_PUBSUB_LOGLEVEL_>1) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINT(y, HEX); MQTT_PRINT_SP0X; MQTT_PRINTLN(z, HEX); }
#define MQTT_LOGWARN3(x,y,z,w)   if(_MQTT_PUBSUB_LOGLEVEL_>1) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINT(z); MQTT_PRINT_SP; MQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define MQTT_LOGINFO(x)          if(_MQTT_PUBSUB_LOGLEVEL_>2) { MQTT_PRINT_MARK; MQTT_PRINTLN(x); }
#define MQTT_LOGINFO0(x)         if(_MQTT_PUBSUB_LOGLEVEL_>2) { MQTT_PRINT(x); }
#define MQTT_LOGINFO1(x,y)       if(_MQTT_PUBSUB_LOGLEVEL_>2) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINTLN(y); }
#define MQTT_HEXLOGINFO1(x,y)    if(_MQTT_PUBSUB_LOGLEVEL_>2) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINTLN(y, HEX); }
#define MQTT_LOGINFO2(x,y,z)     if(_MQTT_PUBSUB_LOGLEVEL_>2) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINTLN(z); }
#define MQTT_HEXLOGINFO2(x,y,z)  if(_MQTT_PUBSUB_LOGLEVEL_>2) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINT(y, HEX); MQTT_PRINT_SP0X; MQTT_PRINTLN(z, HEX); }
#define MQTT_LOGINFO3(x,y,z,w)   if(_MQTT_PUBSUB_LOGLEVEL_>2) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINT(z); MQTT_PRINT_SP; MQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define MQTT_LOGDEBUG(x)         if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINT_MARK; MQTT_PRINTLN(x); }
#define MQTT_LOGDEBUG0(x)        if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINT(x); }
#define MQTT_LOGDEBUG1(x,y)      if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINTLN(y); }
#define MQTT_HEXLOGDEBUG1(x,y)   if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINTLN(y, HEX); }
#define MQTT_LOGDEBUG2(x,y,z)    if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINTLN(z); }
#define MQTT_HEXLOGDEBUG2(x,y,z) if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP0X; MQTT_PRINT(y, HEX); MQTT_PRINT_SP0X; MQTT_PRINTLN(z, HEX); }
#define MQTT_LOGDEBUG3(x,y,z,w)  if(_MQTT_PUBSUB_LOGLEVEL_>3) { MQTT_PRINT_MARK; MQTT_PRINT(x); MQTT_PRINT_SP; MQTT_PRINT(y); MQTT_PRINT_SP; MQTT_PRINT(z); MQTT_PRINT_SP; MQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#endif    //MQTT_PUBSUB_CLIENT_DEBUG_H
