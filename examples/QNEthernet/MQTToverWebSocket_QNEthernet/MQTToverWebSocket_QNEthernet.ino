/****************************************************************************************************************************
  MQTToverWebSocket_QNEthernet.ino
  MQTT and MQTT over WebSoket Client for Arduino
  
  For nRF52, SAMD21, SAMD51, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, RP2040-based boards, besides ESP8266, 
  ESP32 (ESP32, ESP32_S2, ESP32_S3 and ESP32_C3) and WT32_ETH01
  
  Ethernet shields W5100, W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet/QNEthernet.
   
  Based on and modified from MQTTPubSubClient Library (https://github.com/hideakitai/MQTTPubSubClient)
  
  Built by Khoi Hoang https://github.com/khoih-prog/MQTTPubSubClient_Generic
  Licensed under MIT license
 ***************************************************************************************************************************************/
#include "defines.h"

#define MQTTPUBSUBCLIENT_USE_WEBSOCKETS     true

//#include <WebSocketsClient.h>  // include before MQTTPubSubClient.h
#include <WebSocketsClient_Generic.h>  // include before MQTTPubSubClient.h

#define MQTTPUBSUBCLIENT_USE_WEBSOCKETS     true

#include <MQTTPubSubClient_Generic.h>

WebSocketsClient client;

MQTTPubSubClient mqttClient;

//#define WS_SERVER         "192.168.2.30"
#define WS_SERVER           "test.mosquitto.org"
#define WS_PORT             8080

const char *PubTopic    = "/mqttPubSub";                                  // Topic to publish
const char *PubMessage  = "Hello from " BOARD_NAME " with " SHIELD_TYPE;       // Topic Message to publish


void setup() 
{
  // Debug console
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStart MQTToverWebSocket_QNEthernet on "); Serial.print(BOARD_NAME);
  Serial.print(" with "); Serial.println(SHIELD_TYPE);
  Serial.println(MQTT_PUBSUB_CLIENT_GENERIC_VERSION);

#if USE_NATIVE_ETHERNET
  Serial.println(F("======== USE_NATIVE_ETHERNET ========"));
#elif USE_QN_ETHERNET
  Serial.println(F("=========== USE_QN_ETHERNET ==========="));
#endif

#if USE_NATIVE_ETHERNET

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.println(F("========================="));

  Serial.print("Using mac index ="); Serial.println(index);
  Serial.print("Connected! IP address:"); Serial.println(Ethernet.localIP());

#else

  #if USING_DHCP
    // Start the Ethernet connection, using DHCP
    Serial.print("Initialize Ethernet using DHCP => ");
    Ethernet.begin();
  #else   
    // Start the Ethernet connection, using static IP
    Serial.print("Initialize Ethernet using static IP => ");
    Ethernet.begin(myIP, myNetmask, myGW);
    Ethernet.setDNSServerIP(mydnsServer);
  #endif

  if (!Ethernet.waitForLocalIP(5000))
  {
    Serial.println(F("Failed to configure Ethernet"));

    if (!Ethernet.linkStatus())
    {
      Serial.println(F("Ethernet cable is not connected."));
    }

    // Stay here forever
    while (true)
    {
      delay(1);
    }
  }

  if (!Ethernet.waitForLink(5000))
  {
    Serial.println(F("Failed to wait for Link"));
  }

#endif

  // server address, port and URL
  Serial.print("Connecting to WebSockets Server @ ");
  Serial.println(WS_SERVER);

  client.begin(WS_SERVER, WS_PORT, "/", "mqtt");  // "mqtt" is required
  
  client.setReconnectInterval(2000);

  // initialize mqtt client
  mqttClient.begin(client);

  Serial.print("Connecting to mqtt broker...");

  while (!mqttClient.connect("arduino", "public", "public"))
  {
    Serial.print(".");
    delay(1000);
  }

  Serial.println(" connected!");

  // subscribe callback which is called when every packet has come
  mqttClient.subscribe([](const String & topic, const String & payload, const size_t size)
  {
    (void) size;
    
    Serial.println("MQTT received: " + topic + " - " + payload);
  });

  // subscribe topic and callback which is called when /hello has come
  mqttClient.subscribe(PubTopic, [](const String & payload, const size_t size)
  {
    (void) size;
    
    Serial.print("Subcribed to ");
    Serial.print(PubTopic); Serial.print(" => ");
    Serial.println(payload);
  });

  mqttClient.publish(PubTopic, PubMessage);
}

void loop() 
{
  mqttClient.update();  // should be called

  // publish message
  static uint32_t prev_ms = millis();
  
  if (millis() > prev_ms + 30000) 
  {
    prev_ms = millis();
    mqttClient.publish(PubTopic, PubMessage);
  }
}
