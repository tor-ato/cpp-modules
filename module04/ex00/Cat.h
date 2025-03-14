#ifndef CPP_MODULES_CAT_H
#define CPP_MODULES_CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
	Cat();

	Cat(const Cat &other);

	~Cat();

	Cat &operator=(const Cat &other);

	void makeSound() const;
};

#endif
