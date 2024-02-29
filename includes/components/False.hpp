/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - False component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class False : public AComponent {
          public:
            False();
            nts::Tristate getPinState(std::size_t outputPinId);
        };
    }
}
