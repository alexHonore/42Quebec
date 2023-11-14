#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
    this->_contact_index = 0;
    this->_nb_contacts = 0;
    return;
}

PhoneBook::~PhoneBook(void){
    return;
}

void PhoneBook::start(void){
    std::string buffer = "";
    std::cout << "|---------- My PhoneBook!! -----------|" << std::endl;
    std::cout << "| Type one of the following:          |" << std::endl;
    std::cout << "|     [ADD]    [SEARCH]    [EXIT]     |" << std::endl;
    std::cout << "|-------------------------------------|" << std::endl;
    while (1)
    {
        std::cout << "> ";
        getline(std::cin, buffer);
        if (std::cin.eof())
            return;
        if (buffer == "ADD")
            this->_add();
        else if (buffer == "SEARCH")
            this->_search();
        else if (buffer == "EXIT")
            return ;
    }
}

void PhoneBook::_add(void){
    this->_nb_contacts++;
    //add a new contact and create the apropriate id to it, is the contact list is full, replace the oldest one (id of 1), re-map id's and add it 
    if (this->_nb_contacts <= 8) {
        this->_contacts[this->_nb_contacts - 1].add_contact();
        // append new contact as constacts[nb_contact]
    }
    else {
        this->_nb_contacts = 8;
        if (this->_contact_index >= 8)
            this->_contact_index = 0;
        this->_contacts[this->_contact_index].add_contact();
        _contact_index++;
        // pop the contact[0], loop all contacts and decrease them,
        // then, append new contact as constacts[nb_contact]
    }
}
void PhoneBook::_search(void){
    std::string ans;
    int index;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|  index   |first name| last name| nickname |" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    for(int i = 0; i < this->_nb_contacts; i++){
        this->_contacts[i].search_contact(i);
        std::cout << std::endl;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "Type the index> ";
    getline(std::cin, ans);
    for(int i = 0; i < (int)ans.length(); i++){
        if (std::isdigit(ans[i]) == 0){
            std::cout << "Please put an index from the tab..." << std::endl;
            return;
        }
    }
    index = std::stoi(ans);
    if (!(index > 0 && index <= this->_nb_contacts)){
        std::cout << "No contact with this index was found..." << std::endl;
        return;
    }
    this->_contacts[index - 1]._print_contact(index - 1);
}