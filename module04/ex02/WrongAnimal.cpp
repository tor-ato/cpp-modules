#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type_(type) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) : type_(animal.type_) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &animal) {
		this->type_ = animal.type_;
	}
	return *this;
}

const std::string &WrongAnimal::getType() const {
	return this->type_;
}

void WrongAnimal::makeSound() const {
	std::cout << this->type_ << " makes sound" << std::endl;
}
