/*
server & finish module


*/
#include "ServerFinish.h"
#include "html.h"

#define PIN_FINISH 5
Users u;
unsigned int amountRecords = 0;
unsigned int prevAmountRecords;
unsigned long prevMillis = 0, curMillis, interval = 1000;
struct Node *list;
struct UserList *userList;

const char* PARAM_INPUT_1 = "name";
const char* PARAM_INPUT_2 = "selectUser";
void setup(){
  
    Serial.begin(9600);
    Serial.println();
    pinMode(PIN_FINISH, OUTPUT);
    WiFi.config(ipFinish, IPAddress(192,168,4,1), IPAddress(255,255,255,0));
    WiFi.softAP(ssid, password);
    
    /*Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());*/
    


    userList = u.MakeList(String("default"));
    
    //home page
    HtmlCombineHeader();
    server.on("/", HTTP_GET, [&htmlHeader](AsyncWebServerRequest *request){
      String a = String(htmlHeader);
      a += String("<h1>Timing System </h1><br><p>made by Olav</p>");
      a += String(htmlFooter);
      request->send_P(200, "text/html", a.c_str());
    });
    //time page
    server.on("/time", HTTP_GET, [&htmlHeader](AsyncWebServerRequest *request){
      String a = String(htmlHeader);
      String selectOptions;
      /*get all users and place in option form*/
      UserList *l = u.GetHead();

      while(l != NULL){
        selectOptions += String("<option value=\""+ String(l->id) +"\">" + l->name +"</option>" );
        l = l->next;        
      }
      a += "Selected user is: ";
      a += u.GetUserNameById(u.GetCurUserID()) + "<br>";
      a += htmlUserSelectForm;
      a += selectOptions;
      a += htmlUserSelectForm2;      
      a += ReadTime(&u);
      a += String(htmlFooter);
      /*dropdown menu with all the users*/
      request->send_P(200, "text/html", a.c_str());
    });
    //start page (only for start module)
    server.on("/start", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", Start().c_str());
    });
    //unused right now -- remove -- ??
   
    //user page to see all users
    server.on("/users", HTTP_GET, [&htmlHeader](AsyncWebServerRequest *request){
      String a = String(htmlHeader+ u.User());
      a += String(htmlFooter);
      request->send_P(200, "text/html", a.c_str());
    });
    //set curUser from input from /time page
    server.on("/selectUser", HTTP_GET, [](AsyncWebServerRequest *request){
      String inputMessage;
      String inputParam;
      // GET  value on <ESP_IP>/selectUser?selectUser=<inputMessage>
      if (request->hasParam(PARAM_INPUT_2)) {
        inputMessage = request->getParam(PARAM_INPUT_2)->value();
        int b = inputMessage.toInt();
        u.SetCurUserID(b);
      }
      request->send_P(200, "text/html", htmlGoback);           
    });
    //input users
    server.on("/ImportUsers", HTTP_GET, [&htmlHeader](AsyncWebServerRequest *request){
      String a = String(htmlHeader);
      a += String(htmlInputName);
      a += String(htmlFooter);
      request->send_P(200, "text/html", a.c_str());
    });
    //process ImportUsers
    server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request){
      String inputMessage;
      String inputParam;
      // GET input1 value on <ESP_IP>/get?name=<inputMessage>
      if (request->hasParam(PARAM_INPUT_1)) {
        inputMessage = request->getParam(PARAM_INPUT_1)->value();
        inputParam = PARAM_INPUT_1;
        userList = u.AddItem(userList, inputMessage);
      }
      request->send(200, "text/html", "User with name " + inputMessage +
                                     " is added. <br><a href=\"/\">Return to Home Page</a>");
    });
    server.begin();

  //lazer input init
  pinMode(0, OUTPUT);
  digitalWrite(0,1);
  unsigned char lazerInputPin = 4;
  pinMode(lazerInputPin, INPUT);
  InitLazerInput(0, lazerInputPin);
  attachInterrupt(digitalPinToInterrupt(lazerInputPin), ISR, RISING);

  /*make a new list for timing*/
  list = MakeList(t.TimeString().toFloat(), amountRecords);
  prevAmountRecords = amountRecords;

}

ICACHE_RAM_ATTR void ISR(){
  curMillis = millis(); 
  if(curMillis - prevMillis >= interval){
    //if not started dont finish
    if(t.GetRunning() == true){
      t.Stop();
      t.SetRunning(false);
      digitalWrite(PIN_FINISH, 1);
      Serial.println("isr: StopSignal");

      amountRecords ++;
      prevMillis = millis();
    }
  }
  
}


void loop(){
    
  if(prevAmountRecords != amountRecords){
    list = AddItem(list,t.TimeString().toFloat(),u.GetCurUserID());
    prevAmountRecords = amountRecords;
  }
  //one sec after finish go off
  if(millis() - prevMillis >= interval && /*digitalRead(PIN_FINSH) == 1*/t.GetRunning() == false){
    digitalWrite(PIN_FINISH, 0);
  }
  delay(1);
}
  //SaveTimes();
