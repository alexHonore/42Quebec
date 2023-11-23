#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _vec;
    protected:
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span&    operator=(const Span& rhs);
        ~Span();

        void addNumberRange(int num);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        void fill(void);
        std::size_t getSize() const;
        void printVec();

        class VectorFullException : public std::exception {
            public:
                virtual const char *what() const throw(){
                    return ("Span::VectorFullException: Vector is full.");
                }
        };
        class SizeTooSmallException : public std::exception {
            public:
                virtual const char *what() const throw(){
                    return ("Span::SizeTooSmallException: Vector size is too small.");
                }
        };
};
int gen(void);

#endif