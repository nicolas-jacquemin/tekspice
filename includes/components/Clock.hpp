/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Clock component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Clock : public AComponent {
            public:
                Clock();
                nts::Tristate getPinState(size_t outputPinId);
                void simulate(size_t tick);
                void setStdin(std::string const &stdin);

            private:
                nts::Tristate _state = nts::Undefined;
                nts::Tristate _stdin = nts::Undefined;
                bool _setStdin = false;
        };
    }
}
