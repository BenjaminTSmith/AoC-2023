#include <iostream>
#include <fstream>
#include <vector>

int main() {

    int sum = 0;

    std::ifstream input("input.txt");
    std::string word;

    while (std::getline(input, word)) {
        std::vector<int> winningNums;
        std::vector<int> yourNums;
        int foundNum;
        char symbol = ' ';
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ':') {
                symbol = ':';
                continue;
            } else if (word[i] == '|') {
                symbol = '|';
                continue;
            }
            if (isdigit(word[i])) {
                for (int j = i; j < word.length() + 1; ++j) {
                    if (!isdigit(word[j])) {
                        foundNum = std::stoi(word.substr(i, j - i));
                        i = j - 1;
                        break;
                    }
                }
                if (symbol == ':') { winningNums.push_back(foundNum); }
                else if (symbol == '|') {yourNums.push_back(foundNum); }
            }
        }

        int wins = 0;
        for (int yourNum: yourNums) {
            for (int winningNum: winningNums) {
                if (yourNum == winningNum) {
                    wins++;
                    break;
                }
            }
        }
    }

    std::cout << sum << '\n';

    return 0;
}
