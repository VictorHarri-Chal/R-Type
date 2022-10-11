/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "server.hpp"
#include <istream>
using boost::asio::ip::udp;

// message decryptMessage(boost::array<char, 64> _recv_buffer)
message decryptMessage(std::string _recv_buffer)
{
    std::ofstream out("filename");

    /*create a binary_oarchive object to archive an array to a binary file*/
    boost::archive::binary_oarchive binary_output_archive(out, boost::archive::no_header);

    /*create an object of class*/
    message object1(message::DELETE, "hello world");

    /*archive a class object using & */
    binary_output_archive & BOOST_SERIALIZATION_NVP(object1);

    /*display the content of archived object to console*/
    std::cout << "Ecriture" << std::endl;
    object1.print();

    /*disconnect the file*/
    out.close();
    // std::ifstream in("filename");
    // std::string tmp;

    // in >> _recv_buffer;
    // in.close();

    // std::cout << "Lecture" << std::endl;
    // std::ofstream out2("filename");

    // // out2 << _recv_buffer;
    // out2.close();
    // std::cout << "reecriture" << std::endl;
    std::ifstream in2("filename");
    /*create a binary_iarchive object to restore the archieved content*/
    boost::archive::binary_iarchive binary_input_archive(in2, boost::archive::no_header);
    message recv(message::request::CREATE, "Room 1");
    binary_input_archive & BOOST_SERIALIZATION_NVP(recv);
    in2.close();
    std::cout << "reLecture" << std::endl;
    recv.print();
    std::cout << "Apres print" << std::endl;

    return (recv);
}

// TODO: Add class constructor here

void Server::start_receive()
{
  std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recv_buffer), _remote_endpoint,
      boost::bind(&Server::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Server::handle_receive(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
  {
    if (!error || error == boost::asio::error::message_size)
    {
      decryptMessage(_recv_buffer);
      // queue.push(); 

      // boost::shared_ptr<std::string> message(
      //     new std::string("hello world"));

      // _socket.async_send_to(boost::asio::buffer(*message), _remote_endpoint,
      //     boost::bind(&Server::handle_send, this, message,
      //       boost::asio::placeholders::error,
      //       boost::asio::placeholders::bytes_transferred));
      // _recv_buffer.assign(0);
      start_receive();
    }
}

void Server::handle_send(boost::shared_ptr<std::string> /*message*/,
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{
}
