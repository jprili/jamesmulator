#include <iostream>
#include <fstream>
#include <dpp/dpp.h>
#include <json/json.h>
#include "bot.cpp"

int main() {
    Bot botInfo;
    dpp::cluster bot(botInfo.getToken());

    return 0;
}