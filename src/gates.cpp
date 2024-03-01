/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** gates
*/

#include "gates.hpp"

nts::Tristate nts::gates::andGate(nts::Tristate a, nts::Tristate b) {
    if (a == nts::Tristate::True && b == nts::Tristate::True)
        return (nts::Tristate::True);
    else if (a == nts::Tristate::False || b == nts::Tristate::False)
        return (nts::Tristate::False);

    return (nts::Tristate::Undefined);
}

nts::Tristate nts::gates::orGate(nts::Tristate a, nts::Tristate b) {
    if (a == nts::Tristate::True || b == nts::Tristate::True)
        return (nts::Tristate::True);
    else if (a == nts::Tristate::False && b == nts::Tristate::False)
        return (nts::Tristate::False);

    return (nts::Tristate::Undefined);
}
