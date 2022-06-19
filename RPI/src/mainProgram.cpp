#include "dataProcessing.hpp"
#include "timing.h"
#include "socket.h"


int main(){
    Socket s;
    Timing t(&s);
    if(s.CreateSocket((uint16_t)8080)){
        printf("socket donen\n");
        int time = t.TimingMain();
        printf("Time taken %d seconds %d milliseconds", time/1000, time%1000);
    }else{
        return 0;
    }
    
}