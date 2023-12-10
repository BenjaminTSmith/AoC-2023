#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

struct Position {

    int x, y;

    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Position operator+(Position otherPosition) const {
        return {this->x + otherPosition.x, this->y + otherPosition.y};
    }
};

std::unordered_map<char, Position> pipes {

};

int main() {

    std::ifstream input("test-input.txt");
    std::string line;
    std::vector<std::vector<char>> diagram;
    std::vector<std::vector<int>> distances;

    while (std::getline(input, line)) {
        std::vector<char> pipe;
        std::vector<int> distance;
        for (auto character: line) {
            pipe.push_back(character);
            distance.push_back(0);
        }
        diagram.push_back(pipe);
        distances.push_back(distance);
    }

    Position currentPosition(0, 0);

    for (int i = 0; i < diagram.size(); i++) {
        for (int j = 0; j < diagram[i].size(); j++) {
            if (diagram[i][j] == 'S') {
                currentPosition.x = j;
                currentPosition.y = i;
            }
        }
    }



    return 0;
}
