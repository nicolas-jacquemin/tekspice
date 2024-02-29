/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Component factory
*/

#include "Factory.hpp"

std::unique_ptr<nts::AComponent> nts::ComponentFactory::deliver(std::string type) {
    auto newComponent = _components.find(type);
    if (newComponent == _components.end())
        throw nts::Error("Component \"" + type + "\" does not exist");

    return ((*this).*(newComponent->second))();
}
