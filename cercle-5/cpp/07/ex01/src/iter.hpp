#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *arr, int len, void (*f)(T&)) {
	for (int i = 0; i < len; i++){
		f(arr[i]);
	}
}

template <typename T> void print(T& a) {
	std::cout << a << " ";
}

#endif