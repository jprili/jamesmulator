    /*
    *  Code inspiration from
    *  https://github.com/harshfeudal/Kamisato-Ayaka-Cpp/blob/main/commands/ping.h
    */

    #pragma once

    #include <dpp/dpp.h>

    void ping(dpp::cluster& bot, const dpp::slashcommand_t& event);

    void joke(dpp::cluster& bot, const dpp::slashcommand_t& event);