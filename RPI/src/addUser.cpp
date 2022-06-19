#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>


char fileName[] = "/home/timing/RPI/bin/users.txt";
int main(int argc, char ** argv){
    if(argc < 1){
        std::cout << "no input name" << std::endl;
        return 2;
    }
    char* name;
    name = argv[1];
    
    std::fstream file;
    std::ifstream read_file;
    read_file.open(fileName, std::ios::in);

    if(!read_file){
        return 2;
    }else{
        for(std::string line; std::getline(read_file,line);){
            if(strcmp(name, line.c_str())==0){
                return 1;
            }
        }
        read_file.close();
        
        file.open(fileName, std::ios::app);
        if(!file){
            std::cout << "error: cant open file" << std::endl;
            return 2;
        }else{
            file << argv[1] << "\n";
            file.close();
        }
        
    }
    std::cout << name << " added" << std::endl;
    return 0;
}