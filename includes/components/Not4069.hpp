/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Not4069 component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Not4069 : public AComponent {
          public:
            Not4069();
            nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
