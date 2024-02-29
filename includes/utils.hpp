/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Header file - Utils
*/

#pragma once

#include "Circuit.hpp"

void parser(const std::string &configPath);

void shell(nts::Circuit circuit);

char displayTristate(nts::Tristate tristate);

std::vector<std::string> splitTrimString(const std::string &string);

std::string uncommentString(const std::string &string);

std::pair<std::string, size_t> splitLink(const std::string &link);
