#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input_file>" <<std::endl;
	}

	BitcoinExchange btc(argv[1], "data.csv");
	btc.run();
}
