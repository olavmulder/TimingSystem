//server finish module

#include "ServerFinish.h"
#include "users.h"
#include "html.h"
Users u;
unsigned int amountRecords = 0;
unsigned int prevAmountRecords;
struct Node *list;
struct UserList *userList;

const char* PARAM_INPUT_1 = "name";
void setup(){
  
    Serial.begin(9600);
    Serial.println();
    WiFi.config(ipFinish, NULL, NULL, NULL, NULL);
    WiFi.softAP(ssid, password);
    
    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());


    userList = u.MakeList(NULL);
    unsigned char pinLazerCheck = 0;
    pinMode(pinLazerCheck, OUTPUT);
    digitalWrite(pinLazerCheck,1);

    server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", ReadTime().c_str());
    });
    server.on("/start", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", Start().c_str());
    });

    server.on("/users", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", u.User().c_str());
    });
    //input users
    server.on("/ImportUsers", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", index_html);
    });
    server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request){
      String inputMessage;
      String inputParam;
      // GET input1 value on <ESP_IP>/get?name=<inputMessage>
      if (request->hasParam(PARAM_INPUT_1)) {
        inputMessage = request->getParam(PARAM_INPUT_1)->value();
        inputParam = PARAM_INPUT_1;
        userList = u.AddItem(userList, (char*)inputMessage.c_str());
      }
      request->send(200, "text/html", "HTTP GET request sent to your ESP on input field (" 
                                     + inputParam + ") with value: " + inputMessage +
                                     "<br><a href=\"/time\">Return to Home Page</a>");
    });
    server.begin();

  //lazer input init
  unsigned char lazerInputPin = 4;
  pinMode(lazerInputPin, INPUT);
  InitLazerInput(pinLazerCheck, lazerInputPin);
  attachInterrupt(digitalPinToInterrupt(lazerInputPin), ISR, RISING);

  /**/
  list = MakeList(t.TimeString().toFloat(), amountRecords);
  prevAmountRecords = amountRecords;

}

ICACHE_RAM_ATTR void ISR(){
  
  if(t.GetRunning() == true){
    t.Stop();
    t.SetRunning(false);
    Serial.println("isr: StopSignal");
    amountRecords ++;
  }
  
}


void loop(){
    while(prevAmountRecords == amountRecords)delay(1);
    list = AddItem(list,t.TimeString().toFloat(),amountRecords);
    prevAmountRecords = amountRecords;
  }
  //SaveTimes();
