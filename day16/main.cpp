#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

struct Beam {
    std::tuple<int, int> direction = {1, 0};
    std::tuple<int, int> position = {0, 0};

    Beam(int x_pos, int y_pos, int x_dir, int y_dir) {
        std::get<0>(this->direction) = x_dir;
        std::get<1>(this->direction) = y_dir;
        std::get<0>(this->position) = x_pos;
        std::get<1>(this->position) = y_pos;
    }

    void move() {
        std::get<0>(this->position) += std::get<0>(this->direction);
        std::get<1>(this->position) -= std::get<1>(this->direction);
    }
};

int main() {

    std::vector<std::string> graph;
    std::vector<std::vector<int>> seenGraph;
    std::string line;
    std::ifstream input("test-input.txt");

    while (input >> line) {

        graph.push_back(line);
        std::vector<int> unseenGraph;
        for ([[maybe_unused]] const auto& character: line) {
            unseenGraph.push_back(0);
        }
        seenGraph.push_back(unseenGraph);

    }

    std::vector<Beam> beams;
    beams.emplace_back(0, 0, 1, 0);

    while (!beams.empty()) {

        for (auto& beam: beams) {
            int row = std::get<1>(beam.position);
            int col = std::get<0>(beam.position);

            if (graph[row][col] == '/') {
                int temp = std::get<0>(beam.direction);
                std::get<0>(beam.direction) = std::get<1>(beam.direction);
                std::get<1>(beam.direction) = temp;
            } else if (graph[row][col] == '\\') {
                int temp = -1 * std::get<0>(beam.direction);
                std::get<0>(beam.direction) = -1 * std::get<1>(beam.direction);
                std::get<1>(beam.direction) = temp;
            } else if (graph[row][col] == '|') {
                if (std::get<1>(beam.direction) == 0) {
                    std::get<1>(beam.direction) = 1;
                    std::get<0>(beam.direction) = 0;
                    beams.emplace_back(std::get<0>(beam.position), std::get<1>(beam.position),
                            0, -1);
                }
            } else if (graph[row][col] == '-') {
                if (std::get<0>(beam.direction) == 0) {
                    std::get<0>(beam.direction) = 1;
                    std::get<1>(beam.direction) = 0;
                    beams.emplace_back(std::get<0>(beam.position), std::get<1>(beam.position),
                                       -1, 0);
                }
            }

            seenGraph[row][col] = 1;

        }

        for (auto& beam: beams) {
            beam.move();
        }


        for (auto i = beams.begin(); i != beams.end();) {
            if (std::get<1>(i->position) < 0 || std::get<1>(i->position) >= graph.size()
                || std::get<0>(i->position) < 0 || std::get<0>(i->position) >= graph[0].size()) {
                i = beams.erase(i);
            } else {
                ++i;
            }
        }

    }

    int totalEnergized = 0;

    for (const auto& row: seenGraph) {
        for (const auto energy: row) {
            if (energy == 1) { totalEnergized++; }
        }
    }

    std::cout << totalEnergized << std::endl;

    return 0;
}
