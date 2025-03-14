#ifndef CPP_MODULES_DOG_H
#define CPP_MODULES_DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
	Dog();

	Dog(const Dog &other);

	~Dog();

	Dog &operator=(const Dog &other);

	void makeSound() const;
};

#endif
