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
    printf("0");
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    printf("1");
    address.sin_family = AF_INET;
    //const char* ipAddr = "10.0.0.1";
    address.sin_addr.s_addr = INADDR_ANY; //inet_addr(ipAddr);
    address.sin_port = htons(port);
    printf("2");
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("3");
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("4");
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    printf("done socket\n");
    return true;
}
void Socket::SendEthernet(unsigned char data){
    char* buf = (char*)malloc(sizeof(int));
    sprintf(buf, "%d", data);
    printf("data to send: %s\n", buf);
    valread = write(new_socket, buf, sizeof(buf));
}
void Socket::ReadEthernet(){
    valread = 0;
    bool go;
    while(go){
        read(new_socket, buffer, BUFFER_SIZE);
        printf("buffer %s\n", buffer);
        if(strcmp(buffer, "f")==0){
            read(new_socket, buffer, BUFFER_SIZE);
            std::string str = buffer;
            long int time = atoi(str.c_str());
            printf("buffer time %ld\n", time);
            t->SetTime(time);
            go = false;
        }
    }
    
    
}

/*void Socket::DummyBuffer(){
    sprintf(buffer, "%.2f", 10.00);
}*/