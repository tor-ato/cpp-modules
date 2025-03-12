#ifndef CPP_MODULES_FRAGTRAP_H
#define CPP_MODULES_FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {

protected:
	virtual void displayAlreadyDead() const;
	virtual void displayDead() const;
	virtual void displayNotEnoughEnergy() const;
	virtual void displayMaxHitPoints() const;
	virtual void displayAttack(std::string const &target) const;
	virtual void displayStatus() const;

public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	FragTrap &operator=(const FragTrap &other);

	void highFivesGuys(void);
};

#endif
