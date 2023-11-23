#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

#include <iomanip>
#include <cerrno>
#include <string.h>
#include <locale.h>

class Convert {
    private:
            const std::string   _litteral;
            std::string         _litteralType;
            int           _intValue;
            double        _doubleValue;
            float         _floatValue;
            char          _charValue;
    protected:
    public:
        Convert();
        Convert(const std::string litteral);
        Convert(const Convert & src);
        Convert & operator=(const Convert & rhs);
        ~Convert();

        const std::string & getLitteral(void) const;
        const std::string & getLitteralType(void) const;
        const int & getInt(void) const;
        const double & getDouble(void) const;
        const float & getFloat(void) const;
        const char & getChar(void) const;
        
        bool isPseudo() const;
        bool isInt() const;
        bool isDouble() const;
        bool isFloat() const;
        bool isChar() const;

        bool findMultiple(const char c) const;

        class InvalidLitteral : public std::exception {
            public:
                virtual const char *what() const throw(){
                    return "Invalid litteral.";
                }
        };
};

std::ostream& operator<<(std::ostream& out, const Convert& rhs);

#endif