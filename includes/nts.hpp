/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file
*/

#pragma once

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

namespace nts {
    /**
     * @brief The state of a pin: either True (`true`), False (`false`) or Undefined (`-1`)
     */
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class Error : public std::exception {
      public:
        Error(std::string const &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); } // MAYBE: move to proper file

      private:
        std::string _message;
    };
}
