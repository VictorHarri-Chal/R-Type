/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Rooms
*/

#pragma once

/**
 * @brief Room struct
 *
 * @param id Room id
 * @param slot Room slot
 * @param name Room name
 * @param currPlayers Room current players
 * @param isOpen Boolean if room is open
 *
 */
struct room_t {
    /**
     * @brief Room id
     *
     */
    int id;
    /**
     * @brief Room slot
     *
     */
    int slot;
    /**
     * @brief Room name
     *
     */
    std::string name;
    /**
     * @brief Room current players
     *
     */
    unsigned int currPlayers;
    /**
     * @brief Boolean if room is open
     *
     */
    bool isOpen;
};
