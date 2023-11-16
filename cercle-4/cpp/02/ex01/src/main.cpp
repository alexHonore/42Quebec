#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1224.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as int" << std::endl;
    std::cout << "b is " << b.toInt() << " as int" << std::endl;
    std::cout << "c is " << c.toInt() << " as int" << std::endl;
    std::cout << "d is " << d.toInt() << " as int" << std::endl;
    return (0);
}