/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Clock component
*/

#include "components/Clock.hpp"

nts::Components::Clock::Clock() {
    _pins.insert(std::make_pair(1, Pin(*this, nts::Pin::Type::OUTPUT, 1)));
}

nts::Tristate nts::Components::Clock::getPinState(size_t outputPinId) {
    getPin(outputPinId);
    return (_state);
}

void nts::Components::Clock::simulate(size_t tick) {
    (void)tick;
    if (_setStdin) {
        _state = _stdin;
        _setStdin = false;
        return;
    }

    switch (_state) {
    case True:
        _state = False;
        break;
    case False:
        _state = True;
        break;
    default:
        break;
    }
}

void nts::Components::Clock::setStdin(std::string const &stdin) {
    if (stdin == "1")
        _stdin = True;
    else if (stdin == "0")
        _stdin = False;
    else if (stdin == "U")
        _stdin = Undefined;
    else
        throw nts::Error("Invalid input value");

    _setStdin = true;
}
