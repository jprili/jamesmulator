// external import
#include <dpp/nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

/**
 * Gets the current date
 * 
 * @return a pointer to an int[2] array
 *         containing [day, month]
 */
int* getCurrDate() {
    static int dateNow[2];

    std::time_t currTime  = std::time(0);
    std::tm*    localTime = localtime(&currTime);

    dateNow[0] = localTime->tm_mon;
    dateNow[1] = localTime->tm_mday;

    return dateNow;
};

/**
 * Gets the celebrants from the json file
 * 
 * @param  birthDate the birth date of the celebrants
 * @return a vector of celebrants
*/
std::vector<std::string> getCelebrants(int* birthDate) {
    std::vector<std::string> celebrants;
    int mon = birthDate[0];
    int day = birthDate[1];

    std::fstream bdays("../data/bdays.json");
    json jBirths = json::parse(bdays);

    // iterate through json object
    for (auto& e : jBirths.items()) {
        if (e.value()["mon"] == mon && e.value()["day"] == day) {
            celebrants.push_back(e.key());
        };
    }

    return celebrants;
}