#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <array>

int main() {

    std::ifstream input("test-input.txt");
    std::string line;

    std::set<int> seeds;
    std::vector<std::array<unsigned int, 3>> ranges;
    std::string currentMap;

    while (std::getline(input, line)) {

        std::istringstream iss(line);

        std::string word;
        while (iss >> word) {
            if (isdigit(word[0])) {
                if (currentMap == "seeds:") {
                    seeds.emplace(std::stoul(word));
                }
            } else if (word != "map"){
                currentMap = word;
            }
        }

    }

    std::cout << "Seeds:" << '\n';
    for (unsigned long seed: seeds) {
        std::cout << seed << '\n';
    }

    return 0;
}
