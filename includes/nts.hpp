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

namespace nts {
    /**
     * @brief The state of a pin: either True (`true`), False (`false`) or Undefined (`-1`)
     */
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };
}
