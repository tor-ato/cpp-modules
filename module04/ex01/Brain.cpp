#include "Brain.h"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (size_t i = 0; i < Brain::maxIdeas; i++) {
		this->ideas_[i] = other.ideas_[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other) {
		for (size_t i = 0; i < Brain::maxIdeas; i++) {
			this->ideas_[i] = other.ideas_[i];
		}
	}
	return *this;
}

void Brain::setIdea(size_t index, const std::string &idea) {
	if (index >= Brain::maxIdeas) {
		throw std::out_of_range("Brain index is out of range");
	}
	this->ideas_[index] = idea;
}

const std::string &Brain::getIdea(size_t index) const {
	if (index >= Brain::maxIdeas) {
		throw std::out_of_range("Brain index is out of range");
	}
	return this->ideas_[index];
}
