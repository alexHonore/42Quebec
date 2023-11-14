#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *animals[10];

    std::cout << "Unleash the animals" << std::endl;
    for (int i = 0; i < 10; i++){
        if (i % 2 == 0)
            animals[i]  = new Dog();
        else
            animals[i]  = new Cat();
    }
    std::cout << "Who let the dogs out?!?!(and the cats...)" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Anyways, animals getting some ideas:" << std::endl;
    for (int i = 0; i < 10; i++){
        if (animals[i]->getType() == "Dog")
            animals[i]->getBrain()->addIdea("I want a bone!");
        else
            animals[i]->getBrain()->addIdea("I want a fish!");
        std::cout << animals[i]->getBrain()->getIdea(0) << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "The cat number 3 is getting real smart! :" << std::endl;
    animals[3]->getBrain()->addIdea("Wait, I'm a conscious!?");
    animals[3]->getBrain()->addIdea("Am I a king?");
    animals[3]->getBrain()->addIdea("Who are these humans???");
    animals[3]->getBrain()->addIdea("I'm too tired for this bs");
    for (int i = 0; !animals[3]->getBrain()->getIdea(i).empty(); i++){
        std::cout << animals[3]->getBrain()->getIdea(i) << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    for (int i = 0; i < 10; i++){
        delete animals[i];
    }
    return 0;
}