#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if(argc < 2){
		std::cout << "Error: bad arguments" << std::endl;
		return 1;
	}
	else{
		std::vector<int> vectContainer;
		std::deque<int> deqContainer;
		for (int i = 1; i <= argc; i++){
			if (argv[i]){
				for(int j = 0; argv[i][j]; j++){
					if (!std::isdigit(argv[i][j])){
						std::cout << "Error: Invalid argument: " << argv[i] << std::endl;
						return 1;
					}
				}
				vectContainer.push_back(std::atoi(argv[i]));
				deqContainer.push_back(std::atoi(argv[i]));
			}
		}
		sortvector(vectContainer, argc - 1);
		sortdeque(deqContainer, argc - 1);
	}
}
