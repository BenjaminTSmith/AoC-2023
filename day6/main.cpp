#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream input("input.txt");
    std::string line;
    std::string times;
    std::string distances;
    std::string token;

    while (input >> line) {

        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (!isdigit(word[0])) {
                token = word;
            } else {
                if (token == "Time:") {
                    times += word;
                } else if (token == "Distance:") {
                    distances += word;
                }
            }
        }
    }
    unsigned long long finalDistance = std::stoull(distances);
    unsigned long long finalTime = std::stoull(times);

    unsigned long long wins = 0;
    unsigned long long record = finalDistance;
    for (unsigned long long j = 1; j < finalTime; j++) {
        unsigned long long time = finalTime - j;
        unsigned long long distance = time * j;
        if (distance > record) { wins++; }
    }


    std::cout << "Time: " << finalTime;
    std::cout << '\n' << "Distance: " << finalDistance;

    std::cout << std::endl;
    std::cout << wins << '\n';


    return 0;
}
