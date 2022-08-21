//
// Created by jorge on 8/21/22.
//
#include "game.h"

const QString Game::values_separator = "~~vkBasalt~~";

const QString newline('\n');
const QString cr('\r');

#ifdef __linux__
const QString Game::end_line_separator = newline;
#elif _WIN32
const QString Game::end_line_separator = cr + newline;
#else
const QString Game::end_line_separator = cr;
#endif