#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* animal = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
animal->makeSound();

delete animal;
delete i;
delete j;

std::cout << std::endl << "-----------------------------" << std::endl;
const WrongAnimal* Wanimal = new WrongAnimal();
const WrongAnimal* Wcat = new WrongCat();

std::cout << Wanimal->getType() << " " << std::endl;
std::cout << Wcat->getType() << " " << std::endl;
Wcat->makeSound();
Wanimal->makeSound();

delete Wanimal;
delete Wcat;

return 0;
}