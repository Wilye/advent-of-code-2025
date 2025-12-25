#include <iostream>
#include <fstream>
#include <sstream>

void processRange(std::string& range) {
    std::cout << "range: " << range << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file_name>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    std::ifstream input;
    input.open(filename);

    if (!input.is_open()) {
        std::cerr << "Error: " << filename << " could not be opened." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(input, line);
    std::istringstream iss(line);

    std::string range;
    while(std::getline(iss, range, ',')) {
        processRange(range);
    }
}