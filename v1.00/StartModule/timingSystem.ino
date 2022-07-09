#include "timingSystemStart.h"
/*start modules
send signal to finish modules
finish module caluclates time and published
on webserver

TODO:
  Add indicator leds to visualize status
  Add Function to start from signal(sound etc.) instead of led indicator

*/


const byte startSignalData = 49; // == "1"
IPAddress ipFinish = {192,168,4,1};
const unsigned char port = 80;
   
ICACHE_RAM_ATTR void ISR();


void setup() {
  Serial.begin(9600);
  //init digital outputs for leds
  unsigned char pinWebserver = 2;
  pinMode(pinWebserver, OUTPUT);
  digitalWrite(pinWebserver, 0);

  unsigned char pinLazerCheck = 0;
  pinMode(pinLazerCheck, OUTPUT);
  digitalWrite(pinLazerCheck,1);
  
  
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  /*someting with leds...*/
  //Serial.println("");
  //Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
  

  //lazer input init
  unsigned char lazerInputPin = 4;
  pinMode(lazerInputPin, INPUT);
  InitLazerInput(pinLazerCheck, lazerInputPin);
  attachInterrupt(digitalPinToInterrupt(lazerInputPin), ISR, RISING);
}
void loop() {
  //while(!GetStartStatus())continue;//wait till finished;
  if(sendSignal){//finished wait till started
    SendStartSignal();
    //Serial.println("isr: SendStartSignal");
    sendSignal = false;
  }

}


ICACHE_RAM_ATTR void ISR(){
    sendSignal = true;
}
