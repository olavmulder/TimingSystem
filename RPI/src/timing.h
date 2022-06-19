#ifndef TIMING
#define TIMING
#include "socket.h"
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

class Timing{
    private:
        clock_t start,diff;
        int fd;
        Socket *s;

    public:
        Timing(Socket *socket){
            s = socket;
        }
        void StartTiming();
        long int StopTiming();
        void SetupGPIO();
        long int TimingMain();

};


#endif