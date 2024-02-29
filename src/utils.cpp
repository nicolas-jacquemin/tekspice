/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Utils
*/

#include "utils.hpp"

std::string uncommentString(const std::string &string) {
    size_t index = string.find('#');

    if (index != std::string::npos)
        return (string.substr(0, index));

    return (string);
};

std::vector<std::string> splitTrimString(const std::string &string) {
    std::stringstream stream(string);
    std::vector<std::string> tokens;

    std::string token;
    while (std::getline(stream, token, ' ')) {
        if (token == "")
            continue;
        tokens.push_back(token);
    }

    return (tokens);
}

std::pair<std::string, size_t> splitLink(const std::string &link) {
    std::stringstream stream(link);
    std::string component = "";
    size_t pin = 0;

    std::string token;
    for (int index = 0; std::getline(stream, token, ':'); index++) {
        switch (index) {
        case 0:
            component = token;
            break;
        case 1:
            pin = std::stoi(token);
            break;
        default:
            throw nts::Error("Invalid file format: bad link format");
        }
    }

    if (component == "" || pin == 0)
        throw nts::Error("Invalid file format: bad link format");

    return (std::make_pair(component, pin));
}
