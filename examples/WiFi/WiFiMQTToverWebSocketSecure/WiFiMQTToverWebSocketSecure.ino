/****************************************************************************************************************************
  WiFiMQTToverWebSocketSecure.ino

  MQTT and MQTT over WebSoket Client for Arduino

  For nRF52, SAMD21, SAMD51, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, RP2040-based boards, besides ESP8266,
  ESP32 (ESP32, ESP32_S2, ESP32_S3 and ESP32_C3) and WT32_ETH01

  Ethernet shields W5100, W5200, W5500, ENC28J60, Teensy 4.1 NativeEthernet/QNEthernet.

  Based on and modified from MQTTPubSubClient Library (https://github.com/hideakitai/MQTTPubSubClient)

  Built by Khoi Hoang https://github.com/khoih-prog/MQTTPubSubClient_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#if !( defined(ESP8266) ||  defined(ESP32) )
  #error This code is intended to run on the ESP8266 or ESP32 platform! Please check your Tools->Board setting.
#endif

#if defined(ESP32)
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

#define _MQTT_PUBSUB_LOGLEVEL_              1

#include <WebSocketsClient_Generic.h>  // include before MQTTPubSubClient.h

#include <MQTTPubSubClient_Generic.h>

char ssid[] = "YOUR_SSID";        // your network SSID (name)
char pass[] = "12345678";         // your network password

int status = WL_IDLE_STATUS;     // the Wifi radio's status

WebSocketsClient client;
MQTTPubSubClient mqttClient;

//#define WS_SERVER         "192.168.2.30"
#define WS_SERVER           "public.cloud.shiftr.io"
#define WS_PORT             443

// Topic to publish
const char *PubTopic    = "/mqttPubSub";

// Topic Message to publish
const char *PubMessage  = "Hello from WiFiMQTToverWebSocketSecure on " ARDUINO_BOARD;

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
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print(F("\nStart WiFiMQTToverWebSocketSecure on ")); Serial.println(ARDUINO_BOARD);
  Serial.println(MQTT_PUBSUB_CLIENT_GENERIC_VERSION);

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

  Serial.print("Connecting to secured-host:port = "); Serial.print(WS_SERVER); 
  Serial.print(":"); Serial.println(WS_PORT); 
  
  client.beginSSL(WS_SERVER, WS_PORT); 
  
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
