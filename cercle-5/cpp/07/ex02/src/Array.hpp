#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template <class T>
class Array {
    private:
        T* _array;
        unsigned int _n;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& src);
        Array& operator=(const Array& rhs);
        ~Array();

        T& operator[](unsigned int i);

        int size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char *what() const throw(){
                    return ("Array::exception: Index out of bounds");
                }
        };
};

#include "Array.tpp"

#endif