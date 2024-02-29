/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Main file
*/

#include "utils.hpp"

int main(int argc, char **argv) {
    try {
        if (argc < 2)
            throw nts::Error("No configuration file provided as argument");

        parser(argv[1]);
        return (0);
    } catch (const std::exception &e) {
        std::cerr << "\e[0;31m" << e.what() << '\n';
        return (84);
    }
}
