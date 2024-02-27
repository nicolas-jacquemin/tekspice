/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Main file
*/

#include "nts.hpp"

void openConfigFile(const std::string &path) {
    std::ifstream file(path);

    if (!file.is_open())
        throw nts::Error("Could not open file \"" + path + "\"");

    std::string line;
    std::string buffer;
    while (std::getline(file, line))
        buffer += line + '\n';

    file.close();
}

int main(int argc, char **argv) {
    try {
        if (argc < 2)
            throw nts::Error("No configuration file provided as argument");

        openConfigFile(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << "\e[0;31m" << e.what() << '\n';
    }
}
