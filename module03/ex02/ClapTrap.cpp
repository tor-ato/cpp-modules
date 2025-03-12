#include "ClapTrap.h"
#include <iostream>
#include <limits>

const unsigned int ClapTrap::maxHitPoints = std::numeric_limits<unsigned int>::max();

/* public */

ClapTrap::ClapTrap() : name_("defalut"), hitPoints_(10), energyPoints_(10), attackDamege_(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name_(name), hitPoints_(10), energyPoints_(10), attackDamege_(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	std::cout << "CrapTrap copy assignment operator called" << std::endl;
	if (this == &clapTrap) {
		this->name_ = clapTrap.name_;
		this->hitPoints_ = clapTrap.hitPoints_;
		this->energyPoints_ = clapTrap.energyPoints_;
		this->attackDamege_ = clapTrap.attackDamege_;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (!this->isAlive()) {
		this->displayAlreadyDead();
		return;
	}
	if (!this->hasEnoughEnergy()) {
		this->displayNotEnoughEnergy();
		return;
	}

	this->energyPoints_ -= ClapTrap::actionEnergyCost;

	this->displayAttack(target);
	this->displayStatus();
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->isAlive()) {
		this->displayAlreadyDead();
		return;
	}

	this->hitPoints_ = (this->hitPoints_ > amount) ? this->hitPoints_ - amount : 0;

	displayTakeDamage(amount);

	if (this->hitPoints_ == 0)
		this->displayDead();
	else
		this->displayStatus();
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->isAlive()) {
		this->displayAlreadyDead();
		return;
	}
	if (!this->hasEnoughEnergy()) {
		this->displayNotEnoughEnergy();
		return;
	}
	if (this->hitPoints_ == ClapTrap::maxHitPoints) {
		this->displayMaxHitPoints();
		return;
	}

	unsigned int reparAmaount = getRepairAmount(amount);
	this->energyPoints_ -= ClapTrap::actionEnergyCost;
	this->hitPoints_ += reparAmaount;

	this->displayBeRepaired(reparAmaount);
	this->displayStatus();
}

/* private */

bool ClapTrap::isAlive() const {
	return this->hitPoints_ > 0;
}

bool ClapTrap::hasEnoughEnergy() const {
	return this->energyPoints_ >= ClapTrap::actionEnergyCost;
}

unsigned int ClapTrap::getRepairAmount(unsigned int amount) const {
	if (amount > ClapTrap::maxHitPoints || 
	 	this->hitPoints_ > ClapTrap::maxHitPoints - amount) {
		return ClapTrap::maxHitPoints - this->hitPoints_;
	} else {
		return amount;
	}
}

/* protected */

void ClapTrap::displayStatus() const {
	std::cout << "ClapTrap " << this->name_ 
							<< " has " << this->hitPoints_ << " hit points and "
							<< this->energyPoints_ << " energy points" << std::endl;
}

void ClapTrap::displayAlreadyDead() const {
	std::cout << "ClapTrap " << this->name_ << " is already dead!" << std::endl;
}

void ClapTrap::displayNotEnoughEnergy() const {
	std::cout << "ClapTrap " << this->name_ << " has not enough energy!" << std::endl;
}

void ClapTrap::displayMaxHitPoints() const {
	std::cout << "ClapTrap " << this->name_ << " has max hit points!" << std::endl;
}

void ClapTrap::displayBeRepaired(unsigned int amount) const {
	std::cout << "ClapTrap " << this->name_
				<< " is repaired for " << amount << " points!" << std::endl;
}

void ClapTrap::displayTakeDamage(unsigned int amount) const {
	std::cout << "ClapTrap " << this->name_
				<< " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::displayAttack(const std::string &target) const {
	std::cout << "ClapTrap " << this->name_ << " attacks " << target
				<< ", caousing " << this->attackDamege_ << " points of damage!" << std::endl;
}

void ClapTrap::displayDead() const {
	std::cout << "ClapTrap " << this->name_ << " is dead!" << std::endl;
}
