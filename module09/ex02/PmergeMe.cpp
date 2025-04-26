#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec_(other.vec_), deq_(other.deq_) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        vec_ = other.vec_;
        deq_ = other.deq_;
    }
    return *this;
}

bool PmergeMe::parseArgs(int argc, char **argv) {
	if (argc < 2)
		return false;

	for (int i = 1; i < argc; i++) {
		int num;
		try {
			num = s2i(argv[i]);
		} catch (std::exception &e) {
			return false;
		}
		vec_.push_back(num);
		deq_.push_back(num);
	}

	return true;
}

int PmergeMe::s2i(const std::string &str) throw(std::invalid_argument) {
	std::istringstream iss(str);
	int i;
	iss >> i;
	if (iss.fail())
		throw std::invalid_argument("invalid string to int conversion: " + str);
	iss.get();    // should read nothing
	if (!iss.eof())
		throw std::invalid_argument("invalid string to int conversion: " + str);
	return i;
}
