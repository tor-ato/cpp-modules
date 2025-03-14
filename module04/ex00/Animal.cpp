#include "Animal.h"
#include <iostream>

Animal::Animal() : type_("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type_(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : type_(animal.type_) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &animal) {
		this->type_ = animal.type_;
	}
	return *this;
}

const std::string &Animal::getType() const {
	return this->type_;
}

void Animal::makeSound() const {
	std::cout << this->type_ << " makes sound" << std::endl;
}
