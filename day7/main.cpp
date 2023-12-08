#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {

    std::ifstream input("test-input.txt");
    std::string line;
    std::vector<std::pair<std::string, int>> hands;

    while (std::getline(input, line)) {
        std::string word;
        std::istringstream iss(line);
        std::string hand;
        int bid;
        while (iss >> word) {
            if (word.size() != 5) {
                bid = std::stoi(word);
            } else {
                hand = word;
            }
        }
        hands.emplace_back(hand, bid);
    }

    std::cout << "Hands: | Bets: " << '\n';
    for (const auto& hand: hands) {
        std::cout << std::get<0>(hand) << "    " << std::get<1>(hand) << '\n';
    }

    return 0;
}
