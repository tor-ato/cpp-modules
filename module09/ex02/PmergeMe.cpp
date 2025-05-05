#include "PmergeMe.hpp"

int g_counterVct = 0;
int g_counterDeq = 0;

PmergeMe::PmergeMe() : vct_(), deq_() {}

PmergeMe::PmergeMe(int ac, char **av) : vct_(), deq_() {
	validate(ac, av);
}

PmergeMe::PmergeMe(const PmergeMe &src) : vct_(src.vct_), deq_(src.deq_) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (&src != this) {
		vct_ = src.vct_;
		deq_ = src.deq_;
	}
	return *this;
}

void PmergeMe::validate(int ac, char **av) {
	int num; 
	t_pairVct tmp;
	
	for (int i = 1; i < ac; i++) {
		std::istringstream iss(av[i]);

		iss >> num;
		if (iss.fail() || !iss.eof() || num < 1)
			throw("Invalid element");
		tmp.num = num;
		before_.push_back(tmp);
	}
}

void PmergeMe::printContainer(const std::string &title, const std::vector<t_pairVct> &container) {
	std::cout << title;
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << " " << container[i].num;
	std::cout << std::endl;
}

void PmergeMe::printTime(int size, const std::string &container, std::clock_t sortTime, int count) {
	double time = static_cast<double>(sortTime) * 1000000 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << size <<  " elements"
			  << " with std::" << container << ": "
			  <<  time <<  " µs"
			  << "    Comparison Count:" << count
			  << std::endl;
	(void)count;
}

void PmergeMe::initVct(int ac, char **av) {
	int num;
	t_pairVct tmpVct;

	for (int i = 1; i < ac; i++) {
		std::istringstream iss(av[i]);
		iss >> num;
		tmpVct.num = num;
		vct_.push_back(tmpVct);
	}
}

void PmergeMe::createPairs(std::vector<t_pairVct> &pairs, std::vector<t_pairVct> vct) {
	t_pairVct tmp;
	for (size_t i = 0; i < vct.size(); i +=2) {
		g_counterVct++;
		if (vct[i].num > vct[i + 1].num) {
			vct[i].pairs.push_back(vct[i + 1]);
			pairs.push_back(vct[i]);
		} else {
			vct[i + 1].pairs.push_back(vct[i]);
			pairs.push_back(vct[i + 1]);
		}
	}
}

void PmergeMe::insertFirstElement(std::vector<t_pairVct> &mainChain) {
	t_pairVct first = mainChain[0].pairs.back();
	mainChain[0].pairs.pop_back();
	mainChain.insert(mainChain.begin(), first);
}

std::vector<int> PmergeMe::getJacobStahlNumVct(int size) {
	std::vector<int> jacovStahl;
	int total = 1;
	if (size > 0)
		jacovStahl.push_back(0);
	if (size >= 1)
		jacovStahl.push_back(1);
	for (int i = 2; total * 2 < size; ++i) {
		int num = jacovStahl[i - 1] + 2 * jacovStahl[i - 2];
		jacovStahl.push_back(num);
		total += num;
	}
	return jacovStahl;
}

std::vector<int> PmergeMe::getIndexVct(int size) {
 	std::vector<int> js;
	std::vector<int> js2;
	std::vector<int> idx;

	js = getJacobStahlNumVct(size);

	for (size_t i = 0; i < js.size(); ++i)
		js2.push_back(js[i] * 2);

	int total = 1;
	for (size_t i = 1; i < js2.size(); ++i) {
		int num = js2[i];
		if (total + num > size + 1)
			num = size + 1 - total;
		for ( ; num > 0; num--)
			idx.push_back(total + num);
		total += js2[i];
	}
	return idx;
}

void PmergeMe::createInsertElements(std::vector<t_pairVct> &insertFirstElement, std::vector<t_pairVct> &mainChain, t_pairVct &lastOne) {
	int size = mainChain.size() - 2 + (lastOne.num == -1 ? 0 : 1);
	std::vector<int> index = getIndexVct(size);
	t_pairVct tmp;

	for (size_t i = 0; i < index.size(); ++i) {
		if (static_cast<size_t>(index[i]) < mainChain.size()) {
			tmp = mainChain[index[i]];
			mainChain[index[i]].pairs.pop_back();
		} else {
			tmp.num = DUMMY;
			tmp.pairs.push_back(lastOne);
		}
		insertFirstElement.push_back(tmp);
		tmp.pairs.clear();
	}
}

bool PmergeMe::compVctElements(const t_pairVct &first, const t_pairVct &second) {
	g_counterVct++;
	return (first.num < second.num);
}

void PmergeMe::binarySearchInsert(std::vector<t_pairVct> &mainChain, t_pairVct &insertElement, int large) {
	std::vector<t_pairVct>:: iterator untillMainChainPair;
	for (untillMainChainPair = mainChain.begin(); untillMainChainPair->num != large; ++untillMainChainPair) {}
	mainChain.insert(std::lower_bound(mainChain.begin(), untillMainChainPair, insertElement, compVctElements), insertElement);
}

void PmergeMe::insertBasedOnJacobsthal(const std::vector<t_pairVct> &insetElements, std::vector<t_pairVct> &mainChain) {
	t_pairVct insertElement;
	int large;

	for (size_t i = 0; i < insetElements.size(); ++i) {
		insertElement = insetElements[i].pairs.back();
		large = insetElements[i].num;
		if (large != -1)
			binarySearchInsert(mainChain, insertElement, large);
		else
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), insertElement, compVctElements), insertElement);
	}
}

std::vector<t_pairVct> PmergeMe::mergeInsertSortVct(std::vector<t_pairVct> &vct) {
	if (vct.size() < 2)
		return (vct);

	int oddNumber = vct.size() % 2;
	t_pairVct lastOne;
	lastOne.num = -1;
	if (oddNumber) {
		lastOne = vct.back();
		vct.pop_back();
	}

	std::vector<t_pairVct> pairs;
	createPairs(pairs, vct);

	std::vector<t_pairVct> mainChain = mergeInsertSortVct(pairs);

	insertFirstElement(mainChain);

	std::vector<t_pairVct> insertElements;
	createInsertElements(insertElements, mainChain, lastOne);

	if (!insertElements.empty())
		insertBasedOnJacobsthal(insertElements, mainChain);

	return mainChain;
}

void PmergeMe::excutePmergeMe(int ac, char **av) {
	std::clock_t startVct = std::clock();
	initVct(ac, av);
	vct_ = mergeInsertSortVct(vct_);
	std::clock_t timeVct = std::clock() - startVct;

	// std::clock_t startDeq = std::clock();
	// initDeq(ac, av);
	// deq_ = mergeInsertSortDeq(deq_);
	// std::clock_t timeDeq = std::clock() - startDeq;

	printContainer("Before: ", before_);
	printContainer("After: ", vct_);

	printTime(vct_.size(), "vector", timeVct, g_counterVct);
	// printTime(deq_.size(), "deque", timeDeq, g_counterDeq);
}
