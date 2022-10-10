/*include iostream for console I/O*/
#include <iostream>

/*include fstream for file I/O*/
#include <fstream>

/*include binary_oarchive.hpp for binary_oacrhive*/
#include <boost/archive/binary_oarchive.hpp>

/*include binary_iarchive.hpp for binary_iacrhive*/
#include <boost/archive/binary_iarchive.hpp>



/*declaration of class to be archived*/
class message{
public:
    enum request {
        CREATE,
        JOIN,
        DELETE,
        LAUNCH,
        DISCONNECT
    };
    /*public access is required for the class member which are to be saved/loaded*/
    request type;
    std::string body;

    /*default constructor for class*/
    message(){};
    /*parameterized constructor for class*/
    message(request t, std::string b) : type(t), body(b){}

    /*this function prints the details of class object*/
    void print(){
        std::cout << "(" << type << ", " << body.size() << ", " << body  << ")" <<  std::endl;
    }

};


/*override serialize function to serialize class Class*/
namespace boost{
    namespace serialization{
        template<class Archive>
        void serialize(Archive &archive, message &object, const unsigned int version){
            archive & object.type;
            archive & object.body;
        }
    }
}

int main() {

    /*filename to work with*/
    std::string filename = "binary.txt";

    /*create an ofstream object for writing to file*/
    std::ofstream out(filename);

    /*create a binary_oarchive object to archive an array to a binary file*/
    boost::archive::binary_oarchive binary_output_archive(out, boost::archive::no_header);

    /*create an object of class*/
    message object1(message::DELETE, "hello world");

    /*archive a class object using & */
    binary_output_archive & BOOST_SERIALIZATION_NVP(object1);

    /*display the content of archived object to console*/
    std::cout << "Archived to " << filename << std::endl;
    object1.print();

    /*disconnect the file*/
    out.close();

    /*create an ifstream object for reading from file*/
    std::ifstream in(filename);

    /*create a binary_iarchive object to restore the archieved content*/
    boost::archive::binary_iarchive binary_input_archive(in, boost::archive::no_header);

    /*create an object to store the restored data*/
    message object2;

    /*restore the archived content using &*/
    binary_input_archive & BOOST_SERIALIZATION_NVP(object2);

    /*disconnect the file*/
    in.close();

    /*display the restored content to console*/
    std::cout << "Restored archived content from " << filename << " : " << std::endl;
    object2.print();

    /*return 0 to caller*/
    return 0;
}