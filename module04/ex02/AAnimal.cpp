#include "AAnimal.h"
#include <iostream>

AAnimal::AAnimal() : type_("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : type_(type) {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = animal;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &animal) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &animal) {
		this->type_ = animal.type_;
	}
	return *this;
}

const std::string &AAnimal::getType() const {
	return this->type_;
}
