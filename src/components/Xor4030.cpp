/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor4030 component
*/

#include "components/Xor4030.hpp"
#include "gates.hpp"

nts::Components::Xor4030::Xor4030() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::INPUT, 1)));
    _pins.insert(std::make_pair(2, Pin(*this, nts::Pin::Type::INPUT, 2)));
    _pins.insert(std::make_pair(3, Pin(*this, nts::Pin::Type::OUTPUT, 3)));

    _pins.insert(std::make_pair(4, Pin(*this, nts::Pin::Type::OUTPUT, 4)));
    _pins.insert(std::make_pair(5, Pin(*this, nts::Pin::Type::INPUT, 5)));
    _pins.insert(std::make_pair(6, Pin(*this, nts::Pin::Type::INPUT, 6)));

    _pins.insert(std::make_pair(8, Pin(*this, nts::Pin::Type::INPUT, 8)));
    _pins.insert(std::make_pair(9, Pin(*this, nts::Pin::Type::INPUT, 9)));
    _pins.insert(std::make_pair(10, Pin(*this, nts::Pin::Type::OUTPUT, 10)));

    _pins.insert(std::make_pair(11, Pin(*this, nts::Pin::Type::OUTPUT, 11)));
    _pins.insert(std::make_pair(12, Pin(*this, nts::Pin::Type::INPUT, 12)));
    _pins.insert(std::make_pair(13, Pin(*this, nts::Pin::Type::INPUT, 13)));
}

nts::Tristate nts::Components::Xor4030::getPinState(size_t outputPinId) {
    switch (outputPinId) {
    case 3:
    case 10:
        return (nts::gates::xorGate(getPin(outputPinId - 2).getState(), getPin(outputPinId - 1).getState()));

    case 4:
    case 11:
        return (nts::gates::xorGate(getPin(outputPinId + 2).getState(), getPin(outputPinId + 1).getState()));

    default:
        getPin(outputPinId);
        throw nts::Error("\"4030\" component: pin " + std::to_string(outputPinId) + " is not an output");
    }
}
