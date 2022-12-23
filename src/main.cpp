// stl include
#include <iostream>
#include <fstream>
#include <map>

// external import
#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

// source import
#include "bot.cpp"

using json = nlohmann::json;

int main() {
    Bot botInfo; // Bot information.
    dpp::cluster bot(botInfo.getToken());



    return 0;
}