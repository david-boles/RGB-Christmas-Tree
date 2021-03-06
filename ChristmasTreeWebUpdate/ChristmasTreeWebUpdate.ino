/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

const char* host = "esp8266-webupdate";
const char* ssid = "Beausoleil";
const char* password = "74594112";

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

void setup(void){

  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
//  WiFi.mode(WIFI_AP_STA);
//  WiFi.begin(ssid, password);
//
//  while(WiFi.waitForConnectResult() != WL_CONNECTED){
//    WiFi.begin(ssid, password);
//    Serial.println("WiFi failed, retrying.");
//  }
  WiFi.mode(WIFI_AP);
  WiFi.softAP("RGB_Tree");

  //MDNS.begin(host);

  httpUpdater.setup(&httpServer);
  setupWebControl ();
  httpServer.begin();

  //MDNS.addService("http", "tcp", 80);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
  setupLights();
}

void loop(void){
  httpServer.handleClient();
  loopLights();
  //if (WiFi.status() != WL_CONNECTED) {reconnect();}
  //rainbow(20);
}

void reconnect() {
  WiFi.disconnect();
  WiFi.mode(WIFI_AP_STA); // added in V 3.1a to disable AP_SSID publication in Client mode - default was WIFI_AP_STA
  WiFi.begin(ssid, password);  // connect to local WIFI Access Point
  delay(1000);
}

