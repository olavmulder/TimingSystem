#include "ethernet.h"
/*
* 
* 0: interrupt:: lazer input going low, 
     stop time
     
* while(1){
    1. wait for rpi send 1;
    1a start timer;
    if timer is stop
    send time to rpi
  }

*/
/*IR*/
/*IR input active low*/
unsigned int pinOutput = 3;
unsigned int pinInput = 2;

Timer t;
ETH eth(&t);
void setup(){
  pinMode(pinOutput, OUTPUT);
  pinMode(pinInput, INPUT);
  digitalWrite(pinOutput, 1);
  Serial.begin(9600);
  eth.SetupEth();
  Serial.print("Etst");


}

void loop(){
  
  eth.ReceiveData();
  //delay(7000);//7 sec;
  /*WAIT until cross*/
  while(digitalRead(pinInput) != 1)continue;
  unsigned long time = eth.GetTime();
  Serial.print("time: ");
  Serial.println(time);
  char buf[15];
  String strTime = String(time);
  strTime.toCharArray(buf, 15);
  eth.SendData(buf);
  
 
  
  
}