#ifndef SERVER_FINISH_H
#define SERVER_FINISH_H

#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#include "Timing.h"
#include "LinkedList.h"
#define SERVER_PORT 80

Timing t;
AsyncWebServer server(SERVER_PORT);

bool finishSignal;
const char* ssid = "ESP8266-AP";
const char* password = "123456789";
    
IPAddress ipFinish = {192,168,4,1};
 

String Start(){
  t.Start();
  t.SetRunning(true);
  return String("started!!");
}
String ReadTime(Users* userClass){
  while(t.GetRunning() )continue;
  t.GetTime();
  String ret = "<u><b>previous times:</b></u> <br>";
  ret = PrintList(userClass, ret);
  ret = String(userClass->GetUserNameById(userClass->GetCurUserID()) + ": " + \
                t.TimeString() + "<br>" + ret);
  return ret;
}


void InitLazerInput(unsigned char ledPin, unsigned char inputPin ){
  while(digitalRead(inputPin) == 1){
    delay(500);
    digitalWrite(ledPin, 1);
    delay(500);
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
