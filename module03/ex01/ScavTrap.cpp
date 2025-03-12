#include "ScavTrap.h"
#include <iostream>
#include "ClapTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamege_ = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamege_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) :ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &other) {
		this->name_ = other.name_;
		this->hitPoints_ = other.hitPoints_;
		this->energyPoints_ = other.energyPoints_;
		this->attackDamege_ = other.attackDamege_;
	}
	return *this;
}

void ScavTrap::displayStatus() const {
	std::cout << "ScavTrap " << this->name_ 
				<< " has " << this->hitPoints_ << " hit points and "
				<< this->energyPoints_ << " energy points" << std::endl;
}

void ScavTrap::displayAlreadyDead() const {
	std::cout << "ScavTrap " << this->name_ << " is already dead!" << std::endl;
}

void ScavTrap::displayNotEnoughEnergy() const {
	std::cout << "ScavTrap " << this->name_ << " has not enough energy!" << std::endl;
}

void ScavTrap::displayMaxHitPoints() const {
	std::cout << "ScavTrap " << this->name_ << " has maxhit points!" << std::endl;
}

void ScavTrap::displayAttack(const std::string &target) const {
	std::cout << "ScavTrap " << this->name_ << " attacks " << target 
				<< ", cousing " << this->attackDamege_ << " points of damage!" << std::endl;
}

void ScavTrap::displayDead() const {
	std::cout << "ScavTrap " << this->name_ << " is dead!" << std::endl;
}

void ScavTrap::guardGate() {
	if (!this->isAlive()) {
		this->displayAlreadyDead();
		return;
	}
	if (!this->hasEnoughEnergy()) {
		this->displayNotEnoughEnergy();
		return;
	}

	this->energyPoints_ -= ClapTrap::actionEnergyCost;
	std::cout << "ScavTrap " << this->name_
		<< " is now int Gate keeper mode" << std::endl;
	this->displayStatus();
}
