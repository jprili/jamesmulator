#pragma once
#include <iostream>

class Bot {
    private:
        std::string token;
        std::vector<std::string> getCelebrants(int* birthDate);

    public:
        std::string getToken() {return token;};
        void setToken(const std::string& token);
        void greetCelebrants();
};