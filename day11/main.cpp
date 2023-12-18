#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {

    std::ifstream input("input.txt");
    std::string row;
    std::vector<std::string> observatory;

    // expand rows
    while (input >> row) {
        if (std::all_of(row.begin(), row.end(), [](char i){return i == '.';})) {
            observatory.push_back(row);
        }
        observatory.push_back(row);
    }

    // expand columns
    for (size_t i = 0; i < observatory[0].size(); i++) {
        bool expand = true;
        for (auto& line: observatory) {
            if (line[i] == '#') {
                expand = false;
                break;
            }
        }
        if (expand) {
            for (auto& line: observatory) {
                line.insert(i, 1, '.');
            }
            i++;
        }
    }

    std::vector<std::pair<int, int>> galaxies;
    int sum = 0;

    for (int i = 0; i < observatory.size(); i++) {
        for (int j = 0; j < observatory[i].size(); j++) {
            if (observatory[i][j] == '#') { galaxies.emplace_back(i, j); }
        }
    }

    for (auto galaxy1: galaxies) {
        for (auto galaxy2: galaxies) {
            if (galaxy1 == galaxy2) { break; }

            sum += abs(std::get<0>(galaxy1) - std::get<0>(galaxy2)) + abs(std::get<1>(galaxy1) - std::get<1>(galaxy2));

        }
    }

    std::cout << sum << std::endl;

    return 0;
}