#include "dataProcessing.hpp"
#include "timing.h"
#include "socket.h"
/*
*ALGORITMH:
* 1. Make socket, connect with arduino
* 2. Wait for lazer input
* 2a. Send signal to Arduino
* 3. Wait for time data is back
* 4. Place time data in currentTime file in /bin folder
*/

int main(){
    printf("start\n");
    Timing t;
    Socket s(&t);
    s.CreateSocket(8080);

    unsigned char startCode = 1;
    char input;
    std::cin >> input;
    while(input != 'q'){
        s.SendEthernet(startCode);
        s.ReadEthernet();
        std::cout <<"input any to go, q to exit"<<std::endl;
        std::cin >>input;
    }
    
    return 0;
    
}