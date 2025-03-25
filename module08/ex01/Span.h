#ifndef CPP_MODULES_SPAN_H
#define CPP_MODULES_SPAN_H

#include <vector>
#include <set>
#include <stdexcept>

class Span {
public:
	Span();

	Span(unsigned int n);

	Span(const Span &other);

	~Span();

	Span &operator=(Span const &other);

	void addNumber(int num);

	template<class T>
	void addNumber(T begin, T end) {
		if (numbers_.size() + std::distance(begin, end) > N)
			throw std::runtime_error("Span is full");
		for (T it = begin; it != end; ++it)
			addNumber(*it);
	}

	unsigned int shortestSpan() const;

	unsigned int longestSpan() const;

	std::vector<int>::size_type size() const;

private:
	unsigned int N;
	std::set<int> numbers_;
	std::set<unsigned int> span_;
};

#endif
