#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class OccurrenceNotFoundException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Exception: No occurrence found");
        }
};

#include "easyfind.tpp"

#endif