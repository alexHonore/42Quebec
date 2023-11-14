#include "Fixed.hpp"

Fixed::Fixed(void){
    std::cout << "Default constructor called" << std::endl;
    this->_nb = 0;
    return;
}
Fixed::Fixed(const int nb){
    std::cout << "int constructor called" << std::endl;
    this->_nb = (nb << Fixed::_bits);
    return;
}
Fixed::Fixed(const float nb){
    std::cout << "Float constructor called" << std::endl;
    this->_nb = (int)roundf(nb * (1 << Fixed::_bits));
    return;
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
    return;
}
Fixed::Fixed(Fixed const & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}
Fixed &Fixed::operator=(Fixed const & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return *this;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_nb;
}
void Fixed::setRawBits(int const raw){
    this->_nb = raw;
    return;
}
float Fixed::toFloat() const{
    return ((float)this->_nb / (float)(1 << Fixed::_bits));
}

int Fixed::toInt() const{
    return (this->_nb >> Fixed::_bits);
}

// insert a ',' at the [o] output
std::ostream & operator<<(std::ostream & out, const Fixed & rhs){
    out << rhs.toFloat();
    return out;
}