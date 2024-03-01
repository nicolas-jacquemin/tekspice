/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Shell
*/

#include "Circuit.hpp"
#include "components/Input.hpp"
#include "components/Clock.hpp"

extern std::stringstream shellInputs;

static void display(nts::Circuit &circuit) {
    (void)circuit;
    std::cout << "tick: " << circuit.getTick() << std::endl
              << "input(s):" << std::endl;
    circuit.displayInputs();

    std::cout << "output(s):" << std::endl;
    circuit.displayOutputs();
}

static void loop(nts::Circuit &circuit) {
    while (true) {
        circuit.simulate();
        display(circuit);
    }
}

static void setValue(nts::Circuit &circuit, std::string line) {
    size_t index = line.find('=');
    if (index == std::string::npos)
        throw nts::Error("Invalid command: bad format");

    nts::AComponent &component = circuit.getComponent(line.substr(0, index));
    std::string value = line.substr(index + 1);

    if (dynamic_cast<nts::Components::Input *>(&component)) {
        dynamic_cast<nts::Components::Input &>(component).setStdin(value);
    } else if (dynamic_cast<nts::Components::Clock *>(&component)) {
        dynamic_cast<nts::Components::Clock &>(component).setStdin(value);
    } else
        throw nts::Error("Invalid command: component state cannot be set");
}

void shell(nts::Circuit circuit) {
    (void)circuit;
    std::cout << "> ";

    std::string line;
    while (std::getline(shellInputs, line)) {
        if (line == "exit")
            return;
        if (line == "display")
            display(circuit);
        else if (line == "simulate")
            circuit.simulate();
        else if (line == "loop")
            loop(circuit);
        else
            setValue(circuit, line);

        std::cout << "> ";
    }
}

// MAYBE: move this to a separate file
char displayTristate(nts::Tristate tristate) {
    switch (tristate) {
    case nts::Tristate::False:
        return '0';
    case nts::Tristate::True:
        return '1';
    default:
        return 'U';
    }
}
