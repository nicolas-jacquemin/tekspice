/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Circuit
*/

#pragma once

#include "Component.hpp"

namespace nts {
    class Circuit {
      public:
        void addComponent(std::string name, IComponent &component);

      private:
        std::size_t _tick = 0;
        std::map<std::string, IComponent &> _components = {};
    };
}
