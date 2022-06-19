#include "timing.h"

void Timing::StartTiming(){
    while(!s->ReadEthernet())printf(".");
    printf("\nstart timing");
    start = clock();
}

long int Timing::StopTiming(){
    diff = clock() - start;
    return(diff * 1000 / CLOCKS_PER_SEC);
}
void Timing::SetupGPIO(){
   

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/export");
        exit(1);
    }

    if (write(fd, "24", 2) != 2) {
        perror("Error writing to /sys/class/gpio/export");
        exit(1);
    }

    close(fd);


    fd = open("/sys/class/gpio/gpio24/direction", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio24/direction");
        exit(1);
    }

    if (write(fd, "in", 2) != 2) {
        perror("Error writing to /sys/class/gpio/gpio24/direction");
        exit(1);
    }

    fd = open("/sys/class/gpio/gpio24/value", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio24/value");
        exit(1);
    }
}
long int Timing::TimingMain(){
    char* buf = NULL;

    SetupGPIO();
    printf("setup gpio done");
    StartTiming();
    while(strcmp(buf,"1") != 0 ){
        read(fd, buf, 1);
    }

    return(StopTiming());
}
