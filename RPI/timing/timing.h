#ifndef TIMING

#include "../ethernet/socket.h"
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

clock_t start,diff;
int fd;
void StartTiming();
int StopTiming();
void SetupGPIO();
int Timing();
#endif