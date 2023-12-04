#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream file("input.txt");
    std::string word;

    struct Game {
        int redCubes;
        int greenCubes;
        int blueCubes;
    };

    int MAX_RED = 12;
    int MAX_GREEN = 13;
    int MAX_BLUE = 14;
    int id = 1;
    std::vector<int> possibleGames;

    while (std::getline(file, word)) {
        Game game{.redCubes = 0, .greenCubes = 0, .blueCubes = 0};
        int currentNum = 0;
        for (int i = 0; i < word.length(); i++) {
            if (isdigit(word[i])) {
                int size = 1;
                int j = 1;
                while (isdigit(word[i + j])) {
                    size++;
                    j++;
                }
                if (size == 1) {
                    currentNum = word[i] - '0';
                    std::cout << currentNum << std::endl;
                } else {
                    currentNum = std::stoi(word.substr(i, j + 1));
                    i += j - 1;
                    std::cout << currentNum << std::endl;
                }
            } else if (word[i] == 'r' && word[i - 1] != 'g') {
                if (currentNum > game.redCubes) {
                    game.redCubes = currentNum;
                }
            } else if (word[i] == 'g') {
                if (currentNum > game.greenCubes) {
                    game.greenCubes = currentNum;
                }
            } else if (word[i] == 'b') {
                if (currentNum > game.blueCubes) {
                    game.blueCubes = currentNum;
                }
            }
        }

        possibleGames.push_back(game.redCubes * game.blueCubes * game.greenCubes);

        id++;
    }

    int sum = 0;
    for (int num: possibleGames) {
        sum += num;
    }
    std::cout << sum << std::endl;

    return 0;
}
