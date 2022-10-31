/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Script.cpp
*/

#include "Script.hpp"

rtype::Script::Script()
{
    parseScript();
}

sf::Clock rtype::Script::getClock() const
{
    return (this->_clock);
}

void rtype::Script::restartClock()
{
    _clock.restart();
}

std::vector<std::vector<int>> rtype::Script::getLines() const
{
    return (this->_lines);
}

void rtype::Script::spriteIsPrinted(size_t i)
{
    _lines[i][7] = 0;
}

void rtype::Script::parseScript()
{
    std::ifstream file;
    file.open("src/client/script/script.txt");
    std::string line;
    std::string value;
    
    while (std::getline(file, line)) {
        std::stringstream buffer(line);
        std::vector<int> tmp;
        while (std::getline(buffer, value, ' ')) {
            tmp.push_back(std::stoi(value));
        }
        _lines.push_back(tmp);
    }
}
