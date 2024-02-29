/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - And component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class And : public AComponent {
            public:
                And();
                nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
