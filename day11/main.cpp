#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {

    std::ifstream input("input.txt");
    std::string row;
    std::vector<std::string> observatory;
    std::vector<std::vector<int>> distanceGraph;

    int expandSize = 1000000;
    // expand rows
    while (input >> row) {
        std::vector<int> distances;
        distances.reserve(row.size());
        for (int i = 0; i < row.size(); i++) {
            distances.push_back(0);
        }

        if (std::all_of(row.begin(), row.end(), [](char i){return i == '.';})) {
            std::fill(distances.begin(), distances.end(), expandSize);
            distanceGraph.push_back(distances);
        } else {
            std::fill(distances.begin(), distances.end(), 1);
            distanceGraph.push_back(distances);
        }
        observatory.push_back(row);
    }

    // expand columns
    for (size_t i = 0; i < observatory[0].size(); i++) {
        bool expand = true;
        for (auto& line: observatory) {
            if (line[i] == '#') {
                expand = false;
                break;
            }
        }
        if (expand) {
            for (auto& distances: distanceGraph) {
                distances[i] = expandSize;
            }
            i++;
        }
    }

    std::vector<std::pair<int, int>> galaxies;
    unsigned long long sum = 0;

    for (int i = 0; i < observatory.size(); i++) {
        for (int j = 0; j < observatory[i].size(); j++) {
            if (observatory[i][j] == '#') { galaxies.emplace_back(i, j); }
        }
    }

    for (auto galaxy1: galaxies) {
        for (auto galaxy2: galaxies) {
            if (galaxy1 == galaxy2) { break; }

            int xDist = 0;
            int start = std::min(std::get<1>(galaxy1), std::get<1>(galaxy2));
            int end = std::max(std::get<1>(galaxy1), std::get<1>(galaxy2));
            for (int x = start; x < end; x++) {
                xDist += distanceGraph[std::get<0>(galaxy1)][x];
            }

            int yDist = 0;
            start = std::min(std::get<0>(galaxy1), std::get<0>(galaxy2));
            end = std::max(std::get<0>(galaxy1), std::get<0>(galaxy2));
            for (int x = start; x < end; x++) {
                yDist += distanceGraph[x][std::get<1>(galaxy1)];
            }

            sum += xDist + yDist;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}