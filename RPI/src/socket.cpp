#include "socket.h"

bool Socket::CreateSocket(uint16_t port){
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int  opt = 1;
    server_fd = socket(AF_INET, SOCK_STREAM,0);
   
    if(server_fd  == 0){
        perror("socket faild");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    //const char* ipAddr = "10.0.0.1";
    address.sin_addr.s_addr = INADDR_ANY; //inet_addr(ipAddr);
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    return true;
}
void Socket::SendEthernet(char* data){
    valread = send(new_socket, data, sizeof(char), 0);
    printf("data send: %c, amount chars:%d\n", *data, valread);
}

void Socket::ReadEthernet(){
    /*wait till data f(finish)*/
    
    while(recv(new_socket, codeBuffer, sizeof(codeBuffer), 0) < 0)continue;
    std::string str = codeBuffer;
    int time = atoi(str.c_str());
    printf("incomming data %d\n",time);
    if(time == 1){/*finish code in int time*/
        while(recv(new_socket, timeBuffer, sizeof(timeBuffer), 0) <0)continue;
        std::string str = timeBuffer;
        printf("%s\n", str.c_str());
        long int time = atoi(str.c_str());
        t->SetTime(time);
        for(unsigned char i=0;i< sizeof(timeBuffer);i++){
            timeBuffer[i] = '\0';
        }
    }
    //std::string str = buffer;
    //long int time = atoi(str.c_str());
    //if((char)time == finishCode)
    /*if(strcmp(buffer, "f")==0){
        printf("received f");
        //wait till data f(finish)
        while(recv(new_socket, buffer, BUFFER_SIZE, 0) < 0)continue;
        
        t->SetTime(time);

    }*/
}
    

/*void Socket::DummyBuffer(){
    sprintf(buffer, "%.2f", 10.00);
}*/