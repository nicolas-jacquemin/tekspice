/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component
*/

#include "Component.hpp"

void nts::AComponent::simulate(std::size_t tick) {
    (void)tick;
    return;
}

nts::Pin &nts::AComponent::getPin(std::size_t pinId) {
    auto it = _pins.find(pinId);
    if (it == _pins.end())
        throw nts::Error("Pin (" + std::to_string(pinId) + ") does not exist");

    return (it->second);
}
