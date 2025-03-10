#include <iostream>

int main() {
	const std::string brain = "HI THIS IS BRAIN";

	const std::string *stringPTR = &brain;
	const std::string &stringREF =brain;

	std::cout << "Address of brain: " << &brain << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Valeu of brain: " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
