#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec_(other.vec_), deq_(other.deq_) {}

PmergeMe::~PmergeMe() {}

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
		if (num < 0)
			return false;
		vec_.push_back(num);
		deq_.push_back(num);
	}

	return true;
}

std::vector<int> PmergeMe::getJacob(size_t size) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < static_cast<int>(size)) {
		int lastNum = jacobsthal.back();
		int secondLastNum = jacobsthal[jacobsthal.size() - 2];

		// jn = j(n-1) + 2*j(n-2)
		int next = lastNum + 2 * secondLastNum;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

std::vector <int> PmergeMe::getInsertPos(size_t size){
	std::vector<int> jacobSeq = getJacob(size);
	std::vector<int> order;
	std::vector<bool> used(size, false);
	used[0] = true;

	for (size_t i = 1; i < jacobSeq.size() && jacobSeq[i]; i++) {
		if (!used[jacobSeq[i]]) {
			order.push_back(jacobSeq[i]);
			used[jacobSeq[i]] = true;
		}

		for (int j = jacobSeq[i] - 1; j > jacobSeq[i-1]; j--) {
			if (j < (int)size && !used[j]) {
				order.push_back(j);
				used[j] = true;
			}
		}
	}

	for (size_t i = 1; i < size; i++) {
		if (!used[i]) {
			order.push_back(i);
		}
	}

	return order;
}


void PmergeMe::sortVector() {
	if (vec_.size() < 2)
		return;

	bool hasStraaggler = false;
	int straggler = 0;

	if (vec_.size() %2 != 0) {
		hasStraaggler = true;
		straggler = vec_.back();
		vec_.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vec_.size(); i += 2) {
		int first = vec_[i];
		int second = vec_[i + 1];
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}

	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}

	if (mainChain.size() > 1) {
		vec_ = mainChain;
		sortVector();
		mainChain = vec_;
	}

	std::vector<int> result = mainChain;

	std::vector<int> pendChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		pendChain.push_back(pairs[i].second);
	}

	if (!pendChain.empty()) {
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[0]);
		result.insert(pos, pendChain[0]);
	}

	if (pendChain.size() > 1) {
		std::vector<int> insertionOrder = getInsertPos(pendChain.size());
		for (size_t i = 0; i < insertionOrder.size(); i++) {
			int idx = insertionOrder[i];
			if (idx > 0 && idx < (int)pendChain.size()){
				std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[idx]);
				result.insert(pos, pendChain[idx]);
			}
		}
	}

	if (hasStraaggler) {
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}

	vec_ = result;
}

void PmergeMe::sortDeque() {
	if (deq_.size() < 2)
		return;

	bool hasStraaggler = false;
	int straggler = 0;

	if (deq_.size() %2 != 0) {
		hasStraaggler = true;
		straggler = deq_.back();
		deq_.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < deq_.size(); i += 2) {
		int first = deq_[i];
		int second = deq_[i + 1];
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}

	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}

	if (mainChain.size() > 1) {
		deq_ = mainChain;
		sortDeque();
		mainChain = deq_;
	}

	std::deque<int> result = mainChain;

	std::deque<int> pendChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		pendChain.push_back(pairs[i].second);
	}

	if (!pendChain.empty()) {
		std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[0]);
		result.insert(pos, pendChain[0]);
	}

	if (pendChain.size() > 1) {
		std::vector<int> insertionOrder = getInsertPos(pendChain.size());
		for (size_t i = 0; i < insertionOrder.size(); i++) {
			int idx = insertionOrder[i];
			if (idx > 0 && idx < (int)pendChain.size()){
				std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[idx]);
				result.insert(pos, pendChain[idx]);
			}
		}
	}

	if (hasStraaggler) {
		std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}

	deq_ = result;
}


void PmergeMe::run() {
	std::vector<int> original = vec_;

	clock_t vecStart = clock();
	sortVector();
	clock_t vecEnd = clock();
	double vecTime = static_cast<double> (vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;

	clock_t deqStart = clock();
	sortDeque();
	clock_t deqEnd = clock();
	double deqTime = static_cast<double> (deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000;

	
	// for (size_t i = 1; i < vec_.size(); i++) {
	//        if (vec_[i] < vec_[i - 1])
	//        {
	//            std::cerr << "Error: std::vector is no sorted" << std::endl;
	//            return;
	//        }
	//    }
	//
	//
	// for (size_t i = 1; i < deq_.size(); i++) {
	//        if (deq_[i] < deq_[i - 1])
	//        {
	//            std::cerr << "Error: std::deque is no sorted" << std::endl;
	//            return;
	//        }
	//    }
	//

	printSeq(original, "Befor");
	printSeq(vec_, "After");

    std::cout << "Time to process a range of " << vec_.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << vec_.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << deqTime << " us" << std::endl;
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
