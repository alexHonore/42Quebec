#ifndef RPN_HPP
# define RPN_HPP

#include<iostream>
// #include<cmath>
#include<stack>
// #include<climits>
#include <string.h>

class RPN {
    private:
        std::stack<int> numberStack;
    protected:
    public:
        RPN(std::string operation);
        RPN(const RPN & src);
        ~RPN();
        RPN & operator=(const RPN & rhs);
        bool isOperand(char c);
        bool isOperator(char c);
        int compute(int operandA, int operandB, char operatorr);
        void launch (std::string operation);
};

#endif