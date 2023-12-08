#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <tuple>

int main() {

    std::ifstream input("input.txt");
    std::string line;
    std::vector<int> directions;
    std::vector<std::string> startingNodes;

    std::unordered_map<std::string, std::tuple<std::string, std::string>> coordinates;

    while (std::getline(input, line)) {

        if (line.find('=') != std::string::npos) {

            std::string position = line.substr(0, 3);
            if (position[2] == 'A') { startingNodes.push_back(position); }
            std::tuple<std::string, std::string> coordinate(line.substr(7, 3), line.substr(12, 3));

            coordinates[position] = coordinate;

        } else {
            for (const auto& letter: line) {
                if (letter == 'L') { directions.push_back(0); }
                else if (letter == 'R') { directions.push_back(1); }
            }
        }
    }

    std::vector<unsigned long int> steps;

    for (auto& node: startingNodes) {
        int i = 0;
        unsigned long int currentStep = 0;
        while (node[2] != 'Z') {
            if (i >= directions.size()) { i = 0; }

            if (directions[i] == 0) {
                node = std::get<0>(coordinates[node]);
            } else {
                node = std::get<1>(coordinates[node]);
            }

            i++;
            currentStep++;
        }
        steps.push_back(currentStep);
    }

    for (const auto& step: steps) {
        std::cout << step << " ";
    }

    return 0;
}
