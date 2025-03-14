#ifndef CPP_MODULES_DOG_H
#define CPP_MODULES_DOG_H

#include "AAnimal.h"
#include "Brain.h"

class Dog : public AAnimal {
private:
	Brain *brain_;

public:
	Dog();

	Dog(const Dog &other);

	~Dog();

	Dog &operator=(const Dog &other);

	void makeSound() const;

	void setIdea(size_t index, const std::string &idea);

	const std::string &getIdea(size_t index) const;
};

#endif
