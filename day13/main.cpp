#include <iostream>
#include <fstream>
#include <vector>



int main() {

    std::ifstream input("test-input.txt");
    std::string line;

    while (std::getline(input, line)) {
        std::vector<std::string> rockFormation;

        rockFormation.push_back(line);

        if (line.empty()) {



            rockFormation.clear();
        }

    }

    return 0;
}
