#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
    {
      AForm *p = 0;
      std::cout << std::endl << "\033[1;33mworking workflow -- ShrubberyCreationForm\033[1;0m" << std::endl;
      try
      {
         Bureaucrat executor("Smith", 137);
         Bureaucrat secretary("Roberge", 145);
         std::cout << executor << std::endl;
         std::cout << secretary << std::endl;
         std::cout << std::endl;

         p = new ShrubberyCreationForm("Jardin");

         std::cout << std::endl;
         std::cout << *p << std::endl;
         std::cout << std::endl;

         p->beSigned(secretary);
         p->execute(executor);
      }
      catch (std::exception &e)
      {
         std::cout << e.what() << std::endl;
      }
      delete p;
   }
   {
      AForm *p = 0;
      std::cout << std::endl << "\033[1;33mworking workflow -- RobotomyRequestForm\033[1;0m" << std::endl;
      try
      {
         Bureaucrat executor("Smith", 45);
         Bureaucrat secretary("Roberge", 72);
         std::cout << executor << std::endl;
         std::cout << secretary << std::endl;
         std::cout << std::endl;

         p = new RobotomyRequestForm("Jardin");
         std::cout << std::endl;
         std::cout << *p << std::endl;
         std::cout << std::endl;

         p->beSigned(secretary);
         p->execute(executor);
      }
      catch (std::exception &e)
      {
         std::cout << e.what() << std::endl;
      }
      delete p;
    }
   {
      AForm *p = 0;
      std::cout << std::endl << "\033[1;33mworking workflow -- PresidentialPardonForm\033[1;0m" << std::endl;
      try
      {
         Bureaucrat executor("Smith", 5);
         Bureaucrat secretary("Roberge", 25);
         std::cout << executor << std::endl;
         std::cout << secretary << std::endl;
         std::cout << std::endl;

         p = new PresidentialPardonForm("Jardin");
         std::cout << *p << std::endl;
         std::cout << std::endl;

         p->beSigned(secretary);
         p->execute(executor);
      }
      catch (std::exception &e)
      {
         std::cout << e.what() << std::endl;
      }
      delete p;
    }
   {
      AForm *p = 0;
      std::cout << std::endl << "\033[1;33msecretary can't sign the presidential\033[1;0m" << std::endl;
      try
      {
         Bureaucrat executor("Smith", 5);
         Bureaucrat secretary("Roberge", 26);
         std::cout << executor << std::endl;
         std::cout << secretary << std::endl;
         std::cout << std::endl;

         p = new PresidentialPardonForm("Jardin");
         std::cout << *p << std::endl;
         std::cout << std::endl;

         p->beSigned(secretary);
         p->execute(executor);
      }
      catch (std::exception &e)
      {
         std::cout << e.what() << std::endl;
      }
      delete p;
   }
   {
      AForm *p = 0;
      std::cout << std::endl << "\033[1;33mexecutor can't do the presidential\033[1;0m" << std::endl;
      try
      {
         Bureaucrat executor("Smith", 6);
         Bureaucrat secretary("Roberge", 25);
         std::cout << executor << std::endl;
         std::cout << secretary << std::endl;
         std::cout << std::endl;

         p = new PresidentialPardonForm("Jardin");
         std::cout << *p << std::endl;
         std::cout << std::endl;

         p->beSigned(secretary);
         p->execute(executor);
      }
      catch (std::exception &e)
      {
         std::cout << e.what() << std::endl;
      }
      delete p;
   }
    return (0);
}