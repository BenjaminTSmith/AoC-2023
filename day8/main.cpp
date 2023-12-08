#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <tuple>

int main() {

    std::ifstream input("input.txt");
    std::string line;
    std::vector<int> directions;

    std::unordered_map<std::string, std::tuple<std::string, std::string>> coordinates;

    while (std::getline(input, line)) {

        if (line.find('=') != std::string::npos) {

            std::string position = line.substr(0, 3);
            std::tuple<std::string, std::string> coordinate(line.substr(7, 3), line.substr(12, 3));

            coordinates[position] = coordinate;

        } else {
            for (const auto& letter: line) {
                if (letter == 'L') { directions.push_back(0); }
                else if (letter == 'R') { directions.push_back(1); }
            }
        }
    }

    int i = 0;
    int currentCount = 0;
    std::string currentPosition = "AAA";
    std::string newPosition;

    while (currentPosition != "ZZZ") {
        if (i >= directions.size()) { i = 0; }
        if (directions[i] == 0) {
            newPosition = std::get<0>(coordinates[currentPosition]);
        } else {
            newPosition = std::get<1>(coordinates[currentPosition]);
        }
        currentPosition = newPosition;

        currentCount++;
        i++;
    }

    std::cout << currentCount << std::endl;

    return 0;
}
