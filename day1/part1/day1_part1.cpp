#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MOD(a, n) ((a % n) + n) % n // mathemetical modulo
// because C++ mod doesn't handle negatives the same way

int dial = 50;
int num_zero = 0;

void processLine(const std::string& line) {
    char direction = line[0];
    int amount = std::stoi(line.substr(1, line.size()));

    if (direction == 'R') {
        dial = (dial + amount) % 100;
    } else if (direction == 'L') {
        dial = MOD((dial - amount), 100);
    }

    static int num_print = 5;

    if (num_print > 0) {
        std::cout << "new dial: " << dial << std::endl;
        --num_print;
    }

    if (dial == 0) {
        ++num_zero;
    }
}

int main() {
    std::ifstream input;
    input.open("input.txt");

    std::string line;

    if (input.is_open()) {
        while(std::getline(input, line)) {
            processLine(line);
        }
    }

    std::cout << "Number of times the dial hit zero: " << num_zero << std::endl;
}