/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False component
*/

#include "components/False.hpp"

nts::Components::False::False() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::OUTPUT, 1)));
}

nts::Tristate nts::Components::False::getPinState(size_t outputPinId) {
    getPin(outputPinId);
    return (nts::Tristate::False);
}
