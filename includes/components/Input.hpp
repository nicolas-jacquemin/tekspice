/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Input component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Input : public AComponent {
          public:
            Input();
            nts::Tristate getPinState(size_t outputPinId);
            void simulate(size_t tick);
            void setStdin(std::string const &stdin);

          private:
            nts::Tristate _state = nts::Undefined;
            nts::Tristate _stdin = nts::Undefined;
        };
    }
}
