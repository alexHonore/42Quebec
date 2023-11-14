
#include <iostream>
// using namespace std;

int main(int argc, char const **argv)
{
	int i = 0;
	int j = 1;

	if (argc > 1)
	{
		while (argv[j])
		{
			i = 0;
			while (argv[j][i])
			{
				std::cout << (char)std::toupper(argv[j][i]);
				i++;
			}
			j++;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << "\n";
	return 0;
}
