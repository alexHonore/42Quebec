#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){

}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & src){
    *this = src;
}
BitcoinExchange::~BitcoinExchange(){

}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs){
    if (this != &rhs)
        this->dataHashMap = rhs.dataHashMap;
    return *this;
}

float ft_stof(const std::string& str){ 
    float nb;
    std::stringstream ss(str);                                                                                     
    ss >> nb;
    return nb;
}

std::string BitcoinExchange::trimSpaces(const std::string &str){
    std::string trimed_str;
    std::istringstream iss(str);
    std::getline(iss >> std::ws, trimed_str);

    return trimed_str;
}
bool isPastDate(float year, float month, float day){
    if (year && month && day)
        return true;
    else
        return false;
}
bool BitcoinExchange::isValidDateFormat(const std::string &date){
    if(date.empty()){
        std::cerr << "Error:empty!" << std::endl;
        return false;
    }
    if (date.length() != 10 || date[4] != '-' || date[7] != '-'){
        std::cerr << "Error: not a valid date: " << date << std::endl;                                                     
        return false;
    }
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue; 
        if (!std::isdigit(date[i])){
            std::cerr << "Error: not a valid date: " << date << std::endl;
            return false;
        }
    }

    float year = ft_stof(date.substr(0, 4));
    float month = ft_stof(date.substr(5, 2));
    float day = ft_stof(date.substr(8, 2));

	if(year < 2009 || year > 2024){
         std::cerr << "Error: not a valid year: " << year << std::endl;
		return false;
    }
    if (month < 1 || month > 12){
         std::cerr << "Error: not a valid month: " << month << std::endl;
        return false;
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31)){
    std::cerr << "Error: not a valid day: " << day << std::endl;
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)){
    std::cerr << "Error: not a valid day: " << day << std::endl;
        return false;
    }
    else if (month == 2) {
        bool isLeapYear = static_cast<int>(year) % 4 == 0;
        if (isLeapYear && (day < 1 || day > 29)) {
            std::cerr << "Error: not a valid day: " << day << " for February in a leap year" << std::endl;
            return false;
        } else if (!isLeapYear && (day < 1 || day > 28)) {
            std::cerr << "Error: not a valid day: " << day << std::endl;
            return false;
        }
    }
    return isPastDate(year, month, day); // looks if the valid date is not in the future
}
bool BitcoinExchange::isValidValue(const std::string &value){
    size_t i = 0;
    int flag = 0;
    bool isvalid = false;

    if (value.empty()) {
        std::cerr << "Error: empty value!" << std::endl;
        return false;
    }
    while(i < value.size()){
        if (std::isdigit(value[i])) 
            isvalid = true;
        else if (i > 0 && value[i] == '.' && flag == 0) 
            flag++;
        else {
            std::cerr << "Error: not a valid number: " << value << std::endl;                                                  
            return false;
        }
        i++;
    }
    if (!isvalid || (value.find('.') != std::string::npos && !std::isdigit(value.back()))) {
        std::cerr << "Error: not a valid number: " << value << std::endl;
        return false;
    }
    if (ft_stof(value) < 0) {
        std::cerr << "Error: not a positive number: " << value << std::endl;
        return false;
    } else if (ft_stof(value) > 1000) {
        std::cerr << "Error: too large a number: " << value << std::endl;
        return false;
    }
    return true;
}
void BitcoinExchange::fillData(std::ifstream& data){
    std::string line;
    size_t delimiter;

    std::getline(data, line);
    while (std::getline(data, line))                                                      
    {
        delimiter = line.find(',');
        std::string rate = line.substr(delimiter + 1);
        this->dataHashMap[line.substr(0, delimiter)] = ft_stof(rate);
    }
    data.close();
}
float BitcoinExchange::getRateValueFromData(const std::string &date){
    if (this->dataHashMap.count(date) > 0)
        return this->dataHashMap.at(date);
    // return getRateValueFromData(--this->dataHashMap.lower_bound(date));
    return (--this->dataHashMap.lower_bound(date))->second;
}
void BitcoinExchange::parseFile(const std::string &file_name){
    std::ifstream file(file_name);
	std::ifstream data_file("data.csv", std::ifstream::in);

    if (!file.is_open())
        throw ("ERROR: Unable to open file!");
    if (file.peek() == EOF)
        throw ("FILE IS EMPTY!");

	if (!data_file.is_open())
	    throw ("ERROR: Unable to open data_file!");
    if (data_file.peek() == EOF)
        throw ("FILE IS EMPTY!");

	this->fillData(data_file);
    file.close();
    data_file.close();
}
void BitcoinExchange::ShowRatesExchange(const std::string &file_name){
    std::string line;
    std::getline(file_name, line);
    std::ifstream data_file("data.csv", std::ifstream::in);

    if (line != "date | value")
        throw("INVALID FILE FORMAT!");
    while (std::getline(file_name, line))
    {
        size_t delimiter = line.find('|');
        if (delimiter == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trimSpaces(line.substr(0, delimiter));
        std::string value = trimSpaces(line.substr(delimiter + 1));
        if (!this->isValidDateFormat(date))
            continue;
        if (!this->isValidValue(value))
            continue;
        float rate = ft_stof(value);
        std::cout << date << " => " << value << " = " << std::setprecision(2) << rate * this->getRateValueFromData(date) << std::endl; 
    }
    data_file.close();
}