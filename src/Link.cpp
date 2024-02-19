/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Link
*/

#include "Pin.hpp"

nts::Link::Link(nts::Pin &a, nts::Pin &b)
    : _source((a._type == nts::Pin::Type::OUTPUT) ? a : b), _destination((a._type == nts::Pin::Type::INPUT) ? a : b) {
    if (_source._type != nts::Pin::Type::OUTPUT || _destination._type != nts::Pin::Type::INPUT)
        exit(84); // TODO: Error handling if pins are bot INPUT/OUTPUT

    if (_source._link != nullptr || _destination._link != nullptr)
        exit(84); // TODO: Error handling if pins are already linked

    _source._link = std::make_shared<nts::Link>(*this);
    _destination._link = _source._link;
}
