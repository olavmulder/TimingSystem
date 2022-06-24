#include "timing.h"



void Timing::WriteTimeToFile(){
    std::ofstream file;
    file.open( "/home/timing/RPI/bin/curTime.txt", std::ios::trunc);
    char buf[6];
    sprintf(buf, "%.2f", time);
    file << buf;
    //printf("writed\n");
}
void Timing::SetTime(long int t){
    time = 0;
    double seconds = t/1000;
    double mil = t%1000;
    time = seconds+(mil/1000);
    //printf("time: %.2f", time);
    WriteTimeToFile();
}