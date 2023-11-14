#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
# include <string.h>

class Contact{
    public:
        Contact(void);
        ~Contact(void);
        void add_contact(void);
        void search_contact(int id);
        void _print_contact(int index);
    private:
        std::string _ask_data(std::string msg);
        void _print_clean(std::string data);
        std::string _f_name;
        std::string _l_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
};

#endif