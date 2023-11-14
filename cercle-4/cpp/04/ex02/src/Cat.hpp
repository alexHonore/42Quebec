#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

// Abstract class
class Cat : public Animal{
    private:
        Brain *brain;
    protected:
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();
        Cat & operator=(Cat const & rhs);
        Animal &operator=(Animal const & rhs);
        void makeSound() const;
        Brain* getBrain() const;
};

#endif