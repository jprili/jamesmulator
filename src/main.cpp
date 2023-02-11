/*
*  A portion of the code is from 
*  https://github.com/harshfeudal/Kamisato-Ayaka-Cpp
*  and from https://dpp.dev/
*/

// stl include
#include <iostream>
#include <fstream>
#include <map>

// external import
#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

// source import
#include "bot.cpp"
#include "cmd/handle.h"
#include "cmd/slashCmds.h"

using json = nlohmann::json;

std::map<std::string, cmdDef> cmds 
{
    { 
        "ping", {"Get jamesmulator's ping (ms).", ping}
    },
    {
        "joke", {"Tells you a joke.", joke}
    }
};

int main() {
    Bot botInfo;                                                // Bot information.
    dpp::cluster bot(botInfo.getToken());

    bot.on_log(dpp::utility::cout_logger());                    // enable live logging

    // BEGIN bot logic.
    bot.on_ready([&bot](const dpp::ready_t& event) {
        bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_game, "with balls"));

        if (dpp::run_once<struct bulk_register>()) {
            std::vector<dpp::slashcommand> slashCmds;

            for (auto& definition : cmds) {
                dpp::slashcommand cmd;

                cmd.set_name(definition.first)                  // first is key, second is value
                   .set_description(definition.second.desc)
                   .set_application_id(bot.me.id);

                cmd.options = definition.second.params;         // would add options if params is
                                                                // not empty.

                slashCmds.push_back(cmd);                       // add to dpp::slashcommand vector.
            }

            bot.global_bulk_command_create(slashCmds);          // compile bulk commands.
        }
    });

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        const dpp::command_interaction cmdData = event.command.get_command_interaction();
        const auto cmdVal = cmds.find(cmdData.name);

        if (cmdVal != cmds.end()) {
            cmdVal->second.func(bot, event);
        }

    });


    bot.start(dpp::st_wait);
    return 0;
}