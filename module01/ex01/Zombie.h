#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <string>

class Zombie {
private:
	std::string name;

public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();

	void announce();
	void setName(const std::string &name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
