#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

// Abstract class
class Dog : public Animal{
    private:
    protected:
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog();
        Dog & operator=(Dog const & rhs);
        void makeSound() const;
};

#endif