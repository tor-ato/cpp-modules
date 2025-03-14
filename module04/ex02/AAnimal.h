#ifndef CPP_MODULES_AANIMAL_H
#define CPP_MODULES_AANIMAL_H

#include <string>

class AAnimal {
protected:
	std::string type_;

public:
	AAnimal();

	AAnimal(const std::string &type);

	AAnimal(const AAnimal &animal);

	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &animal);

	const std::string &getType() const;

	virtual void makeSound() const = 0;
};

#endif
