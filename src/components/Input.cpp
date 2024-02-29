/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Input component
*/

#include "components/Input.hpp"

nts::Components::Input::Input() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::OUTPUT, 1)));
}

nts::Tristate nts::Components::Input::getPinState(std::size_t outputPinId) {
    getPin(outputPinId);
    return (_state);
}

void nts::Components::Input::simulate(std::size_t tick) {
    (void)tick;
    _state = _stdin;
    return;
}

void nts::Components::Input::setStdin(std::string const &stdin) {
    if (stdin == "0")
        _stdin = nts::Tristate::False;
    else if (stdin == "1")
        _stdin = nts::Tristate::True;
    else if (stdin == "U")
        _stdin = nts::Tristate::Undefined;
    else
        throw nts::Error("Invalid input value");

    return;
}
