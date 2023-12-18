#include <iostream>
#include <fstream>
#include <vector>
#include <array>

int main() {

    std::ifstream input("input.txt");
    std::string line;
    std::vector<std::string> instructions;
    std::array<std::string, 256> lenses;
    input >> line;

    size_t pos;

    while ((pos = line.find(',')) != std::string::npos) {
        instructions.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
    instructions.push_back(line);

    unsigned long long sum = 0;

    for (const auto& instruction: instructions) {
        unsigned long long value = 0;
        for (auto letter: instruction) {
            value += letter;
            value *= 17;
            value %= 256;
        }
        sum += value;
    }

    std::cout << sum;

    return 0;
}
