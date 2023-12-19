#include <iostream>
#include <fstream>
#include <vector>

void spinCycle(std::vector<std::string>& rocks) {
    // roll north
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
    // roll west
    for (int col = 0; col < rocks[0].size(); col++) {
        for (auto& row : rocks) {
            int i = 1;
            if (row[col] == 'O') {
                while (col - i >= 0 && row[col - i] == '.') {
                    row[col - i] = 'O';
                    row[col - i + 1] = '.';
                    i++;
                }
            }
        }
    }

    // roll south
    for (int row = (int)rocks.size() - 1; row >= 0; row--) {
        for (int rock = 0; rock < rocks[row].size(); rock++) {
            int i = 1;
            if (rocks[row][rock] == 'O') {
                while (row + i < rocks.size() && rocks[row + i][rock] == '.') {
                    rocks[row + i][rock] = 'O';
                    rocks[row + i - 1][rock] = '.';
                    i++;
                }
            }
        }
    }

    // roll east
    for (int col = (int)rocks[0].size() - 1; col >= 0; col--) {
        for (auto& row: rocks) {
            int i = 1;
            if (row[col] == 'O') {
                while (col + i < rocks[0].size() && row[col + i] == '.') {
                    row[col + i] = 'O';
                    row[col + i - 1] = '.';
                    i++;
                }
            }
        }
    }
}

int main() {

    std::ifstream input("input.txt");
    std::string line;

    std::vector<std::string> rocks;

    while (input >> line) {
        rocks.push_back(line);
    }

    std::vector<std::vector<std::string>> prev;
    int cycleStart = -1;
    int cycleEnd;
    for (unsigned long long i = 0; i < 1000000000; i++) {
        prev.push_back(rocks);
        spinCycle(rocks);
        int j;
        for (j = 0; j < prev.size(); j++) {
            bool found = true;
            for (int k = 0; k < rocks.size(); k++) {
                if (prev[j][k] != rocks[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                cycleStart = j;
                cycleEnd = (int) i;
                break;
            }
        }

        if (cycleStart != -1) { break; }
    }

    std::cout << "Cycle start: " << cycleStart << "; Cycle end: " << cycleEnd << "; \n";
    int loopLength = 1000000000 - cycleStart;
    int cycleLength = cycleEnd - cycleStart + 1;
    int loopNum = loopLength % cycleLength;
    rocks = prev[loopNum + cycleStart];

    // print rocks
    for (const auto& row: rocks) {
        std::cout << row << std::endl;
    }

    // calculate and print structural stress
    size_t totalLoad = 0;
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
