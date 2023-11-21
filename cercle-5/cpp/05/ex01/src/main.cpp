#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat b1 = Bureaucrat();
        Bureaucrat b2 = Bureaucrat("Test", 4);
        Bureaucrat b3 = Bureaucrat();
        b3 = b2;
        std::cout << "--------------------" << std::endl;
        std::cout << b2 << std::endl;
        std::cout << "--------------------" << std::endl;
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------Test 2----------" << std::endl;
    try{
        Bureaucrat b1 = Bureaucrat("Promotion tryhard", 4);
        Bureaucrat b2 = Bureaucrat("Test2", 148);
        Bureaucrat b3 = Bureaucrat();
        b3 = b2;
        std::cout << "--------------------" << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << " got a promotion and is at no." << b1.getGrade() << " spot" << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << " got a promotion and is at no." << b1.getGrade() << " spot" << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << " got a promotion and is at no." << b1.getGrade() << " spot" << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << " got a promotion and is at no." << b1.getGrade() << " spot" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "--------------------" << std::endl;
        b3.decrementGrade();
        std::cout << b3.getName() << " got a downgrade and is at no." << b3.getGrade() << " spot" << std::endl;
        b3.decrementGrade();
        std::cout << b3.getName() << " got a downgrade and is at no." << b3.getGrade() << " spot" << std::endl;
        b3.decrementGrade();
        std::cout << b3.getName() << " got a downgrade and is at no." << b3.getGrade() << " spot" << std::endl;
        b3.decrementGrade();
        std::cout << b3.getName() << " got a downgrade and is at no." << b3.getGrade() << " spot" << std::endl;
        std::cout << "--------------------" << std::endl;
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}