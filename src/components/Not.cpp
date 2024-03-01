/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not component
*/

#include "components/Not.hpp"
#include "gates.hpp"

nts::Components::Not::Not() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::INPUT, 1)));
    _pins.insert(std::make_pair(2, Pin(*this, nts::Pin::Type::OUTPUT, 2)));
}

nts::Tristate nts::Components::Not::getPinState(size_t outputPinId) {
    if (getPin(outputPinId)._type != nts::Pin::Type::OUTPUT)
        throw nts::Error("\"not\" component: pin " + std::to_string(outputPinId) + " is not an output");

    return (nts::gates::notGate(getPin(1).getState()));
}
