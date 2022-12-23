/*
*  Code inspiration from
*  https://github.com/harshfeudal/Kamisato-Ayaka-Cpp/blob/main/commands/handler.h
*/

#pragma once

#include <functional>
#include <dpp/dpp.h>

using cmd_func = std::function<void (dpp::cluster&, dpp::slashcommand_t&)>;

// command info structure for definition

struct cmd_def {

std::string desc; // command description

cmd_func func; // slash command

std::vector<dpp::command_option> params = {}; // extra params for extensibility

};