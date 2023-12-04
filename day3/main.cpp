#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>



bool checkPart(const std::vector<std::string>& engineSchematic, std::unordered_map<std::string, std::vector<int>>& gears,
               const int startX, const int endX, const int y, const int num) {
    std::vector<std::string> hashes = {};
    for (int index = startX; index < endX; index++) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (y + i < engineSchematic.size() && y + i >= 0 && index + j >= 0 && index + j < engineSchematic[y + i].length()) {
                    if (engineSchematic[y + i][index + j] == '*') {
                        std::string hashIndex = std::to_string(y + i) + ":" + std::to_string(index + j);
                        bool add = true;
                        for (const std::string& hash: hashes) {
                            if (hash == hashIndex) {
                                add = false;
                            }
                        }
                        if (add) {
                            gears[hashIndex].push_back(num);
                            hashes.push_back(hashIndex);
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {

    std::ifstream input("input.txt");
    std::string word;
    std::vector<std::string> engineSchematic;
    std::unordered_map<std::string, std::vector<int>> gears = {};

    while (std::getline(input, word)) {
        engineSchematic.push_back(word);
    }

    input.close();

    for (int i = 0; i < engineSchematic.size(); i++) {
        for (int j = 0; j < engineSchematic[i].length(); j++) {
            if (isdigit(engineSchematic[i][j])) {
                int startIndex = j;
                int endIndex = j;
                while (isdigit(engineSchematic[i][endIndex]) && endIndex <= engineSchematic[i].length()) {
                    endIndex++;
                }
                int foundNum = std::stoi(engineSchematic[i].substr(startIndex, endIndex - startIndex));
                checkPart(engineSchematic, gears, startIndex, endIndex, i, foundNum);
                j = endIndex - 1;
            }
        }
    }

    unsigned long long sum = 0;
    for (std::pair<std::string, std::vector<int>> gear: gears) {
        if (gear.second.size() == 2) {
            unsigned long ratio = 1;
            for (int num: gear.second) {
                ratio *= num;
            }
            sum += ratio;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
