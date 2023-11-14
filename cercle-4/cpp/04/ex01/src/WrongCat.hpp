#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

// Abstract class
class WrongCat : public WrongAnimal{
    private:
    protected:
    public:
        WrongCat();
        WrongCat(const WrongCat &src);
        ~WrongCat();
        WrongCat & operator=(WrongCat const & rhs);
        void makeSound() const;
};

#endif