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
    // MAYBE: Error handling if pin does not exist
    return (_pins.find(pinId)->second);
}
