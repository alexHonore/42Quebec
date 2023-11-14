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
        Fixed & operator=(const Fixed & rhs);
        bool    operator>(const Fixed & rhs)const;
        bool    operator<(const Fixed & rhs)const;
        bool    operator>=(const Fixed & rhs)const;
        bool    operator<=(const Fixed & rhs)const;
        bool    operator==(const Fixed & rhs)const;
        bool    operator!=(const Fixed & rhs)const;
        Fixed   operator+(const Fixed & rhs)const;
        Fixed   operator-(const Fixed & rhs)const;
        Fixed   operator*(const Fixed & rhs)const;
        Fixed   operator/(const Fixed & rhs)const;
        Fixed & operator++(void);
        Fixed & operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;

        static Fixed&        min(Fixed &nb1, Fixed &nb2);
        static const Fixed&  min(const Fixed &nb1, const Fixed &nb2);
        static Fixed&        max(Fixed &nb1, Fixed &nb2);
        static const Fixed&  max(const Fixed &nb1, const Fixed &nb2);
    private:
        int _nb;
        static const int _byte = 8;
};

std::ostream & operator<<(std::ostream & out, Fixed const & rhs);

#endif