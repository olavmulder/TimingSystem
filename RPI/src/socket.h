#ifndef SOCKET
#define SOCKET

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <cstdlib>
#include "timing.h"
#define BUFFER_SIZE 15




class Socket{
    private:
        
        ssize_t valread;
        int server_fd, new_socket;
        char timeBuffer[BUFFER_SIZE];
        char codeBuffer[2];
        char finishCode;
       
        Timing *t;
    public:
        Socket(Timing *time){
            t = time;
            finishCode = 49;/*'1'*/
        }
        ~Socket(){
            close(new_socket);
            printf("closed socket");
            shutdown(server_fd, SHUT_RDWR);
        }
        bool CreateSocket(uint16_t port);
        void ReadEthernet();
        void SendEthernet(char* data);

        //void DummyBuffer();

};
    

    

#endif