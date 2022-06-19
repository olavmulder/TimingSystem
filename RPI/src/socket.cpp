#include "socket.h"

bool Socket::CreateSocket(uint16_t port){
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
    address.sin_addr.s_addr = INADDR_ANY;
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
    return true;
}
bool Socket::ReadEthernet(){

    valread = read(new_socket, buffer, BUFFER_SIZE);
    if(buffer[0] != START_CODE){
        return false;
    }else{
        return true;
    }
}
