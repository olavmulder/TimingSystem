#include "dataProcessing.hpp"
#include "timing.h"
#include "socket.h"
#include "gpio.h"
/*
*ALGORITMH:
* 1. Make socket, connect with arduino
* 2. Wait for lazer input
* 2a. Send signal to Arduino
* 3. Wait for time data is back
* 4. Place time data in currentTime file in /bin folder
*/
unsigned char InputLazerGPIO = 12;
unsigned char OutputLed = 16;
char* startCode;
char str = 48;/*0*/


int main(){
    Timing t;
    Socket s(&t);
    SetupGPIO(InputLazerGPIO, OutputLed);
    s.CreateSocket(8080);
    
    SetGPIO(OutputLed);
    while(GetInputStart(InputLazerGPIO)== 1);//lazer is not sending beam in input
    while(GetInputStart(InputLazerGPIO) == 0){
        SetGPIO(OutputLed);
        sleep(1);
        ClearGPIO(OutputLed);
        sleep(1);
        SetGPIO(OutputLed);
        sleep(1);
        if(GetInputStart(InputLazerGPIO) == 0){
            break;
        }

    }
    
    
    
    startCode = &str;

    while(1){
        while(!GetInputStart(InputLazerGPIO))continue;
        s.SendEthernet(startCode);
        s.ReadEthernet();
    }
    return 0;
    
}

