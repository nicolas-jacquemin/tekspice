/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"
#include "Circuit.hpp"

nts::Pin::Pin(nts::IComponent &parent, nts::Pin::Type type, size_t id)
    : _parent(parent), _type(type), _id(id) {}

nts::Tristate nts::Pin::getState() const {
    if (_type == nts::Pin::Type::OUTPUT)
        return (_parent.getPinState(_id));

    if (_link == nullptr)
        return (nts::Tristate::Undefined);

    return (_link->_source.getState());
}
