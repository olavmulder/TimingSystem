#ifndef SERVER_FINISH_H
#define SERVER_FINISH_H

#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#include "Timing.h"
#define SERVER_PORT 80


class ServerFinish{
  private:


    bool finishSignal;
    const char* ssid = "ESP8266-AP";
    const char* password = "123456789";
        
    IPAddress ipFinish = {192,168,4,1};
    TIMING *t;
    

  public:

    ServerFinish(TIMING *ti);
    String Start();
    String ReadTime(USERS *u);
};







#endif
