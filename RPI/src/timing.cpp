#include "timing.h"


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
    double seconds = t/1000;
    double mil = t%1000;
    time = seconds+(mil/1000);
    printf("time: %.2f", time);
    WriteTimeToFile();
}