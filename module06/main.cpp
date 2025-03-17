#include <iostream>
#include <string>
#include <iomanip>
#include "Option.h"
#include "ScalarConverter.h"
#include <cmath>

void printCharResult(Option<char> *charPtr) {
	std::cout << "char: ";
	if (!charPtr->isSome())
		std::cout << "impossible" << std::endl;
	else {
		char c = charPtr->unwrap();
		if (c < 32 || c > 126)
			std::cout << "None displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
}

void printIntResult(Option<int> *intPtr) {
	std::cout << "int: ";
	if (!intPtr->isSome())
		std::cout << "impossible" << std::endl;
	else
		std::cout << intPtr->unwrap() << std::endl;
}

void printFloatResult(Option<float> *floatPtr) {
    std::cout << "float: ";
    if (!floatPtr->isSome())
        std::cout << "impossible" << std::endl;
    else {
        float value = floatPtr->unwrap();
        if (std::isnan(value)) {
            std::cout << "nanf" << std::endl;
        } else if (std::isinf(value)) {
            if (value < 0)
                std::cout << "-inff" << std::endl;
            else
                std::cout << "+inff" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
        }
    }
}

void printDoubleResult(Option<double> *doublePtr) {
    std::cout << "double: ";
    if (!doublePtr->isSome())
        std::cout << "impossible" << std::endl;
    else {
        double value = doublePtr->unwrap();
        if (std::isnan(value)) {
            std::cout << "nan" << std::endl;
        } else if (std::isinf(value)) {
            if (value < 0)
                std::cout << "-inf" << std::endl;
            else
                std::cout << "+inf" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(1) << value << std::endl;
        }
    }
}
int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::ConvertResult result = ScalarConverter::convert(std::string(argv[1]));
	// ScalarConverter convert;
	// (void) convert;
	printCharResult(result.charPtr);
	printIntResult(result.intPtr);
	printFloatResult(result.floatPtr);
	printDoubleResult(result.doublePtr);

	delete result.charPtr;
	delete result.intPtr;
	delete result.floatPtr;
	delete result.doublePtr;
}
