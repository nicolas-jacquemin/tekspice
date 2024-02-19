/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - True component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class True : public AComponent {
          public:
            True();
            nts::Tristate getPinState(std::size_t outputPinId);
        };
    }
}
