/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#include "utils.hpp"
#include "Factory.hpp"
#include "Circuit.hpp"

nts::Circuit::Circuit(std::map<std::string, std::string> components, std::vector<std::pair<std::string, std::string>> links) {
    nts::ComponentFactory factory;
    for (auto &component : components)
        _components.insert(std::make_pair(component.first, factory.deliver(component.second)));

    for (auto &link : links) {
        std::pair pairA = splitLink(link.first);
        std::pair pairB = splitLink(link.second);

        nts::Link(getComponent(pairA.first).getPin(pairA.second), getComponent(pairB.first).getPin(pairB.second));
    }
}

nts::AComponent &nts::Circuit::getComponent(std::string name) {
    auto component = _components.find(name);
    if (component == _components.end())
        throw nts::Error("Component \"" + name + "\" does not exist in the circuit");

    return (*component->second);
}

size_t nts::Circuit::getTick() const {
    return (_tick);
}


void nts::Circuit::simulate() {
    for (auto &component : _components)
        component.second->simulate(_tick);
    _tick++;
}

void nts::Circuit::displayOutputs() {
    for (auto &component : _components)
        if (dynamic_cast<nts::Components::Output *>(component.second.get()))
            std::cout << "  "
                      << component.first
                      << ": "
                      << displayTristate(component.second->getPin(1).getState())
                      << std::endl;
}

void nts::Circuit::displayInputs() {
    for (auto &component : _components)
        if (dynamic_cast<nts::Components::Input *>(component.second.get()))
            std::cout << "  "
                      << component.first
                      << ": "
                      << displayTristate(component.second->getPin(1).getState())
                      << std::endl;
}
