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
int main(){
    printf("start\n");
    SetupGPIO(InputLazerGPIO);
    Timing t;
    Socket s(&t);
    s.CreateSocket(8080);

    unsigned char startCode = 1;
    while(1){
        while(GetInputStart(InputLazerGPIO)== 0)continue;
        
        //printf("GO!");
        s.SendEthernet(startCode);
        s.ReadEthernet();

        while(GetInputStart(InputLazerGPIO) == 1)continue;
        
    }
    
    
    return 0;
    
}