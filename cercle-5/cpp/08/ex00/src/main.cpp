#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    std::cout << std::endl << "\033[1;32mVECTOR INIT\033[1;0m" << std::endl;
    std::vector<int> vec;
    
    vec.push_back(17);
    vec.push_back(54);
    vec.push_back(86);
    vec.push_back(82);

    std::cout << std::endl << "\033[1;32mVECTOR VALUES:\033[1;0m" << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    try {
        easyfind(vec, 54);
        easyfind(vec, 86);
        easyfind(vec, 75);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl << "\033[1;32mLIST INIT\033[1;0m" << std::endl;
    std::list<int> lst;
    
    lst.push_back(57);
    lst.push_back(95);
    lst.push_back(857);
    lst.push_back(8);

    std::cout << std::endl << "\033[1;32mLIST VALUES:\033[1;0m" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    try {
        easyfind(lst, 57);
        easyfind(lst, 857);
        easyfind(lst, 7);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}