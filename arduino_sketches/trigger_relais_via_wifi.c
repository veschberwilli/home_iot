#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "xxx"
#define STAPSK  "xxx"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const int led = 13;

const String postForms = "<html>\
  <head>\
    <title>Wasserkocher</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Wasserkocher</h1><br>\
    <form method=\"post\" enctype=\"application/x-www-form-urlencoded\" action=\"/postform/\">\
      <input type=\"text\" name=\"status\" value=\"an\"><br>\
      <input type=\"submit\" value=\"senden\">\
    </form>\
  </body>\
</html>";

void handleRoot() {
  server.send(200, "text/html", postForms);
}

void handleForm() {
  if (server.method() != HTTP_POST) {
    server.send(405, "text/plain", "Method Not Allowed");
  } else {
    Serial.println(led);
    Serial.println(server.arg(1));
    Serial.println(server.argName(1));
    String message = "Wasserkocher Status:\n";
    // for (uint8_t i = 0; i < server.args(); i++) {
    //   message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    // }
    server.send(200, "text/plain", server.argName(0));
    server.send(200, "text/plain", server.arg(0));

    // Fallunterscheidung
    if (server.arg(0).indexOf("aus")>=0) {
      digitalWrite(led, 1);
    }
    if (server.arg(0).indexOf("an")>=0) {
      digitalWrite(led, 0);
    }
  }
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/postform/", handleForm);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}
