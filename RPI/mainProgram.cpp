#include "dataProcessing/dataProcessing.hpp"
#include "timing/timing.h"
#include "ethernet/socket.h"


int main(){
    CreateSocket();
    int time = Timing();
    printf("Time taken %d seconds %d milliseconds", msec/1000, msec%1000);
    
}