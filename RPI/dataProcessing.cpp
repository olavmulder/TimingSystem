#include "dataProcessing.hpp"
using json = nlohmann::json;
void GetJsonFile(char* file){
    json currJSON;

    std::ifstream in(file);
    std::string contents((std::istreambuf_iterator<char>(in))),\
        std::istreambuf_iterator<char>());
    currJSON = *(contents.c_str());
    PrintJSON(currJSON);
}
void PrintJSON(json file){
    std::cout << std::setw(4) << file << '\n';
}   