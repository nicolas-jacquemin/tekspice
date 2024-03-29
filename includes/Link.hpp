/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Link
*/

#pragma once

#include "nts.hpp"

namespace nts {
    class Pin;

    class Link {
      public:
        Link(Pin &a, Pin &b);

      // private:
        Pin &_source;
        // MAYBE: _destination should be a list of pins
        Pin &_destination;
    };
}
