#include <iostream>

int main ()
{
    std::string hi = "HI THIS IS BRAIN";
    std::string* stringPTR = &hi;
    std::string& stringREF = hi;
    std::cout << "hi: " << &hi << std::endl;
    std::cout << "sP: " << &stringPTR << std::endl;
    std::cout << "sR: " << &stringREF << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << "value hi: " << hi << std::endl;
    std::cout << "value sP: " << stringPTR << std::endl;
    std::cout << "value sR: " << stringREF << std::endl;
}