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
#include "components/Clock.hpp"
#include "components/And.hpp"
#include "components/Or.hpp"
#include "components/Xor.hpp"
#include "components/Not.hpp"
#include "components/And4081.hpp"
#include "components/Or4071.hpp"
#include "components/Nand4011.hpp"
#include "components/Nor4001.hpp"
#include "components/Xor4030.hpp"

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
            {"input", &nts::ComponentFactory::createComponent<nts::Components::Input>},
            {"clock", &nts::ComponentFactory::createComponent<nts::Components::Clock>},
            {"and", &nts::ComponentFactory::createComponent<nts::Components::And>},
            {"or", &nts::ComponentFactory::createComponent<nts::Components::Or>},
            {"xor", &nts::ComponentFactory::createComponent<nts::Components::Xor>},
            {"not", &nts::ComponentFactory::createComponent<nts::Components::Not>},
            {"4081", &nts::ComponentFactory::createComponent<nts::Components::And4081>},
            {"4071", &nts::ComponentFactory::createComponent<nts::Components::Or4071>},
            {"4011", &nts::ComponentFactory::createComponent<nts::Components::Nand4011>},
            {"4001", &nts::ComponentFactory::createComponent<nts::Components::Nor4001>},
            {"4030", &nts::ComponentFactory::createComponent<nts::Components::Xor4030>},
        };
    };
}
