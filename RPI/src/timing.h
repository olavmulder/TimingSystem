#ifndef TIMING
#define TIMING
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>



class Timing{
    private:
        double time;
        int fd;
    public:
        Timing(){};
        ~Timing(){};
        void SetupGPIO();
        void SetTime(long int t);
        void WriteTimeToFile();
};


#endif