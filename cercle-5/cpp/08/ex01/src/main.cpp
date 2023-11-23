#include "Span.hpp"

int main() {
    std::cout << std::endl << "\033[1;31mSpan SP, SIZE 5\033[1;0m" << std::endl;
    std::cout << std::endl << "\033[1;32mSHORTEST SPAN \033[1;0m" << std::endl;
	Span sp = Span(5);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[1;32mLONGEST SPAN\033[1;0m" << std::endl;
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[1;32mINSERT 7 NUMBERS\033[1;0m" << std::endl;
	try
	{
		for (int i = 0; i < 7; i++)
		{
			sp.addNumberRange(i);
		}
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "shortest span is: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span is: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[1;32mINSERT 12K NUMBERS\033[1;0m" << std::endl;
	try
	{
		sp.addNumberRange(12000);
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << std::endl << "\033[1;31mSpan ALOT WITH 15K NUMBERS & COPY IT\033[1;0m" << std::endl;
	Span alot(15000);
	Span bigsp(alot);
	try
	{
		bigsp.addNumberRange(15000);
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Shortest span is: " << bigsp.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << bigsp.longestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}