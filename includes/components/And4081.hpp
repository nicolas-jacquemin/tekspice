/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - AND4081 component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class And4081 : public AComponent {
          public:
            And4081();
            nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
