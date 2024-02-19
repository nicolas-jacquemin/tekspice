/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"

void nts::Circuit::addComponent(std::string name, IComponent &component) {
    // MAYBE: Error handling if component already exists
    _components.insert(std::pair<std::string, IComponent &>(name, component));
}
