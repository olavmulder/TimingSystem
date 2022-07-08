#ifndef TIMING_START_H
#define TIMING_START_H
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;


const char* ssid = "ESP8266-AP";
const char* password = "123456789";
const char* serverNameStart = "http://192.168.4.1/start";
const char* serverNameTime = "http://192.168.4.1/time";
bool sendSignal;


String httpGETRequest(const char* serverName) {
  if (WiFiMulti.run() == WL_CONNECTED) {
      
    HTTPClient http;
    WiFiClient startClient;  
    // Your IP address with path or Domain name with URL path 
    http.begin(startClient, serverName);
    
    // Send HTTP POST request
    int httpResponseCode = http.GET();
    
    String payload = "--"; 
    
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      payload = http.getString();
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
    return payload;
   }else {
      Serial.println("WiFi Disconnected");
   }
   
}

void SendStartSignal(){
    String ret = httpGETRequest(serverNameStart);
    Serial.print("ret: ");
    Serial.println(ret);
}

void InitLazerInput(unsigned char ledPin, unsigned char inputPin ){
  while(digitalRead(inputPin) == 1){
    delay(1000);
    digitalWrite(ledPin, 1);
    delay(1000);
    digitalWrite(ledPin, 0);
    if(digitalRead(inputPin) == 0){
      delay(3000);
      for(unsigned char i = 0;i < 5;i++){
        digitalWrite(ledPin, 1);
        delay(100);
        digitalWrite(ledPin, 0);
        delay(100);
      }
      if(digitalRead(inputPin) == 0){
        return;
      }
    }
  }
  digitalWrite(ledPin,0);
}

#endif
