/*
*  File responsible for defining command logic.
*/
#include <string.h>
#include <map>

#include "slashCmds.h"

using json = nlohmann::json;

std::fstream file("data/jokes.json");
json jJokes = json::parse(file);
std::vector<std::string> jokes = jJokes["jokes"].get<std::vector<std::string>>();

void ping(dpp::cluster& bot, const dpp::slashcommand_t& event) {
    // initialise values to send
    const double wsPing = bot.get_shard(0)->websocket_ping;
    const int totalPing = std::round((bot.rest_ping + wsPing) * 1000);

    const std::string msg = "It took " + std::to_string(totalPing) + " ms to respond!";

    // reply with msg
    event.reply(dpp::message().set_content(msg));
}

void joke(dpp::cluster& bot, const dpp::slashcommand_t& event) {
    // TODO: randomiser, json reader
    int randomIndex = rand() % jokes.size();
    event.reply(jokes[randomIndex]);
}