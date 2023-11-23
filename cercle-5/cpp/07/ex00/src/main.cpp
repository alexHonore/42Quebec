#include "whatever.hpp"

int main() {

	int a = 2;
	int b = 3;
	swap(a, b);
	std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "--------------------" << std::endl;

	std::string c = "string 1";
	std::string d = "string 2";
	swap(c, d);
	std::cout << "c = " << c << std::endl << "d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}