#pragma once

#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange {
public:
	BitcoinExchange();

	~BitcoinExchange();

	BitcoinExchange(const std::string &inputFilePath);

	BitcoinExchange(const std::string &inputFilePath, const std::string &dataFilePath);

	BitcoinExchange(BitcoinExchange &other);

	BitcoinExchange &operator=(const BitcoinExchange &other);

	void run();

	const std::string &getInputFilePath() const;

	const std::string &getDataFIlePath() const;

private:
	std::string inputFilePath_;
	std::string dataFilePath_;
	bool isValidData_;
	std::map<std::string, float, std::greater<std::string> > exchangeRates_;

	void initExchangeRates();

	static std::pair<std::string, float> parseExchangeRateLine(const std::string &line) throw(std::runtime_error);

	static std::pair<std::string, float> parseInputLine(const std::string &line) throw(std::runtime_error);

	static bool isValidDataStr(const std::string &dateStr);

	static int s2i(const std::string &str) throw (std::invalid_argument);

	static float s2f(const std::string &str) throw (std::invalid_argument);

	static std::pair<const std::string, std::string> splitLinePair(const std::string &line, char delimiter) throw(std::runtime_error);

	static std::string trim(const std::string &str);
	
};
