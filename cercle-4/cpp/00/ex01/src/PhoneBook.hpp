#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string.h>

class PhoneBook{
    public:
        //Name of class for constructor
        PhoneBook(void);
        //Tilt before class name for destructor
        ~PhoneBook(void);
        void start(void);
    private:
        int _nb_contacts;
        int _contact_index;
        Contact _contacts[8];
        void _add(void);
        void _search(void);
        // void search(void);
};

#endif