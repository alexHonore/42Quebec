#ifndef BITCOINEXCHANGE_CPP
# define BITCOINEXCHANGE_CPP

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iomanip>

class BitcoinExchange {
    private:
        std::map<std::string, float> dataHashMap;
    protected:
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & src);
        ~BitcoinExchange();
        BitcoinExchange & operator=(const BitcoinExchange & rhs);

        std::string trimSpaces(const std::string &str);
        bool isValidDateFormat(const std::string &date);
        bool isValidValue(const std::string &value);
        void fillData(std::ifstream& data);
        float getRateValueFromData(const std::string &date);

        void parseFile(const std::string &file_name);
        void ShowRatesExchange(const std::string &file_name);
};

#endif