/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** True component
*/

#include "components/True.hpp"

nts::Components::True::True() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::OUTPUT, 1)));
}

nts::Tristate nts::Components::True::getPinState(std::size_t outputPinId) {
    getPin(outputPinId);
    return (nts::Tristate::True);
}
