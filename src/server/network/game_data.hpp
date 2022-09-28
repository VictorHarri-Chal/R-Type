/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** game_data
*/

#ifndef GAME_DATA_HPP_
#define GAME_DATA_HPP_

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace network {
    enum request {
        JOIN,
        CREATE,
        LEAVE,
        START,
    };
    class GameData {
        public:

            GameData(enum request request, int data_length, std::string data) : _request(request), _data_length(data_length), _data(data) {};

            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive& ar, const unsigned int version) {
                ar & _request & _data_length & _data;
            }
        private:
            enum network::request _request;
            int _data_length;
            std::string _data;
    };
}

#endif /* !GAME_DATA_HPP_ */
