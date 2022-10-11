/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "network/server.hpp"
#include "network/SafeQueue.hpp"

int main() {
    try
    {        
        boost::asio::io_context io_context;
        Server server(io_context, 4242);
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

    // /*filename to work with*/
    // std::string filename = "binary.txt";

    // /*create an ofstream object for writing to file*/
    // std::ofstream out(filename);

    // /*create a binary_oarchive object to archive an array to a binary file*/
    // boost::archive::binary_oarchive binary_output_archive(out, boost::archive::no_header);

    // /*create an object of class*/
    // message object1(message::DELETE, "hello world");

    // /*archive a class object using & */
    // binary_output_archive & BOOST_SERIALIZATION_NVP(object1);

    // /*display the content of archived object to console*/
    // std::cout << "Archived to " << filename << std::endl;
    // object1.print();

    // /*disconnect the file*/
    // out.close();

    // /*create an ifstream object for reading from file*/
    // std::ifstream in(filename);

    // /*create a binary_iarchive object to restore the archieved content*/
    // boost::archive::binary_iarchive binary_input_archive(in, boost::archive::no_header);

    // /*create an object to store the restored data*/
    // message object2;

    // /*restore the archived content using &*/
    // binary_input_archive & BOOST_SERIALIZATION_NVP(object2);

    // /*disconnect the file*/
    // in.close();

    // /*display the restored content to console*/
    // std::cout << "Restored archived content from " << filename << " : " << std::endl;
    // object2.print();

    // /*return 0 to caller*/