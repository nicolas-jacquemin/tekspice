/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Pin
*/

#pragma once

#include "Link.hpp"
#include "nts.hpp"

namespace nts {
    class IComponent;

    class Pin {
      public:
        enum Type {
            INPUT,
            OUTPUT
        };

        // TODO: Add destructor
        Pin(nts::IComponent &parent, nts::Pin::Type type, size_t id);
        nts::Tristate getState() const;

        // MAYBE: Add getters
        IComponent &_parent;
        // TODO: Output pins can have multiples links
        std::shared_ptr<nts::Link> _link;
        nts::Pin::Type _type;

      protected:
        size_t _id;
    };
}
