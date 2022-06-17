#ifndef DATA_PROCESSING
#define DATA_PROCESSING
using json = nlohmann::json;

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>



void GetJsonFile(char*);
void PrintJSON(json file);
#endif