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
        virtual nts::Tristate getPinState(std::size_t outputPinId) = 0;
        virtual void simulate(std::size_t tick) = 0;
    };

    class AComponent : public IComponent {
      public:
        // TODO: Add destructor
        virtual void simulate(std::size_t tick);
        nts::Pin &getPin(std::size_t pinId);

      protected:
        std::map<std::size_t, Pin> _pins;
    };
}
