/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Or4071 component
*/

#pragma once

#include "Component.hpp"

namespace nts {
    namespace Components {
        class Or4071 : public AComponent {
          public:
            Or4071();
            nts::Tristate getPinState(size_t outputPinId);
        };
    }
}
