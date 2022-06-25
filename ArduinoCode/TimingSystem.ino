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
char *finishCode;
char fc = 49;
bool status = 1;
char buf[15];

Timer t;
ETH eth(&t);
void setup(){
  finishCode = &fc;
  pinMode(pinOutput, OUTPUT);
  pinMode(pinInput, INPUT);
  digitalWrite(pinOutput, 1);
  Serial.begin(9600);
  eth.SetupEth();
}

void loop(){

    eth.ReceiveData();
    while(digitalRead(pinInput) == 0);
    eth.StopTime();
    eth.SendData("1");
    for(int i=0;i< sizeof(buf);i++){
      buf[i] = '\0';
    }
    unsigned long time = eth.GetTime();
    Serial.print("time: ");
    Serial.println(time);

    unsigned long timeDum = time;
    unsigned char iterations = 1;
    while(timeDum != 0){
      timeDum /= 10;
      iterations++;
    }
    String strTime = String(time);
    Serial.println(iterations);
    
    strTime.toCharArray(buf, iterations+1);
    eth.SendData(buf);
  }
    
    
 /* while(1);
  //delay(7000);//7 sec;
  /*WAIT until cross*/
  //while(digitalRead(pinInput) == 0)continue;
  
  /*unsigned long time = eth.GetTime();
  Serial.print("time: ");
  Serial.println(time);
  
  eth.SendData("f");
  eth.SendData(buf);
}*/

/*
  if(status != digitalRead(pinInput)){
    status = (bool)digitalRead(pinInput);
    Serial.println(digitalRead(pinInput));
  }
*/