/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Output component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Output : public AComponent {
          public:
            Output();
            nts::Tristate getPinState(std::size_t outputPinId);
        };
    }
}
