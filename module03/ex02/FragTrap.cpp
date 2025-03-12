#include "FragTrap.h"
#include <iostream>
#include "ClapTrap.h"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamege_ = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamege_ = 30;
}

FragTrap::FragTrap(const FragTrap &other) :ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &other) {
		this->name_ = other.name_;
		this->hitPoints_ = other.hitPoints_;
		this->energyPoints_ = other.energyPoints_;
		this->attackDamege_ = other.attackDamege_;
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	if (!this->isAlive()) {
		this->displayAlreadyDead();
		return;
	}
	if (!this->hasEnoughEnergy()) {
		this->displayNotEnoughEnergy();
		return;
	}

	this->energyPoints_ -= ClapTrap::actionEnergyCost;
	std::cout << "FragTrap " << this->name_ << " high fives guys!" << std::endl;
	this->displayStatus();
}

void FragTrap::displayStatus() const {
	std::cout << "FragTrap " << this->name_ 
				<< " has " << this->hitPoints_ << " hit points and "
				<< this->energyPoints_ << " energy points" << std::endl;
}

void FragTrap::displayAlreadyDead() const {
	std::cout << "FragTrap " << this->name_ << " is already dead!" << std::endl;
}

void FragTrap::displayNotEnoughEnergy() const {
	std::cout << "FragTrap " << this->name_ << " has not enough energy!" << std::endl;
}

void FragTrap::displayMaxHitPoints() const {
	std::cout << "FragTrap " << this->name_ << " has maxhit points!" << std::endl;
}

void FragTrap::displayAttack(const std::string &target) const {
	std::cout << "FragTrap " << this->name_ << " attacks " << target 
				<< ", cousing " << this->attackDamege_ << " points of damage!" << std::endl;
}

void FragTrap::displayDead() const {
	std::cout << "FragTrap " << this->name_ << " is dead!" << std::endl;
}


