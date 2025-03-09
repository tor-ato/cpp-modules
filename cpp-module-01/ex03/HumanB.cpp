#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

void HumanB::attack() const {
	if (this->weapon == NULL)
		std::cout << name << " dose not have a weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &w) {
	this->weapon = &w;
}
