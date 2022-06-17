#ifndef SOCKET
#define SOCKET
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>
#define BUFFER_SIZE 1

#define START_CODE 1

uint16_t port;
int server_fd, new_socket;
ssize_t valread;
char buffer[BUFFER_SIZE];
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);

void CreateSocket(uint16_t port);
bool ReadEthernet();
#endif