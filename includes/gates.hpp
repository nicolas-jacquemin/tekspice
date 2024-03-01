/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - gates
*/

#pragma once

#include "nts.hpp"

namespace nts {
    namespace gates {
        nts::Tristate andGate(nts::Tristate a, nts::Tristate b);
        nts::Tristate orGate(nts::Tristate a, nts::Tristate b);
        nts::Tristate xorGate(nts::Tristate a, nts::Tristate b);
        nts::Tristate notGate(nts::Tristate a);
    }
}
