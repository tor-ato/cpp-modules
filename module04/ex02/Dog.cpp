#include "Dog.h"
#include <iostream>

Dog::Dog() : AAnimal("Dog"), brain_(new Brain()) {
	std::cerr << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), brain_(new Brain(*other.brain_)) {
	std::cerr << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cerr << "Dog destructor called" << std::endl;
	delete brain_;
}

Dog &Dog::operator=(const Dog &other) {
	std::cerr << "Dog assignation operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(size_t index, const std::string &idea) {
	brain_->setIdea(index, idea);
}

const std::string &Dog::getIdea(size_t index) const {
	return brain_->getIdea(index);
}
