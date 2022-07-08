/*#ifndef WEBSERVER
#define WEBSERVER

#include <ESP8266WiFi.h>
#include "eth_spi.h"


WiFiServer server(80);
WiFiClient clientWIFI;

class Webserver {

  private:
    double lastTime;
    double bestTime;

    const char* ssid = "TimingSystem";
    const char* password = "timing072";
    String header;
    StartClient *ethHost;
    bool *startSig;

  public:

    Webserver(StartClient *e, bool *s) {
      ethHost = e;
      startSig = s;
    }
    void ConnectWifi(unsigned char pin) {
      //ethHost->StartEthernet();
      Serial.println("done!");

      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        digitalWrite(pin, 1);
        delay(500);
        digitalWrite(pin, 0);
      }
      Serial.println("a");
      server.begin();
      Serial.println("b");
    }
    void SetValue(double time) {
      lastTime = time;
      if(value.lastTime < values.bestTime || values.lastTime == 0.0){
        value.bestTime = values.lastTime;
        }
    }
    double GetValue() {
      return lastTime;
    }
    void ShowWebsite() {
      clientWIFI.println("<!DOCTYPE html><html>");
      clientWIFI.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
      clientWIFI.println("<link rel=\"icon\" href=\"data:,\">");
      clientWIFI.println("<meta charset='utf-8'><meta http-equiv='refresh' content='1'>");

      // CSS to style the on/off buttons
      // Feel free to change the background-color and font-size attributes to fit your preferences
      clientWIFI.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
      clientWIFI.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
      clientWIFI.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
      clientWIFI.println(".button2 {background-color: #77878A;}</style></head>");

      // Web Page data show
      clientWIFI.println("<body><h1>TimingSystem</h1>");
      clientWIFI.print("<p>Best time: ");
      clientWIFI.print(bestTime);
      clientWIFI.print("<br>last time: ");
      clientWIFI.print(lastTime);
      clientWIFI.print("</p>");
      clientWIFI.println("</body></html>");
      clientWIFI.println();
    }
    void Server() {
      clientWIFI = server.available();
      if (clientWIFI) {
        Serial.println("New Client.");                          // If a new client connects,
        String currentLine = "";                // make a String to hold incoming data from the client
        while (clientWIFI.connected()) { // loop while the client's connected
          if (clientWIFI.available()) {             // if there's bytes to read from the client,
            char c = clientWIFI.read();             // read a byte, then
            //Serial.write(c);                    // print it out the serial monitor
            header += c;
            if (c == '\n') {                    // if the byte is a newline character
              // if the current line is blank, you got two newline characters in a row.
              // that's the end of the client HTTP request, so send a response:
              if (currentLine.length() == 0) {
                // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                // and a content-type so the client knows what's coming, then a blank line:
                clientWIFI.println("HTTP/1.1 200 OK");
                clientWIFI.println("Content-type:text/html");
                clientWIFI.println("Connection: close");
                clientWIFI.println();

                ShowWebsite();

                break;
              } else {
                currentLine = "";
              }
            } else if (c != '\r') {
              currentLine += c;
            }
          }
          
          }
        }
        header = "";
        clientWIFI.stop();
        Serial.println("Client disconnected.");
        Serial.println("");
      
    }
};

#endif*/
