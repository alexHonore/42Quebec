#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try{
        BitcoinExchange exchange;
        exchange.parseFile(argv[1]);
        exchange.ShowRatesExchange(argv[1]);
    }catch (const char *e)
    {
        std::cerr << e << std::endl;
        return(1);
    }
    return 0;
}