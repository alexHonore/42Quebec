#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

// Abstract class
class Animal{
    private:
    protected:
        std::string type;
        Animal(const std::string &name);
    public:
        Animal();
        Animal(const Animal &src);
        virtual ~Animal();
        Animal & operator=(const Animal & rhs);
        const std::string &getType() const;
        virtual void makeSound() const;
        virtual Brain* getBrain() const = 0;
};

#endif