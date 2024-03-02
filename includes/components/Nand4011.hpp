/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Nand4011 component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Nand4011 : public AComponent {
          public:
            Nand4011();
            nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
