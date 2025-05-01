#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 3) {
		std::cout << "Error : Not enough argument" << std::endl;
		return (EXIT_FAILURE);
	}

	try {
		PmergeMe pm(ac, av);
		pm.excutePmergeMe(ac,av);
	} catch(const char *msg) {
		std::cout << "Error: " << msg << std::endl;
		return (EXIT_FAILURE);
	}
	
	 return (EXIT_SUCCESS);
}
