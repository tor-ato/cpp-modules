#include "Zombie.h"
#include <iostream>

Zombie::Zombie(const std::string &name) : name_(name) {
	std::cout << this->name_ << " is born" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name_ << "is dead" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
