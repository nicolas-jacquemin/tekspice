/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Nor4001 component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Nor4001 : public AComponent {
          public:
            Nor4001();
            nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
