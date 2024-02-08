/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file
*/

#pragma once

#include <map>
#include <string>

namespace nts {
    /**
     * @brief The state of a pin: either True (`true`), False (`false`) or Undefined (`-1`)
     */
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    /**
     *  @brief The type of a pin: either `INPUT` or `OUTPUT`
     */
    enum PinType {
        INPUT,
        OUTPUT
    };

    class Pin {
      public:
        Pin(IComponent *parent, PinType type, size_t id);

        IComponent *_parent = nullptr;
        Link *_link = nullptr;
        PinType _type;

      protected:
        size_t _id;
    };

    class Link {
      public:
        Link(Pin *source, Pin *destination);

      private:
        Pin *_source = nullptr;
        Pin *_destination = nullptr;
    };

    class IComponent {
      public:
        virtual nts::Tristate getPinState(std::size_t outputPinId) = 0;
        virtual void simulate(std::size_t tick) = 0;

      protected:
        std::map<std::size_t, Pin> _pins = {};
    };

    class Circuit {
      public:
        void addComponent(std::string name, IComponent *component);

      private:
        std::size_t _tick = 0;
        std::map<std::string, IComponent *> _components = {};
    };
}
