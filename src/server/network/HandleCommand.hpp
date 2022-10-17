/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** HandleCommand
*/

#pragma once

#include "../../utils/Message.hpp"
#include <vector>
#include <functional>

class HandleCommand
{
private:
  std::vector<std::function<void(int)>> _allCommand;

public:
    HandleCommand();
    ~HandleCommand() = default;
    void findCmd(message command);
};
