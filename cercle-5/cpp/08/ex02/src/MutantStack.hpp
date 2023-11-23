#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
    private:
    protected:
    public:
        MutantStack();
        MutantStack(const MutantStack& original);
        MutantStack& operator=(const MutantStack& original);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin(void);
        iterator end(void);
};

#include "MutantStack.tpp"

#endif