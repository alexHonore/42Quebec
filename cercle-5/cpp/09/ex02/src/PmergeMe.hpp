#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>

template <typename T>
void swap(T& container, int i){
    int temp = container[i];
    container[i] = container[i + 1];
    container[i + 1] = temp;
}

void	sortvector(std::vector<int>& Container, int size);
void	sortdeque(std::deque<int>& Container, int size);