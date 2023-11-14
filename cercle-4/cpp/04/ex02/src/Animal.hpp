#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

// Abstract class (for real) with no constructor
class Animal{
    private:
    protected:
        std::string type;
    public:
        virtual ~Animal() = 0;
        virtual Animal & operator=(const Animal & rhs) = 0;
        const std::string &getType() const;
        virtual void makeSound() const = 0;
        virtual Brain* getBrain() const = 0;
};

#endif