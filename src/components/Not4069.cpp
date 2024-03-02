/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not4069 component
*/

#include "components/Not4069.hpp"
#include "gates.hpp"

nts::Components::Not4069::Not4069() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::INPUT, 1)));
    _pins.insert(std::make_pair(2, Pin(*this, nts::Pin::Type::OUTPUT, 2)));

    _pins.insert(std::make_pair(3, Pin(*this, nts::Pin::Type::INPUT, 3)));
    _pins.insert(std::make_pair(4, Pin(*this, nts::Pin::Type::OUTPUT, 4)));

    _pins.insert(std::make_pair(5, Pin(*this, nts::Pin::Type::INPUT, 5)));
    _pins.insert(std::make_pair(6, Pin(*this, nts::Pin::Type::OUTPUT, 6)));

    _pins.insert(std::make_pair(8, Pin(*this, nts::Pin::Type::OUTPUT, 8)));
    _pins.insert(std::make_pair(9, Pin(*this, nts::Pin::Type::INPUT, 9)));

    _pins.insert(std::make_pair(10, Pin(*this, nts::Pin::Type::OUTPUT, 10)));
    _pins.insert(std::make_pair(11, Pin(*this, nts::Pin::Type::INPUT, 11)));

    _pins.insert(std::make_pair(12, Pin(*this, nts::Pin::Type::OUTPUT, 12)));
    _pins.insert(std::make_pair(13, Pin(*this, nts::Pin::Type::INPUT, 13)));
}

nts::Tristate nts::Components::Not4069::getPinState(size_t outputPinId) {
    switch (outputPinId) {
        case 2:
        case 4:
        case 6:
            return (nts::gates::notGate(getPin(outputPinId - 1).getState()));

        case 8:
        case 10:
        case 12:
            return (nts::gates::notGate(getPin(outputPinId + 1).getState()));

    default:
        getPin(outputPinId);
        throw nts::Error("\"4069\" component: pin " + std::to_string(outputPinId) + " is not an output");
    }
}
