#pragma once

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <algorithm>
# include <vector>
# include <deque>

# define DUMMY -1

typedef struct s_pairVct {
	int num;
	std::vector<s_pairVct> pairs;
}	t_pairVct;

typedef struct s_pairDeq {
	int num;
	std::deque<s_pairDeq> pairs;
}	t_pairDeq;

class PmergeMe {
public:
	PmergeMe();

	PmergeMe(int ac, char **avA);
	
	PmergeMe(const PmergeMe &src);

	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &src);

	void excutePmergeMe(int ac, char **av);

	static bool compVctElements(const t_pairVct &first, const t_pairVct &second);

	static bool compDeqElements(const t_pairDeq &first, const t_pairDeq &second);

private:
	std::vector<t_pairVct> before_;
	std::vector<t_pairVct> vct_;
	std::deque<t_pairDeq> deq_;

	void validate(int ac, char **av);

	void printContainer(const std::string &title, const std::vector<t_pairVct> &container);

	void printTime(int size, const std::string &container, std::clock_t sortTime, int count);

	/* sort (vector) */
	void initVct(int ac, char **av);

	std::vector<t_pairVct> mergeInsertSortVct(std::vector<t_pairVct> &vct);

	void createPairs(std::vector<t_pairVct> &pairs, std::vector<t_pairVct> vct);

	void createInsertElements(std::vector<t_pairVct> &insertElements, std::vector<t_pairVct> &mainChain, t_pairVct &lastOne);

	void insertBasedOnJacobsthal(const std::vector<t_pairVct> &jsElements, std::vector<t_pairVct> &mainChain);

	void binarySearchInsert(std::vector<t_pairVct> &mainChain, t_pairVct &insertElement, int large);

	std::vector<int> getIndexVct(int size);

	std::vector<int> getJacobStahlNumVct(int size);

	void insertFirstElement(std::vector<t_pairVct> &mainChain);

	/* sort (deque) */
	void initDeq(int ac, char **av);

	std::deque<t_pairDeq> mergeInsertSortDeq(std::deque<t_pairDeq> &deq);

	void createPairs(std::deque<t_pairDeq> &pairs, std::deque<t_pairDeq> deq);

	void createInsertElements(std::deque<t_pairDeq> &insertElements, std::deque<t_pairDeq> &mainChain, t_pairDeq &lastOne);

	void insertBasedOnJacobsthal(const std::deque<t_pairDeq> &jsElements, std::deque<t_pairDeq> &mainChain);

	void binarySearchInsert(std::deque<t_pairDeq> &mainChain, t_pairDeq &insertElement, int large);

	std::deque<int> getIndexDeq(int size);

	std::deque<int> getJacobStahlNumDeq(int size);

	void insertFirstElement(std::deque<t_pairDeq> &mainChain);
};
