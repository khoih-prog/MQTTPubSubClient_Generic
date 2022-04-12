/****************************************************************************************************************************
  EtherMQTToverWebSocket_STM32.ino
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

void initEthernet()
{
#if !(USE_BUILTIN_ETHERNET)
  ET_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);

  ET_LOGWARN(F("Default SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"),  SCK);
  ET_LOGWARN1(F("SS:"),   SS);
  ET_LOGWARN(F("========================="));
#endif

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
  Ethernet.init (USE_THIS_SS_PIN);

  #elif USE_CUSTOM_ETHERNET
  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  //Ethernet.init(USE_THIS_SS_PIN);

  #endif  //( ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
#endif

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());  
}

void setup() 
{
  // Debug console
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStart EtherMQTToverWebSocket_STM32 on "); Serial.print(BOARD_NAME);
  Serial.print(" with "); Serial.println(SHIELD_TYPE);
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);
  Serial.println(MQTT_PUBSUB_CLIENT_GENERIC_VERSION);

  initEthernet();

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
