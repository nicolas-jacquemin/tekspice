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
        // TODO: Add destructor
        Circuit(std::map<std::string, std::string> components, std::vector<std::pair<std::string, std::string>> links);
        nts::AComponent &getComponent(std::string name);
        size_t getTick() const;
        void simulate();

        void displayOutputs();
        void displayInputs();

      private:
        std::size_t _tick = 0;
        std::map<std::string, std::unique_ptr<nts::AComponent>> _components = {};
    };
}
