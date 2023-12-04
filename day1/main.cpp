#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main() {
    int sum = 0;

    std::string word;
    std::ifstream myFile("input.txt");

    std::unordered_map<std::string, int> stringToNum = {
            {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
            {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    while (std::getline(myFile, word)) {

        std::vector<int> numArray = {};
        for (int i = 0; i < word.length(); i++) {
            if (isdigit(word[i])) {
                int num = word[i] - '0';
                if (0 <= num && num <= 9) {
                    numArray.push_back(num);
                }
            } else {

                for (int j = 3; j < 6; j++) {
                    std::string testWord = word.substr(i, j);
                    if (stringToNum.count(testWord)) {
                        numArray.push_back(stringToNum[testWord]);
                    }
                }

            }
        }
        sum += numArray[0] * 10 + numArray[numArray.size() - 1];
    }

    std::cout << sum << "\n";

    myFile.close();

    return 0;
}
