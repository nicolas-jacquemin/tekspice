/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Xor component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Xor : public AComponent {
            public:
                Xor();
                nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
