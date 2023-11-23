#include "Span.hpp"

Span::Span() : _N(0) {

}
Span::Span(unsigned int N) : _N(N) {

}
Span::Span(const Span& src) : _N(src._N), _vec(src._vec) {

}
Span::~Span() {

}
Span &Span::operator=(const Span& rhs) {
    if (this != &rhs) {
        this->_N = rhs._N;
        this->_vec.clear();
        std::copy(rhs._vec.begin(), rhs._vec.end(), this->_vec.begin());
    }
    return (*this);
}

void Span::addNumberRange(int num) {
    if (this->_vec.size() == this->_N)
        throw Span::VectorFullException();
    this->_vec.push_back(num);
}
unsigned int Span::shortestSpan() {
    if (this->_vec.size() < 2)
        throw Span::SizeTooSmallException();
    unsigned int minSpan = UINT_MAX; // largest possible span between two numbers
    for (unsigned int i = 0; i < this->_vec.size(); i++)
    {
        for (unsigned int j = i + 1; j < this->_vec.size(); j++)
        {
            unsigned int span = abs(this->_vec[i] - this->_vec[j]);
            if (span < minSpan) {
                minSpan = span;
            }
        }
    }
    return (minSpan);
}
unsigned int Span::longestSpan() {
    if (this->_vec.size() < 2)
        throw Span::SizeTooSmallException();
    int min = *(std::min_element(this->_vec.begin(), this->_vec.end()));
    int max = *(std::max_element(this->_vec.begin(), this->_vec.end()));
    return (static_cast<unsigned int>(max - min));
}
void Span::fill(void) {
    this->_vec.resize(this->_N);
    std::generate(this->_vec.begin(), this->_vec.end(), &gen);
}
std::size_t Span::getSize() const {
    return (this->_vec.size());
}
void Span::printVec() {
    for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
int gen(void) {
    return(std::rand() % 10000);
}
