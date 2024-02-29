/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Factory.hpp"

static std::pair<std::string, size_t> splitLink(std::string str) {
    std::stringstream stream(str);
    std::string component = "";
    size_t pin = 0;

    std::string token;
    for (int index = 0; std::getline(stream, token, ':'); index++) {
        switch (index) {
        case 0:
            component = token;
            break;
        case 1:
            pin = std::stoi(token);
            break;
        default:
            throw nts::Error("Invalid file format: bad link format");
        }
    }

    if (component == "" || pin == 0)
        throw nts::Error("Invalid file format: bad link format");

    return (std::make_pair(component, pin));
}

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
