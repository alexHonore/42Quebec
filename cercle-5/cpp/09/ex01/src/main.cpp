#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2){
        std::cout << "Error: Only one argument is valid (the operation)." << std::endl;
        return 1;
    }
    try{
        RPN rpn(argv[1]);
    }catch (const char *e)
    {
        std::cerr << e << std::endl;
        return(1);
    }
    return 0;
}