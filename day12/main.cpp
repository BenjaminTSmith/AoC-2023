#include <iostream>
#include <fstream>
#include <vector>

int possibleArrangement(std::vector<std::string>& spring, std::vector<int>& arrangement) {



    return 0;
}

int main() {

    std::ifstream input("test-input.txt");
    std::string line;
    std::vector<std::vector<std::string>> springs;
    std::vector<std::vector<int>> springArrangements;
    int count = 0;

    while (input >> line) {
        if (count % 2 == 0) {
            size_t pos;
            std::vector<std::string> spring;
            while ((pos = line.find('.')) != std::string::npos) {
                spring.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            spring.push_back(line);
            springs.push_back(spring);

        } else {
            size_t pos;
            std::vector<int> positions;
            while ((pos = line.find(',')) != std::string::npos) {
                positions.push_back(std::stoi(line.substr(0, pos)));
                line.erase(0, pos + 1);
            }
            positions.push_back(std::stoi(line));
            springArrangements.push_back(positions);
        }
        count++;
    }

    int sum = 0;
    for (auto i = 0; i < springs.size(); i++) {
        sum += possibleArrangement(springs[i], springArrangements[i]);
    }
    std::cout << sum << std::endl;


    return 0;
}
