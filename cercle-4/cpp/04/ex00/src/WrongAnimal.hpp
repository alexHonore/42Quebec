#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

// Abstract class
class WrongAnimal{
    private:
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal(const std::string &name);
        virtual ~WrongAnimal();
        WrongAnimal & operator=(const WrongAnimal & rhs);
        const std::string &getType() const;
        virtual void makeSound() const;
};

#endif