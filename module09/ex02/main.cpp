#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (!PmergeMe::parseArgs(argc, argv)) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	PmergeMe::run();
}
