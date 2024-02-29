/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Component factory
*/

#pragma once

#include "nts.hpp"
#include "Component.hpp"

#include "components/True.hpp"
#include "components/False.hpp"
#include "components/Output.hpp"
#include "components/Input.hpp"

namespace nts {
    class ComponentFactory {
      public:
        std::unique_ptr<nts::AComponent> deliver(std::string type);

      private:
        template <typename Type>
        std::unique_ptr<nts::AComponent> createComponent() {
            return (std::make_unique<Type>());
        };

        std::map<std::string, std::unique_ptr<nts::AComponent> (nts::ComponentFactory::*)()> _components = {
            {"true", &nts::ComponentFactory::createComponent<nts::Components::True>},
            {"false", &nts::ComponentFactory::createComponent<nts::Components::False>},
            {"output", &nts::ComponentFactory::createComponent<nts::Components::Output>},
            {"input", &nts::ComponentFactory::createComponent<nts::Components::Input>}
        };
    };
}
