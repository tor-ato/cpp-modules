#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain_(new Brain(*other.brain_)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain_;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(size_t index, const std::string &idea) {
	brain_->setIdea(index, idea);
}

const std::string &Cat::getIdea(size_t index) const {
	return brain_->getIdea(index);
}
