#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain constructor" << std::endl;
}
Brain::Brain(const Brain &src){
    std::cout << "Brain copy constructor" << std::endl;
    *this = src;
}
Brain::~Brain(){
    std::cout << "Brain destructor" << std::endl;
}
Brain & Brain::operator=(const Brain & rhs){
    std::cout << "Brain copy assignment constructor" << std::endl;
    if (this != &rhs){
        for(int i = 0; i < 100; i++){
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}
const std::string& Brain::getIdea(unsigned int i) const{
    return this->ideas[i];
}
void Brain::addIdea(std::string idea){
    int i = 0;
    while(!this->ideas[i].empty())
        i++;
    if (i > 99)
        return;
    this->ideas[i] = idea;
}