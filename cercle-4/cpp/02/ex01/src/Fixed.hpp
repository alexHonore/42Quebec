#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    public:
        //Name of class for constructor
        Fixed(void);
        //Name of class for constructor
        Fixed(const int nb);
        //Name of class for constructor
        Fixed(const float nb);
        // Copy of the class from the instance src(new of the current instance)
        Fixed(Fixed const & src);
        //Tilt before class name for destructor
        ~Fixed(void);

        // Assiniation from another instance of the class(update of the current instance) 
        Fixed & operator=(Fixed const & rhs);
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
    private:
        int _nb;
        static const int _bits = 8;
};

std::ostream & operator<<(std::ostream & out, Fixed const & rhs);

#endif