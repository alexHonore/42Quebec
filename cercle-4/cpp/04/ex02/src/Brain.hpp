#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

// Abstract class
class Brain{
    private:
    protected:
    public:
        Brain();
        Brain(const Brain &src);
        ~Brain();
        Brain & operator=(const Brain & rhs);
        std::string ideas[100];
        const std::string& getIdea(unsigned int i) const;
        void addIdea(std::string idea);
};

#endif