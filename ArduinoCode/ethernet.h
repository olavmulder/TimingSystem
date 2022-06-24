
#ifndef ETHERNET
#define ETHERNET
#include <SPI.h>
#include <Ethernet.h>
#include "timer_clock.h"

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 0, 0, 2 };
byte server[] = { 10, 0, 0, 1 }; // RPI
class ETH{
  
  private:
    EthernetClient client;
    Timer *t;
    int port = 8080;
    
  public:
    ETH(Timer *tim){
      t = tim;
    }
    void SetupEth(){
      Ethernet.begin(mac, ip);
      delay(1000);
      bool connected = false;
      Serial.println("connecting...");
      while(!connected){
        if (client.connect(server, port)) {
          Serial.println("connected");
          connected = true;
        } else {
          Serial.println("connection failed");
        }
      }

    }
    void ReceiveData(){
      char c = '0';
      while(c != '1'){ 
        c = client.read();      
      }
      Serial.println("received!");
      t->StartTime();
    }
    void SendData(char *buf){
      client.write(buf);
    }
    inline unsigned long GetTime(){
      return t->GetTime();
    }


};

#endif