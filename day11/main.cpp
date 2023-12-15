#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {

    std::ifstream input("test-input.txt");
    std::string line;
    std::vector<std::string> cosmos;

    while (std::getline(input, line)) {

        if (std::all_of(line.begin(), line.end(), [](char i){return i == '.';})) {
            for (int i = 0; i < 2; i++) { cosmos.push_back(line); }
        } else {
            cosmos.push_back(line);
        }

    }

    int j;
    for (int i = 0; i < cosmos.size(); i++) {
        bool expand = true;
        for (j = 0; j < cosmos[i].size(); j++) {
            if (cosmos[i][j] == '#') { expand = false; }
        }
        if (expand) {
            for (int i = 0; i < cosmos.size(); i++) {
                cosmos[i].insert(cosmos[i].begin() + j, '.');
            }
        }
    }

    for (const auto& row: cosmos) {
        std::cout << row << '\n';
    }

    return 0;
}
