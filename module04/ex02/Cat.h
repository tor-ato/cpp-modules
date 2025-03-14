#ifndef CPP_MODULES_CAT_H
#define CPP_MODULES_CAT_H

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal {
private:
	Brain *brain_;

public:
	Cat();

	Cat(const Cat &other);

	~Cat();

	Cat &operator=(const Cat &other);

	void makeSound() const;

	void setIdea(size_t index, const std::string &idea);

	const std::string &getIdea(size_t index) const;
};

#endif
