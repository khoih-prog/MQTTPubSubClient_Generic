/****************************************************************************************************************************
  WiFiNINA_MQTToverWebSocket.ino
  
  MQTT and MQTT over WebSoket Client for Arduino
  
  For nRF52, SAMD21, SAMD51, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, RP2040-based boards, besides ESP8266, 
  ESP32 (ESP32, ESP32_S2, ESP32_S3 and ESP32_C3) and WT32_ETH01
  
  Ethernet shields W5100, W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet/QNEthernet.
   
  Based on and modified from MQTTPubSubClient Library (https://github.com/hideakitai/MQTTPubSubClient)
  
  Built by Khoi Hoang https://github.com/khoih-prog/MQTTPubSubClient_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
 
#include "defines.h"

#define WEBSOCKETS_NETWORK_TYPE     NETWORK_WIFININA

// Important to extend to min 10s, or can't connect using default 5s
#define WEBSOCKETS_TCP_TIMEOUT        20000L

#include <WebSocketsClient_Generic.h>  // include before MQTTPubSubClient.h

#define MQTTPUBSUBCLIENT_USE_WEBSOCKETS     true

#include <MQTTPubSubClient_Generic.h>

WebSocketsClient client;

//MQTTPubSub::PubSubClient<256> mqttClient;
MQTTPubSubClient mqttClient;

//#define WS_SERVER         "192.168.2.30"
#define WS_SERVER           "test.mosquitto.org"
#define WS_PORT             8080

const char *PubTopic    = "/mqttPubSub";                // Topic to publish
const char *PubMessage  = "Hello from " BOARD_NAME " with " SHIELD_TYPE;     // Topic Message to publish

int status = WL_IDLE_STATUS;     // the Wifi radio's status

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(WiFi.localIP());

  Serial.print(F("SSID: "));
  Serial.print(WiFi.SSID());

  // print the received signal strength:
  int32_t rssi = WiFi.RSSI();
  Serial.print(F(", Signal strength (RSSI):"));
  Serial.print(rssi);
  Serial.println(F(" dBm"));
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print(F("\nStart WiFiNINA_MQTToverWebSocket on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(WIFININA_GENERIC_VERSION);
  Serial.println(WIFI_WEBSERVER_VERSION);
  Serial.println(WEBSOCKETS_GENERIC_VERSION);
  Serial.println(MQTT_PUBSUB_CLIENT_GENERIC_VERSION);

/////////////////////////////////////
 
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println(F("Please upgrade the firmware"));
  }
  
  Serial.print(F("Connecting to SSID: "));
  Serial.println(ssid);
  
  status = WiFi.begin(ssid, pass);

  delay(1000);
   
  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED)
  {
    delay(500);
        
    // Connect to WPA/WPA2 network
    status = WiFi.status();
  }

  // you're connected now, so print out the data
  printWifiStatus();

  /////////////////////////////////////

  // server address, port and URL
  Serial.print("Connecting to WebSockets Server @ "); Serial.print(WS_SERVER);
  Serial.print(", port "); Serial.println(WS_PORT);

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
    Serial.println("MQTT received: " + topic + " - " + payload);
  });

  // subscribe topic and callback which is called when /hello has come
  mqttClient.subscribe(PubTopic, [](const String & payload, const size_t size)
  {
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
