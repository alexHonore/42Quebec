#include "Convert.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
       return (1);
    try
    {
       Convert arg(argv[1]);
       std::cout << arg << std::endl;
    }
    catch (Convert::InvalidLitteral err)
    {
       std::cout << err.what() << std::endl;
    }
    catch (std::exception &e)
    {
       std::string err = e.what();
       if (err.compare("stoi: out of range") == 0)
          std::cout << "Error : Out of bounds" << std::endl;
       else{
          std::cout << "char:\timpossible" << std::endl
          << "int:\timpossible" << std::endl
          << "float:\t" << e.what() << "f" << std::endl
          << "double:\t" << e.what() << std::endl;
       }
    }
    return (0);
}