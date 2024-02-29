/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Shell
*/

#include "Circuit.hpp"

void shell(nts::Circuit circuit) {
    (void)circuit;
    std::cout << "> ";

    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << "> ";
    }
}
