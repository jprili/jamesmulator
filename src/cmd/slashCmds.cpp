/*
*  File responsible for defining command logic.
*/
#include <string.h>
#include <map>

#include "slashCmds.h"

void ping(dpp::cluster& bot, const dpp::slashcommand_t& event) {
    // initialise values to send
    const double wsPing = bot.get_shard(0)->websocket_ping;
    const double totalPing = (bot.rest_ping + wsPing) * 1000;

    const std::string msg = "It took " + std::to_string(totalPing) + "to respond!";

    // reply with msg
    event.reply(dpp::message().set_flags(dpp::m_ephemeral).set_content(msg));
}

void joke(dpp::cluster& bot, const dpp::slashcommand_t& event) {
    event.reply("joke called!");
}