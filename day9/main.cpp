#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

bool allZero(const std::vector<int>& list) {

    for (const auto& num: list) {
        if (num != 0) { return false; }
    }

    return true;
}

int getNextNum(std::vector<int>& list) {
    if (allZero(list)) {
        return 0;
    }

    std::vector<int> newDifferences;
    for (size_t i = 1; i < list.size(); i++) {
        newDifferences.push_back(list[i] - list[i - 1]);
    }

    return list[list.size() - 1] + getNextNum(newDifferences);
}

int main() {

    std::ifstream input("input.txt");
    std::string line;
    std::vector<std::vector<int>> sequences;

    while (std::getline(input, line)) {

        std::istringstream iss(line);
        std::string num;
        std::vector<int> sequence;

        while (iss >> num) {
            sequence.push_back(std::stoi(num));
        }
        sequences.push_back(sequence);
    }

    int sum = 0;
    for (auto& sequence: sequences) {
        sum += getNextNum(sequence);
    }

    std::cout << sum << std::endl;

    return 0;
}
