#include "Zombie.h"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(const std::string &name) : name(name) {}

Zombie::~Zombie() {
	std::cout << name << " is dead" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	this->name = name;
}
