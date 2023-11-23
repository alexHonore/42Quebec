#include "iter.hpp"

int main() {
	std::cout << "Int array" << std::endl;
	int numbers[] = {-6514, -1, 0, 12, 1564};
	iter(numbers, 5, print);

	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Float array" << std::endl;
	float fNumbers[] = {-123.12, -80, -1,2, 0, 4.2, 19.20};
	iter(fNumbers, 6, ::print);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Char array" << std::endl;
	char array[] = {'a', 'b', '1', '2'};
	iter(array, 4, print);
	
	std::cout << std::endl;
	
	return 0;
}