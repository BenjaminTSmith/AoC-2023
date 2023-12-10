#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <sstream>

struct Hand {

    std::string cards;
    int bid;

    Hand(std::string cards, int bid) {
        this->cards = std::move(cards);
        this->bid = bid;
    }

    bool operator>(const Hand& otherHand) {
        int count
    }

};

int main() {

    std::ifstream input("test-input.txt");
    std::string line;
    std::vector<Hand> hands;

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
        std::cout << hand.cards << "   " << hand.bid << '\n';
    }

    return 0;
}
