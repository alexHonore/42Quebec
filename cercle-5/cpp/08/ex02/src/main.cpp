#include "MutantStack.hpp"
#include <list>

int main() {
    std::cout << std::endl << "\033[1;32mMUTANT STACK\033[1;0m" << std::endl;
    std::cout << std::endl;

    MutantStack<int> mstack;
    mstack.push(2);
    mstack.push(42);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(6);
    mstack.push(144);
    mstack.push(875);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl << "\033[1;32mLIST\033[1;0m" << std::endl;
    std::cout << std::endl;

    std::list<int> list;
    list.push_back(2);
    list.push_back(42);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(6);
    list.push_back(144);
    list.push_back(875);
    list.push_back(0);
    std::list<int>::iterator it1 = list.begin();
    std::list<int>::iterator it2 = list.end();
    ++it1;
    --it1;
    while (it1 != it2)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    return 0;
}