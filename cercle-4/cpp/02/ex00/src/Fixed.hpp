#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        //Name of class for constructor
        Fixed();
        // Copy of the class from the instance src(new of the current instance)
        Fixed(Fixed const & src);
        //Tilt before class name for destructor
        ~Fixed(void);
        
        // Assiniation from another instance of the class(update of the current instance) 
        Fixed & operator=(Fixed const & rhs);
        int getRawBits() const;
        void setRawBits(int const raw);
    private:
        int _nb;
        static const int _bits = 8;
};

#endif