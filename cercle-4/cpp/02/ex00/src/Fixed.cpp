#include "Fixed.hpp"

Fixed::Fixed(void){
    std::cout << "Default constructor called" << std::endl;
    this->_nb = 0;
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
        this->_nb = rhs.getRawBits();
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