#pragma once

#include <vector>
#include <deque>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <climits>
#include <iomanip>

class PmergeMe {
public:
	PmergeMe();

	PmergeMe(const PmergeMe &other);

	PmergeMe &operator=(const PmergeMe &other);

	~PmergeMe();

	bool parseArgs(int argc, char **argv);

	void run();

private:
	std::vector<int> vec_;
	std::deque<int> deq_;

	static int s2i(const std::string &str) throw(std::invalid_argument);

	static std::vector<int> getJacob(size_t size);

	static std::vector<int> getInsertPos(size_t size);

	void sortVector();

	void sortDeque();

	template<typename T>
	static void printSeq(const T &seq, const std::string &label) {
		std::cout << label << ": ";
		for (size_t i = 0; i < seq.size(); i++) {
			if (i > 0)
				std::cout << " ";
			std::cout << seq[i];
		}
		std::cout << std::endl;
	}
};
