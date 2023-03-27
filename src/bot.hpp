#pragma once
#include <iostream>

class Bot {
    private:
        std::string myToken;
        std::vector<std::string> getCelebrants(int* birthDate);
        int* getCurrDate();

    public:
        Bot();
        Bot(const std::string& token);
        std::string getToken() {return myToken;};
        void setToken(const std::string& token);
        void greetCelebrants();
};