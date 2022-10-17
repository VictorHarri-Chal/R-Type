/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** HandleCommand
*/

#include "HandleCommand.hpp"

static void CreateCommand(int value)
{
    std::cout << "Create Command value = " << value << std::endl;
}

static void JoinCommand(int value)
{
    std::cout << "Join Command value = " << value << std::endl;
}

static void DeleteCommand(int value)
{
    std::cout << "Delete Command value = " << value << std::endl;
}

static void LaunchCommand(int value)
{
    std::cout << "Launch Command value = " << value << std::endl;
}

static void DisconectCommand(int value)
{
    std::cout << "Disconect Command value = " << value << std::endl;
}

static void RoomCommand(int value)
{
    std::cout << "Room Command Asked" << std::endl;
}

HandleCommand::HandleCommand() {
    _allCommand.emplace_back(CreateCommand);
    _allCommand.emplace_back(JoinCommand);
    _allCommand.emplace_back(DeleteCommand);
    _allCommand.emplace_back(LaunchCommand);
    _allCommand.emplace_back(DisconectCommand);
    _allCommand.emplace_back(RoomCommand);
}

void HandleCommand::findCmd(message command)
{
    this->_allCommand[command.type](command.value);
}
