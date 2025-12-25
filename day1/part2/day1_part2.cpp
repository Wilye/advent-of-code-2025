#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#define MOD(a, n) ((a % n) + n) % n // mathemetical modulo
// because C++ mod doesn't handle negatives the same way

int dial = 50;
int num_zero = 0;

void processLine(const std::string& line) {
    char direction = line[0];
    int amount = std::stoi(line.substr(1, line.size()));

    // std::cout << "direction: " << direction << " amount: " << amount << std::endl;

    int num_zero_one_turn = 0;

    if (direction == 'R') {
        // if (amount + dial >= 100) {
        //     num_zero_one_turn = ((dial + amount) + 100) / 100;
        //     if (num_zero_one_turn >= 2 || (dial == 0 && num_zero_one_turn >= 1)) {
        //         --num_zero_one_turn;
        //     }
        // }
        num_zero_one_turn = (dial + amount) / 100;
        dial = (dial + amount) % 100;
    } else if (direction == 'L') {
        // attempt 1:
        // if (dial - amount <= 0) {
        //     //std::cout << "amount: " << amount << " dial: " << dial << std::endl;
        //     num_zero_one_turn = ((amount - dial) + 100) / 100;

        //     if (num_zero_one_turn >= 2 || (dial == 0 && num_zero_one_turn >= 1)) {
        //         --num_zero_one_turn;
        //     }
        // }
        // attempt 2:
        // bool orig_0 = false;
        // if (dial == 0) {
        //     orig_0 = true;
        // }
        // num_zero_one_turn = -((dial - amount) / 100);
        // if (dial == 0 && !orig_0) {
        //     ++num_zero_one_turn;
        // }

        // corrext attempt:
        // count number of full loops
        num_zero_one_turn = amount / 100;
        // partial loops, counts if it ends at 0
        if (amount % 100 >= dial) {
            ++num_zero_one_turn;
        }
        // if it started at 0, then we over counted by 1
        if (dial == 0) {
            --num_zero_one_turn;
        }
        dial = MOD((dial - amount), 100);

        // this shit took me like 2 days and i still needed claude's help
    }

    static int num_print = 0;

    num_zero += num_zero_one_turn;

    if (num_print > 0) {
        std::cout << "new dial: " << dial << std::endl;
        std::cout << "num_zero: " << num_zero << std::endl;
        --num_print;
    }

}

int main(int argc, char* argv[]) {
    if (argc < 2) { // argv[0] is program name
        std::cerr << "Usage: " << argv[0] << " <input_file_name>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    std::ifstream input;
    input.open(filename);

    if (!input.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::string line;

    if (input.is_open()) {
        while(std::getline(input, line)) {
            processLine(line);
        }
    }

    std::cout << "Number of times the dial hit zero: " << num_zero << std::endl;

    input.close();
}