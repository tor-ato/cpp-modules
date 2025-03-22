#include "Span.h"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &other) : N(other.N), numbers_(other.numbers_), span_(other.span_) {}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		N = other.N;
		numbers_ = other.numbers_;
		span_ = other.span_;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (numbers_.size() >= N)
		throw std::runtime_error("Span is full");
	if (!numbers_.empty()) {
		for (std::multiset<int>::iterator it = numbers_.begin(); it != numbers_.end(); ++it) {
			long diff = static_cast<long>(num) - static_cast<long>(*it);
			unsigned int absDiff = static_cast<unsigned int>(diff < 0 ? -diff : diff);
			span_.insert(absDiff);
		}
	}
	numbers_.insert(num);
}

unsigned int Span::shortestSpan() const {
	if (span_.empty())
		throw std::runtime_error("No span to calculate");
	return *span_.begin();
}

unsigned int Span::longestSpan() const {
	if (span_.empty())
		throw std::runtime_error("No span to calculate");
	return *numbers_.rbegin() - *numbers_.begin();
}
