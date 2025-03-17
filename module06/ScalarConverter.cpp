#include "ScalarConverter.h"
#include "Some.h"
#include "None.h"
#include <string>
#include <sstream>
#include <limits>

bool ScalarConverter::isSpecialValue(const std::string &str) {
    return (str == "nan" || str == "nanf" ||
            str == "-inff" || str == "+inff" ||
            str == "-inf" || str == "+inf");
}

int ScalarConverter::strToInt(const std::string &str) {
	std::istringstream iss(str);
	int value;
	iss >> value;
	return value;
}

float ScalarConverter::strToFloat(const std::string &str) {
    std::istringstream iss(str);
    float value;
    iss >> value;
    return value;
}

double ScalarConverter::strToDouble(const std::string &str) {
    std::istringstream iss(str);
    double value;
    iss >> value;
    return value;
}

ScalarConverter::ConvertResult ScalarConverter::convert(const std::string &str) {
	ConvertResult result;
	result.charPtr = convertToChar(str);
	result.intPtr = convertToInt(str);
	result.floatPtr = convertToFloat(str);
	result.doublePtr = convertToDouble(str);
	return result;
}

Option<char> *ScalarConverter::convertToChar(const std::string &str) {
	if (isSpecialValue(str)) {
        return new None<char>();
    }
	Option<int> *intPtr = convertToInt(str);
	if (!intPtr->isSome())
		return new None<char>();
	int value = intPtr->unwrap();
	delete intPtr;
	return new Some<char>(static_cast<char>(value));
}


Option<int> *ScalarConverter::convertToInt(const std::string &str) {
	if (isSpecialValue(str)) {
        return new None<int>();
    }
	try {
		int value = strToInt(str);
		return new Some<int>(value);
	} catch (std::exception &e) {
		return new None<int>();
	}
}

Option<float> *ScalarConverter::convertToFloat(const std::string &str) {
    if (str == "nan" || str == "nanf") {
        return new Some<float>(std::numeric_limits<float>::quiet_NaN());
    } else if (str == "-inff" || str == "-inf") {
        return new Some<float>(-std::numeric_limits<float>::infinity());
    } else if (str == "+inff" || str == "+inf") {
        return new Some<float>(std::numeric_limits<float>::infinity());
    }
    try {
        float value = strToFloat(str);
        return new Some<float>(value);
    } catch (std::exception &e) {
        return new None<float>();
    }
}

Option<double> *ScalarConverter::convertToDouble(const std::string &str) {
    if (str == "nan" || str == "nanf") {
        return new Some<double>(std::numeric_limits<double>::quiet_NaN());
    } else if (str == "-inf" || str == "-inff") {
        return new Some<double>(-std::numeric_limits<double>::infinity());
    } else if (str == "+inf" || str == "+inff") {
        return new Some<double>(std::numeric_limits<double>::infinity());
    }
    try {
        double value = strToDouble(str);
        return new Some<double>(value);
    } catch (std::exception &e) {
        return new None<double>();
    }
}
