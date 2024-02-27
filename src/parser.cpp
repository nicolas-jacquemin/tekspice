/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#include "nts.hpp"

static std::string unComment(const std::string line) {
    std::size_t index = line.find('#');

    if (index != std::string::npos)
        return (line.substr(0, index));

    return (line);
};

static std::vector<std::string> splitTrim(const std::string line) {
    std::stringstream stream(line);
    std::vector<std::string> tokens;

    std::string token;
    while (std::getline(stream, token, ' ')) {
        if (token == "")
            continue;
        tokens.push_back(token);
    }

    return (tokens);
}

void parser(const std::string &configPath) {
    std::ifstream file(configPath);

    if (!file.is_open())
        throw nts::Error("Could not open file \"" + configPath + "\"");

    std::string type = "";
    std::vector<std::pair<std::string, std::string>> chipsets;
    std::vector<std::pair<std::string, std::string>> links;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens = splitTrim(unComment(line));

        switch (tokens.size()) {
        case 0:
            continue;

        case 1:
            if (tokens[0] != ".chipsets:" && tokens[0] != ".links:")
                throw nts::Error("Invalid file format");
            type = tokens[0];
            // std::cout << type << std::endl;
            continue;

        case 2:
            if (type == "")
                throw nts::Error("Invalid file format: declaration misplaced");
            // std::cout << tokens[0] << " " << tokens[1] << std::endl;
            continue;

        default:
            throw nts::Error("Invalid file format: too many arguments in declaration");
        }
    }

    file.close();
}
