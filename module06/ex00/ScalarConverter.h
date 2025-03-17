#ifndef CPP_MODULES_SCALARCONVERTER_H
#define CPP_MODULES_SCALARCONVERTER_H

#include <string>
#include "Option.h"

class ScalarConverter {
public:
	typedef struct {
		Option<char> *charPtr;
		Option<int> *intPtr;
		Option<float> *floatPtr;
		Option<double> *doublePtr;
	} ConvertResult;

	static ConvertResult convert(const std::string &str);

private:
	ScalarConverter(void);

    ~ScalarConverter(void);

    ScalarConverter(const ScalarConverter &src);

    ScalarConverter &operator=(const ScalarConverter &rhs);

	static bool isSpecialValue(const std::string &str);

	static int strToInt(const std::string &str);

	static float strToFloat(const std::string &str);

	static double strToDouble(const std::string &str);

	static Option<char> *convertToChar(const std::string &str);
	
	static Option<int> *convertToInt(const std::string &str);

	static Option<float> *convertToFloat(const std::string &str);

	static Option<double> *convertToDouble(const std::string &str);
};

#endif
