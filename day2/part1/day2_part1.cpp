#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>

int countDigits(uint64_t num) {
    if (num == 0) return 1;

    int count = 0;
    
    while (num > 0) {
        num /=  10;
        ++count;
    }

    return count;
}

uint64_t processRange(std::string& range) {
    //std::cout << "range: " << range << std::endl;

    uint64_t sum_of_invalid = 0;

    size_t pos = range.find('-');
    if (pos != std::string::npos) {
        uint64_t before = std::stoull(range.substr(0, pos));
        uint64_t after = std::stoull(range.substr(pos + 1));

        uint64_t val = before;
        while (val <= after) {
            int num_digits = countDigits(val);
            if (num_digits % 2 == 0) {
                int mid_index = num_digits / 2;
                std::string val_string = std::to_string(val);
                int first_half = std::stoi(val_string.substr(0, mid_index));
                int second_half = std::stoi(val_string.substr(mid_index));
                if (first_half == second_half) {
                    // invalid
                    sum_of_invalid += val;
                }
            }
            ++val;
        }
    }

    return sum_of_invalid;
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
    uint64_t sum_of_invalid = 0;
    while(std::getline(iss, range, ',')) {
        sum_of_invalid += processRange(range);
    }

    std::cout << "Sum of invalid IDs: " << sum_of_invalid << std::endl;
}