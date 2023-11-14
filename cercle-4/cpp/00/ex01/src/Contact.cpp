#include "Contact.hpp"

Contact::Contact(void){
    return;
}
Contact::~Contact(void){
    return;
}

std::string Contact::_ask_data(std::string msg){
    std::string buff = "";
    while (buff.length() < 1)
    {
        std::cout << msg << std::endl;
        std::cout << "> ";
        std::getline(std::cin, buff);
    }
    return buff;
}

void Contact::_print_clean(std::string data){
    std::string tmp;
    if (data.length() <= 10){
        tmp = "";
        int nb_spaces = 10 - data.length();
        for (int i = 0; i < nb_spaces; i++){
            tmp.append(" ");
        }
        tmp.append(data);
    }
    else {
        data = data.substr(0, 9);
        data.append(".");
        tmp = data;
    }
    std::cout << tmp;
}

void Contact::add_contact(void){
    this->_f_name = Contact::_ask_data("What's your first name?");
    this->_l_name = Contact::_ask_data("What's your last name?");
    this->_nickname = Contact::_ask_data("What's your nickname?");
    this->_phone_number = Contact::_ask_data("What's your phone number?");
    this->_darkest_secret = Contact::_ask_data("What's your darkest secret?");
    std::cout << std::endl << "Contact successfully added!" << std::endl;
}

void Contact::search_contact(int id){
    std::cout << "|         ";
    std::cout << id + 1;
    std::cout << "|";
    _print_clean(this->_f_name);
    std::cout << "|";
    _print_clean(this->_l_name);
    std::cout << "|";
    _print_clean(this->_nickname);
    std::cout << "|";
}

void Contact::_print_contact(int index){
    std::cout << "Index         : " << index + 1 << std::endl;
    std::cout << "First name    : " << this->_f_name << std::endl;
    std::cout << "Last name     : " << this->_l_name << std::endl;
    std::cout << "Nickname      : " << this->_nickname << std::endl;
    std::cout << "Phone number  : " << this->_phone_number << std::endl;
    std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
}