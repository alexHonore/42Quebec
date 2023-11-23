#include "Convert.hpp"

Convert::Convert() : _litteral("Convert"){

}
Convert::Convert(const std::string litteral) : _litteral(litteral){
    if (getLitteral().size() == 0){
        throw Convert::InvalidLitteral();
        return;
    }
    if (isChar()){
        this->_litteralType = "char";
        this->_charValue = static_cast<int>(litteral[0]);
        this->_intValue = static_cast<int>(litteral[0]);
        this->_floatValue = static_cast<float>(getInt());
        this->_doubleValue = static_cast<double>(getInt());
    }
    else if (isFloat() && std::stoi(litteral, nullptr, 10)){
        this->_litteralType = "float";
        this->_floatValue = std::stof(litteral, nullptr);
        this->_intValue = static_cast<int>(getFloat());
        this->_doubleValue = static_cast<double>(getFloat());
        this->_charValue = static_cast<char>(getInt());
    }
    else if (isInt()){
        this->_litteralType = "int";
        this->_intValue = std::stoi(litteral, nullptr, 10);
        if (static_cast<int>(litteral[0]) == 45 || this->_intValue < 33 || this->_intValue > 126)
           this->_charValue = 0;
        else
            this->_charValue = static_cast<char>(getInt());
        this->_floatValue = static_cast<float>(getInt());
        this->_doubleValue = static_cast<double>(getInt());
    }
    else if (isDouble()){
        this->_litteralType = "double";
        this->_doubleValue = std::stod(litteral, nullptr);
        this->_floatValue = static_cast<float>(getDouble());
        this->_intValue = static_cast<int>(getDouble());
        this->_charValue = 0;
    }
    else if (isPseudo()){
        this->_litteralType = "pseudo";
        throw std::invalid_argument(litteral);
    }
    else
        throw Convert::InvalidLitteral();
    return ;
}
Convert::Convert(const Convert & src){
    *this = src;
}
Convert & Convert::operator=(const Convert & rhs){
    (void) rhs;
    return *this;
}
Convert::~Convert(){

}
const std::string & Convert::getLitteral(void) const{
    return this->_litteral;
}
const std::string & Convert::getLitteralType(void) const{
    return this->_litteralType;
}
const int & Convert::getInt(void) const{
    return this->_intValue;
}
const double & Convert::getDouble(void) const{
    return this->_doubleValue;
}
const float & Convert::getFloat(void) const{
    return this->_floatValue;
}
const char & Convert::getChar(void) const{
    if (this->_charValue > 32 && this->_charValue < 127)
        return (this->_charValue);
    else
        std::cout << "Non displayable";
    return (this->_charValue);
}
bool Convert::isPseudo() const{
    std::string pseudo[6] = {"+inff", "-inff", "+inf", "-inf", "nan", "nanf"};
    for (int i = 0; i < 6; i++){
        if (getLitteral().compare(pseudo[i]) == 0)
          return (true);
    }
    return (false);
}
bool Convert::isInt() const{
    std::string intChars = "-0123456789";
    if (getLitteral().find_last_not_of(intChars) == std::string::npos)
        return (true);
    return (false);
}
bool Convert::isDouble() const{
    std::string doubleChars = "-0123456789.";
    if (getLitteral().find_last_not_of(doubleChars) == std::string::npos){
        if (findMultiple('.') == false)
            return (true);
    }
    return (false);
}
bool Convert::isFloat() const{
    std::string floatChars = "-0123456789.f";
    if (getLitteral().find_last_not_of(floatChars) == std::string::npos){
        if (getLitteral().back() == 'f' && findMultiple('f') == false
            && findMultiple('.') == false && findMultiple('-') == false)
                return (true);
    }
    return (false);
}
bool Convert::isChar() const{
    if (getLitteral().size() == 1){
        const char *str = getLitteral().c_str();
        if (str[0] > 31 && str[0] < 127){
            if (str[0] >= 48 && str[0] <= 57)
                return (false);
            else
                return (true);
        }
    }
    return (false);
}
bool Convert::findMultiple(const char c) const{
    std::size_t pos = getLitteral().find(c, 0);
    if (pos != std::string::npos){
        pos = getLitteral().find(c, pos + 1);
        if (pos != std::string::npos)
            return (true);
    }
    return (false);
}

std::ostream & operator<<(std::ostream & out, Convert const & rhs) {

    out << "char:\t" << rhs.getChar() << std::endl <<
    "int:\t" << rhs.getInt() << std::endl <<
    "float:\t" << std::setprecision(1) << std::fixed << rhs.getFloat() << "f" << std::endl <<
    "double:\t" << rhs.getDouble();
    return (out);
}