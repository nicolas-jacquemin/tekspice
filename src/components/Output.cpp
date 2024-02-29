/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Output component
*/

#include "components/Output.hpp"

nts::Components::Output::Output() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::INPUT, 1)));
}

nts::Tristate nts::Components::Output::getPinState(std::size_t outputPinId) {
    return (getPin(outputPinId).getState());
}
