#ifndef CPP_MODULES_CLAPTRAP_H
#define CPP_MODULES_CLAPTRAP_H

#include <string>

class ClapTrap {
private:
protected:
	static const unsigned int actionEnergyCost = 1;
	static const unsigned int maxHitPoints;
	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int attackDamege_;

	bool isAlive() const;
	bool hasEnoughEnergy() const;
	unsigned int getRepairAmount(unsigned int amound) const;

	virtual void displayStatus() const;
	virtual void displayAlreadyDead() const;
	virtual void displayDead() const;
	virtual void displayNotEnoughEnergy() const;
	virtual void displayMaxHitPoints() const;
	virtual void displayBeRepaired(unsigned int amount) const;
	virtual void displayTakeDamage(unsigned int amount) const;
	virtual void displayAttack(std::string const &target) const;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &ClapTrap);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &ClapTrap);
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
