#include "timing.h"



void Timing::WriteTimeToFile(){
    std::ofstream file;
    file.open( "/home/timing/RPI/bin/curTime.txt", std::ios::trunc);
    char buf[6];
    sprintf(buf, "%.2f", time);
    file << buf;
    printf("writed\n");
}
void Timing::SetTime(long int t){
    time = 0;
    printf("t = %ld\n", t);
    int sec = t/1000;
    int ms = t%1000;
    time = sec+(ms*0.001);
    printf("time: %.2f", time);
    WriteTimeToFile();
}