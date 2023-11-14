#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

// Abstract class
class Cat : public Animal{
    private:
    protected:
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();
        Cat & operator=(Cat const & rhs);
        void makeSound() const;
};

#endif