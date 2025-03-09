#include <iostream>

int creatReplacedFile(const std::string &filename, const std::string &s1, const std::string &s2) {
	std::ifstream ifs(filename.c_str());
	if (ifs)
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] <<  " <filename> <search string> <replace string>" << std::endl;
	}
	return createReplacedFile(argv[1], argv[2], argv[3]);
}
