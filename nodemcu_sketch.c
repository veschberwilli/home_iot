#include "DHT.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define DHT22PIN D2
DHT dht22(DHT22PIN, DHT22);

// Update these with values suitable for your network.
const char* ssid = "xxx";
const char* password = "xxx";
const char* mqtt_server = "192.168.1.100";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {
   delay(100);
  // We start by connecting to a WiFi network
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() 
{
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    //if you MQTT broker has clientID,username and password
    //please change following line to    if (client.connect(clientId,userName,passWord))
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
     //once connected to MQTT broker, subscribe command if any
      client.subscribe("OsoyooCommand");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 6 seconds before retrying
      delay(6000);
    }
  }
}


void setup() {
Serial.begin(115200);
delay(10);

setup_wifi();
client.setServer(mqtt_server, 1883);
dht22.begin();
}
 
void loop() {
 
if (!client.connected()) {
    reconnect();
    }
 
float tempValue22 = dht22.readTemperature();
float humidityValue22 = dht22.readHumidity();
 
Serial.println(" jaujau");

Serial.println("DHT22 Sensorwerte");
Serial.print("Luftfeuchtigkeit: "); //Im seriellen Monitor den Text und
Serial.print(humidityValue22); //die Dazugehörigen Werte anzeigen
Serial.println(" %");
Serial.print("Temperatur: ");
Serial.print(tempValue22);
Serial.println(" Grad Celsius");

char temp_payload[20];
char hum_payload[20];

client.publish("temp_1", dtostrf(tempValue22, 6, 2, temp_payload));
client.publish("hum_1", dtostrf(humidityValue22, 6, 2, hum_payload));
     
delay(5000);
}
