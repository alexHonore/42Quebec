#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string.h>

class Harl{
    public:
        //Name of class for constructor
        Harl();
        //Tilt before class name for destructor
        ~Harl(void);
        void complain( std::string level );
    private:
        void _debug(void);
        void _info( void );
        void _warning( void );
        void _error( void );
};


#endif