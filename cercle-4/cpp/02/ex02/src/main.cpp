#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "min of d with a vs b is " << Fixed::min(a, b).toFloat() << std::endl;
    std::cout << "max of d with a vs b is " << Fixed::max(a, b).toFloat() << std::endl;
    return (0);
}