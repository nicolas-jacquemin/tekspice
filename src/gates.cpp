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

nts::Tristate nts::gates::xorGate(nts::Tristate a, nts::Tristate b) {
    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
        return (nts::Tristate::Undefined);
    else if (a == b)
        return (nts::Tristate::False);

    return (nts::Tristate::True);
}

nts::Tristate nts::gates::notGate(nts::Tristate a) {
    if (a == nts::Tristate::True)
        return (nts::Tristate::False);
    else if (a == nts::Tristate::False)
        return (nts::Tristate::True);

    return (nts::Tristate::Undefined);
}

nts::Tristate nts::gates::nandGate(nts::Tristate a, nts::Tristate b) {
    if (a == nts::Tristate::True && b == nts::Tristate::True)
        return (nts::Tristate::False);
    else if (a == nts::Tristate::False || b == nts::Tristate::False)
        return (nts::Tristate::True);

    return (nts::Tristate::Undefined);
}
