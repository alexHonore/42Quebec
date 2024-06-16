#include "RPN.hpp"

// Push each operand in a stack
// When an operator is encountered, it pops the necessary operands,
// make the operation and pushes the result back into the stack

RPN::RPN(std::string operation){
    this->launch(operation);
}
RPN::RPN(const RPN & src){
    this->numberStack = src.numberStack;
}
RPN::~RPN(){

}
RPN & RPN::operator=(const RPN & rhs){
    if (this != &rhs)
        this->numberStack = rhs.numberStack;
    return *this;
}
bool RPN::isOperand(char c){
    return (c >= '0' && c <= '9');
}
bool RPN::isOperator(char c){
    return (c == '+'|| c == '-'|| c == '*'|| c == '/' || c == '^');
}
int RPN::compute(int operandA, int operandB, char operatorr){
    if(operatorr == '+'){
      return operandB + operandA;
    }
    else if(operatorr == '-')
       return operandB - operandA;
    else if(operatorr == '*')
       return operandB * operandA;
    else if(operatorr == '/')
       return operandB / operandA;
    else if(operatorr == '^')
       return pow(operandB, operandA);
    else
       return INT_MIN;
}
void RPN::launch(std::string operation){
    int a, b;

    for (std::string::iterator it = operation.begin(); it != operation.end(); it++) {
        if (*it == ' ')
            continue;
        else if (this->isOperand(*it)){
            // converts the char to int & add it to the stack
            this->numberStack.push(int(*it - '0'));
        }
        else if (this->isOperator(*it)){
            // compute last two & add res to stack
            // if there's no two nb before the operator, it's an error
            if (this->numberStack.empty())
                throw("Error: No operand (A) to compute");
            a = this->numberStack.top();
            this->numberStack.pop();
            if (this->numberStack.empty())
                throw("Error: No operand (B) to compute");
            b = this->numberStack.top();
            this->numberStack.pop();
            this->numberStack.push(compute(a, b, *it));
        }
        else{
            throw("Error: Not a valid character");
        }
    }
    std::cout << this->numberStack.top() << std::endl;
}