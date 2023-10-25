
#include <iostream>
// using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0;
	int ii = 1;

	if (argc > 1)
	{
		while (argv[ii])
		{
			i = 0;
			while (argv[ii][i])
			{
				std::cout << (char)std::toupper(argv[ii][i]);
				i++;
			}
			ii++;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << "\n";
	return 0;
}
