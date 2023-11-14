#include "Fixed.hpp"

Fixed::Fixed(void){
    this->_nb = 0;
    return;
}
Fixed::Fixed(const int nb){
    this->_nb = (nb << Fixed::_byte);
    return;
}
Fixed::Fixed(const float nb){
    this->_nb = (int)roundf(nb * (1 << Fixed::_byte));
    return;
}

Fixed::~Fixed(void){
    return;
}
Fixed::Fixed(Fixed const & src){
    *this = src;
}
Fixed &Fixed::operator=(Fixed const & rhs){
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return *this;
}

int Fixed::getRawBits() const{
    return this->_nb;
}
void Fixed::setRawBits(int const raw){
    this->_nb = raw;
    return;
}
float Fixed::toFloat() const{
    return ((float)this->_nb / (float)(1 << Fixed::_byte));
}

int Fixed::toInt() const{
    return (this->_nb >> Fixed::_byte);
}

// insert a ',' at the [o] output
std::ostream & operator<<(std::ostream & out, const Fixed & rhs){
    out << rhs.toFloat();
    return out;
}

Fixed& Fixed::min(Fixed &nb1, Fixed &nb2){
    if (nb1.getRawBits() < nb2.getRawBits())
        return nb1;
    return nb2;
}

const Fixed& Fixed::min(const Fixed &nb1, const Fixed &nb2){
    if (nb1.getRawBits() < nb2.getRawBits())
        return nb1;
    return nb2;
}

Fixed& Fixed::max(Fixed &nb1, Fixed &nb2){
    if (nb1.getRawBits() > nb2.getRawBits())
        return nb1;
    return nb2;
}

const Fixed& Fixed::max(const Fixed &nb1, const Fixed &nb2){
    if (nb1.getRawBits() > nb2.getRawBits())
        return nb1;
    return nb2;
}

bool    Fixed::operator>(const Fixed & rhs)const{
    return (this->getRawBits() > rhs.getRawBits());
}

bool    Fixed::operator<(const Fixed & rhs)const{
    return (this->getRawBits() < rhs.getRawBits());
}

bool    Fixed::operator>=(const Fixed & rhs)const{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool    Fixed::operator<=(const Fixed & rhs)const{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool    Fixed::operator==(const Fixed & rhs)const{
    return (this->getRawBits() == rhs.getRawBits());
}

bool    Fixed::operator!=(const Fixed & rhs)const{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed   Fixed::operator+(const Fixed & rhs)const{
    Fixed res;
    res.setRawBits(this->getRawBits() + rhs.getRawBits());
    return res;
}

Fixed   Fixed::operator-(const Fixed & rhs)const{
    Fixed res;
    res.setRawBits(this->getRawBits() - rhs.getRawBits());
    return res;   
}

Fixed   Fixed::operator*(const Fixed & rhs)const{
    Fixed res;
    res.setRawBits(this->getRawBits() * rhs.getRawBits() >> Fixed::_byte);
    return res;
}

Fixed   Fixed::operator/(const Fixed & rhs)const{
    if (rhs.getRawBits() == 0)
    {
        std::cout << "Cannot divide with zero..." << std::endl;
        return (Fixed(0));
    }
        return (Fixed(this->toFloat() / rhs.toFloat()));
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed & Fixed::operator++(void){
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed & Fixed::operator--(void){
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed   Fixed::operator++(int){
    Fixed res(*this);

    this->setRawBits(this->getRawBits() + 1);
    return res;
}

Fixed   Fixed::operator--(int){
    Fixed res(*this);

    this->setRawBits(this->getRawBits() - 1);
    return res;
}