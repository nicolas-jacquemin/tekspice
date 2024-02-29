/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Component
*/

#pragma once

#include "Pin.hpp"
#include "nts.hpp"

namespace nts {
    class IComponent {
      public:
        virtual nts::Tristate getPinState(size_t outputPinId) = 0;
        virtual void simulate(size_t tick) = 0;
    };

    class AComponent : public IComponent {
      public:
        // TODO: Add destructor
        virtual void simulate(size_t tick);
        nts::Pin &getPin(size_t pinId);

      protected:
        std::map<size_t, Pin> _pins;
    };
}
