#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

// Abstract class
class Dog : public Animal{
    private:
        Brain *brain;
    protected:
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog();
        Dog & operator=(Dog const & rhs);
        void makeSound() const;
        Brain* getBrain() const;
};

#endif