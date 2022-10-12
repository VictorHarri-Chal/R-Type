/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** HandleCommand
*/

#include "HandleCommand.hpp"

static void CreateCommand(std::string Body)
{
    std::cout << "Create Command Body = " << Body << std::endl; 
}

static void JoinCommand(std::string Body)
{
    std::cout << "Join Command Body = " << Body << std::endl; 
}

static void DeleteCommand(std::string Body)
{
    std::cout << "Delete Command Body = " << Body << std::endl; 
}

static void LaunchCommand(std::string Body)
{
    std::cout << "Launch Command Body = " << Body << std::endl; 
}

static void DisconectCommand(std::string Body)
{
    std::cout << "Disconect Command Body = " << Body << std::endl; 
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
    if (command.body.size() <= 0)
        return;
    this->_allCommand[command.type](command.body);
}
