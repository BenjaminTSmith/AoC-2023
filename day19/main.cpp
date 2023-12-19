#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main() {

    std::unordered_map<std::string, std::vector<std::string>> workflows;
    std::vector<std::string> ratings;

    std::ifstream input("test-input.txt");
    std::string line;

    while (std::getline(input, line)) {
        bool sortingWorkflows = true;
        if (line.empty()) { sortingWorkflows = false; }

        if (sortingWorkflows) {
            size_t nameEnd = line.find('{');
            std::string name = line.substr(0, nameEnd);
            line.erase(0, nameEnd + 1);
            std::vector<std::string> workflow;
            size_t pos;
            while ((pos = line.find(',')) != std::string::npos) {
                workflow.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            workflow.push_back(line.substr(0, line.size() - 2));

            workflows[name] = workflow;

        } else if (!line.empty()) {
            line.erase(0, 1);
            line.erase(line.size() - 2, 1);
            ratings.push_back(line);
        }
    }

    return 0;
}
