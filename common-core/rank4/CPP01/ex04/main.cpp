#include <iostream>
#include <fstream>
#include <string>

std::string customReplace(const std::string& content, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return content;

	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = content.find(s1, pos)) != std::string::npos) {
		result.append(content.substr(pos, found - pos));
		result.append(s2);
		pos = found + s1.length();
	}

	result.append(content.substr(pos));
	return result;
}

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Cannot open input file: " << filename << std::endl;
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();

	std::string replaced = customReplace(content, s1, s2);

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Cannot open output file: " << filename << ".replace" << std::endl;
		return 1;
	}

	outfile << replaced;
	outfile.close();

	std::cout << "File processed successfully: " << filename << ".replace" << std::endl;
	return 0;
}