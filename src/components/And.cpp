/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** And component
*/

#include "components/And.hpp"
#include "gates.hpp"

nts::Components::And::And() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::INPUT, 1)));
    _pins.insert(std::make_pair(2, Pin(*this, nts::Pin::Type::INPUT, 2)));
    _pins.insert(std::make_pair(3, Pin(*this, nts::Pin::Type::OUTPUT, 3)));
}

nts::Tristate nts::Components::And::getPinState(size_t outputPinId) {
    if (getPin(outputPinId)._type != nts::Pin::Type::OUTPUT)
        throw nts::Error("\"and\" component: pin " + std::to_string(outputPinId) + " is not an output");

    return (nts::gates::andGate(getPin(1).getState(), getPin(2).getState()));
}
