/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** ClientBuffer
*/

#include "ClientBuffer.hpp"

void ClientBuffer::write(int i)
{
	_oStream.write(reinterpret_cast<char *>(&i), sizeof(int));
}

void ClientBuffer::write(const std::string &str)
{
	_oStream.write(str.c_str(), str.size());
}

void ClientBuffer::write(struct ClientPayload &data)
{
    write(data.request);
    write(data.data_length);
    write(data.data);
}
