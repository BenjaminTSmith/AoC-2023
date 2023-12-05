#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <limits>

unsigned long long convertSeed (unsigned long long seed, std::vector<std::array<unsigned long long, 3>>& maps) {

    for (const std::array<unsigned long long, 3> map: maps) {
        if (seed >= map[1] && seed < map[1] + map[2]) {
            seed = map[0] + (seed - map[1]);
            break;
        }
    }

    return seed;
}

int main() {

    std::ifstream input("input.txt");
    std::string line;
    std::stringstream iss;
    std::vector<unsigned long long> seeds;
    std::vector<std::array<unsigned long long, 3>> maps;
    std::string currentVector;

    int count = 0;
    std::array<unsigned long long, 3> map = {};

    while (input >> line) {
        iss << ' ' << line;
    }

    input.close();

    while (iss >> line) {
        if (line == "seeds:") {
            currentVector = "seeds";

        } else if (line == "map:") {
            currentVector = "map";

            for (unsigned long long& seed: seeds) {
                seed = convertSeed(seed, maps);
            }

            maps = {};

        } else if (isdigit(line[0])) {
            if (currentVector == "seeds") {
                seeds.push_back(std::stoul(line));

            } else if (currentVector == "map") {
                map[count] = std::stoul(line);
                count++;
                if (count == 3) {
                    maps.push_back(map);
                    map = {};
                    count = 0;
                }
            }
        }
    }

    unsigned long long min = std::numeric_limits<unsigned long long>::max();
    for (unsigned long long seed: seeds) {
        if (seed < min) {
            min = seed;
        }
    }

    std::cout << min << std::endl;

    return 0;
}