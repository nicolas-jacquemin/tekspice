/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Not component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Not : public AComponent {
            public:
                Not();
                nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
