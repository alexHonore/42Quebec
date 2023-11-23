#include "Serializer.hpp"

int main()
{
	Data data = {"Bop Bip Bop", 5};

	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Data content(string): " << data.content << std::endl;
	std::cout << "Data content(int): " << data.i << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "Serialized address: " << &ptr << std::endl;
	std::cout << "Deserialized address: " << Serializer::deserialize(ptr) << std::endl;

   return 0;
}