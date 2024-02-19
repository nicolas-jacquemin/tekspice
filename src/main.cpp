/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Main file
*/

#include "Circuit.hpp"
#include "components/True.hpp"

#include <iostream>

int main(void) {
    nts::Circuit circuit;
    nts::Components::True trueComponent;

    circuit.addComponent("true", trueComponent);
    return (0);
}
