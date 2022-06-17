#ifndef TIMING
#define TIMING
#include "socket.h"
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

clock_t start,diff;
int fd;
void StartTiming();
long int StopTiming();
void SetupGPIO();
long int Timing();
#endif