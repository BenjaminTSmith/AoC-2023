#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream input("input.txt");
    std::string line;

    std::vector<std::string> rocks;

    while (input >> line) {
        rocks.push_back(line);
    }

    // roll forward
    for (int row = 0; row < rocks.size(); row++) {
        for (int rock = 0; rock < rocks[row].size(); rock++) {
            int i = 1;
            if (rocks[row][rock] == 'O') {
                while (row - i >= 0 && rocks[row - i][rock] == '.') {
                    rocks[row - i][rock] = 'O';
                    rocks[row - i + 1][rock] = '.';
                    i++;
                }
            }
        }
    }

    // print rocks
    for (const auto& row: rocks) {
        std::cout << row << std::endl;
    }

    // calculate and print structural stress
    int totalLoad = 0;
    size_t rows = rocks.size();
    for (int i = 0; i < rows; i++) {
        for (auto& rock: rocks[i]) {
            if (rock == 'O') {
                totalLoad += rows - i;
            }
        }
    }
    std::cout << totalLoad;

    return 0;
}
