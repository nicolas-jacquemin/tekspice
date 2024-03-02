/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Xor4030 component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Xor4030 : public AComponent {
          public:
            Xor4030();
            nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
