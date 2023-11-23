#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

// Cannot be instantiated so the Constructors and Destructors should be private
class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& src);
		~Serializer();
		Serializer& operator=(const Serializer& rhs);
    protected:
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif