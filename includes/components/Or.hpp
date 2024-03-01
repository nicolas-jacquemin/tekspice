/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Or component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Or : public AComponent {
            public:
                Or();
                nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
