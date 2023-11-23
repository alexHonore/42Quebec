#include "Array.hpp"

int main() {
	std::cout << std::endl << "\033[1;32mTESTS\033[1;0m" << std::endl;
    int * a = new int();
    std::cout << *a << std::endl;
    delete a;
    
	std::cout << std::endl << "\033[1;32mInt Array\033[1;0m" << std::endl;
    Array<int> intArray1((unsigned int)10);
    Array<int> intArray2;

    intArray2 = intArray1;

    unsigned int size1 = intArray1.size();
    unsigned int size2 = intArray2.size();
	// print size (10)
    std::cout << intArray1.size() << std::endl;
    std::cout << intArray2.size() << std::endl;
    
    for (unsigned int i = 0; i < size1; i++)
        intArray1[i] = 42;
    std::cout << std::endl;

	// 42's
    for (unsigned int i = 0; i < size1; i++)
        std::cout << intArray1[i] << " ";
    std::cout << std::endl;

	// 0's
    for (unsigned int i = 0; i < size2; i++)
        std::cout << intArray2[i] << " ";
    std::cout << std::endl;

	std::cout << std::endl << "\033[1;32mChar Array\033[1;0m" << std::endl;
    Array<char> charArray1((unsigned int)10);
    Array<char> charArray2;

    charArray2 = charArray1;

    unsigned int size3 = charArray1.size();
    unsigned int size4 = charArray2.size();
	// print size (10)
    std::cout << charArray1.size() << std::endl;
    std::cout << charArray2.size() << std::endl;
    
    for (unsigned int i = 0; i < size3; i++)
        charArray1[i] = 'A';
    std::cout << std::endl;

	// A's
    for (unsigned int i = 0; i < size3; i++)
        std::cout << charArray1[i] << " ";
    std::cout << std::endl;

	// nothing
    for (unsigned int i = 0; i < size4; i++)
        std::cout << charArray2[i] << " ";
    std::cout << std::endl;

	std::cout << std::endl << "\033[1;32mExceptions\033[1;0m" << std::endl;
    try {
        intArray1[20];
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        charArray1[50];
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}