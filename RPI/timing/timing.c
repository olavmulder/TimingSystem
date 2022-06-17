#include "timing.h"

void StartTiming(){
    CreateSocket(8080);
    while(!ReadEthernet)continue;
    printf("start timing");
    start = clock();
}

int StopTiming(){
    diff = clock() - start;
    return(diff * 1000 / CLOCKS_PER_SEC);
}
void SetupGPIO(){
    fd = open("/sys/class/gpio/gpio24/value", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio24/value");
        exit(1);
    }
}
int Timing(){
    char buf;
    bool stop = false;
    SetupGPIO();

    StartTiming();
    while(buf != "1"){
        read(fd, buf, 1);
    }

    return(StopTiming());
}
