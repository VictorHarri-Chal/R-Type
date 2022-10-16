/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** HandleCommand
*/

#include "HandleCommand.hpp"

static void CreateCommand(int Value)
{
    std::cout << "Create Command Value = " << Value << std::endl; 
}

static void JoinCommand(int Value)
{
    std::cout << "Join Command Value = " << Value << std::endl; 
}

static void DeleteCommand(int Value)
{
    std::cout << "Delete Command Value = " << Value << std::endl; 
}

static void LaunchCommand(int Value)
{
    std::cout << "Launch Command Value = " << Value << std::endl; 
}

static void DisconectCommand(int Value)
{
    std::cout << "Disconect Command Value = " << Value << std::endl; 
}

HandleCommand::HandleCommand() {
    _allCommand.emplace_back(CreateCommand);
    _allCommand.emplace_back(JoinCommand);
    _allCommand.emplace_back(DeleteCommand);
    _allCommand.emplace_back(LaunchCommand);
    _allCommand.emplace_back(DisconectCommand);
};

void HandleCommand::findCmd(message command)
{
    this->_allCommand[command.type](command.value);
}
