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

std::vector<std::vector<int>> rtype::Script::getWave(int wave) const
{
    switch (wave) {
        case 1:
            return this->_waveOne;
        case 2:
            return this->_waveTwo;
        case 3:
            return this->_waveThree;
        case 4:
            return this->_waveFour;
        case 5:
            return this->_waveFive;
        case 6:
            return this->_waveSix;
        case 7:
            return this->_waveSeven;
        case 8:
            return this->_waveEight;
        case 9:
            return this->_waveNine;
        case 10:
            return this->_waveTen;
        default:
            break;
    }
    return this->_waveOne;
}

void rtype::Script::spriteIsPrinted(int wave, size_t i)
{
    switch (wave) {
        case 1:
            _waveOne[i][5] = 0;
            break;
        case 2:
            _waveTwo[i][5] = 0;
            break;
        case 3:
            _waveThree[i][5] = 0;
            break;
        case 4:
            _waveFour[i][5] = 0;
            break;
        case 5:
            _waveFive[i][5] = 0;
            break;
        case 6:
            _waveSix[i][5] = 0;
            break;
        case 7:
            _waveSeven[i][5] = 0;
            break;
        case 8:
            _waveEight[i][5] = 0;
            break;
        case 9:
            _waveNine[i][5] = 0;
            break;
        case 10:
            _waveTen[i][5] = 0;
            break;
        default:
            break;
    }
}

void rtype::Script::parseScript()
{
    std::ifstream file;
    file.open("src/script/script.txt");
    std::string line;
    std::string value;
    
    while (std::getline(file, line)) {
        std::stringstream buffer(line);
        std::vector<int> tmp;
        while (std::getline(buffer, value, ' ')) {
            tmp.push_back(std::stoi(value));
        }
        switch (tmp.at(1)) {
            case 1:
                this->_waveOne.push_back(tmp);
                break;
            case 2:
                this->_waveTwo.push_back(tmp);
                break;
            case 3:
                this->_waveThree.push_back(tmp);
                break;
            case 4:
                this->_waveFour.push_back(tmp);
                break;
            case 5:
                this->_waveFive.push_back(tmp);
                break;
            case 6:
                this->_waveSix.push_back(tmp);
                break;
            case 7:
                this->_waveSeven.push_back(tmp);
                break;
            case 8:
                this->_waveEight.push_back(tmp);
                break;
            case 9:
                this->_waveNine.push_back(tmp);
                break;
            case 10:
                this->_waveTen.push_back(tmp);
                break;
            default:
                break;
        }
    }
}
