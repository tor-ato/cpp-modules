#ifndef CPP_MODULES_HUMANB_H
#define CPP_MODULES_HUMANB_H

#include <string>
#include "Weapon.h"

class HumanB {
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(const std::string &name);
	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif
