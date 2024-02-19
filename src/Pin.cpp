/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#include "Circuit.hpp"

nts::Pin::Pin(nts::IComponent &parent, nts::Pin::Type type, size_t id)
    : _parent(parent), _type(type), _id(id) {}
