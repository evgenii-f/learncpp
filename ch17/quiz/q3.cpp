#include <iostream>
#include <array>
#include <string_view>
#include <cassert>
#include <algorithm> // for shuffle
#include <limits.h>

#include <Random.h>

struct Card {
    enum Rank {
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        ace,

        max_rank_number
    };
    enum Suit {
        club,
        diamond,
        heart,
        spade,

        max_suit_number
    };

    Rank rank{ };
    Suit suit{ };

    static constexpr std::array<char, max_rank_number> rankNames {
        '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
    };

    static constexpr std::array<char, max_suit_number> suitNames {
        'C', 'D', 'H', 'S'
    };

    static constexpr std::array<Rank, max_rank_number> allRanks { 
        two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace 
    };

    static constexpr std::array<Suit, max_suit_number> allSuits { club, diamond, heart, spade };

    static constexpr std::array<int, max_rank_number> rankValues {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10};
    

    friend std::ostream& operator<<(std::ostream& out, const Card &card) {
        out << rankNames[card.rank] << suitNames[card.suit];
        return out;
    }

    int value() const {
        return rankValues[rank];
    }
};

class Deck {
    std::array<Card, Card::max_rank_number * Card::max_suit_number> m_cards {};
    std::size_t m_cardIndex{ 0 };

public:
    Deck() {
        std::size_t index{ 0 };
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
                m_cards[index++] = Card{ rank, suit };
    }

    Card dealCard() {
        assert(m_cardIndex < std::size(m_cards));

        return m_cards[m_cardIndex++];
    }

    void shuffle() {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_cardIndex = 0;
    }


};

//// main to check Card (copied from the learningcpp)
// int main()
// {
//     // Print one card
//     Card card { Card::five, Card::heart };
//     std::cout << card << '\n';

//     // Print all cards
//     for (auto suit : Card::allSuits)
//         for (auto rank : Card::allRanks)
//             std::cout << Card { rank, suit } << ' ';
//     std::cout << '\n';

//     return 0;
// }

//// main to check deck (copied from the learningcpp)
// int main()
// {
//     Deck deck{};
//     std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

//     deck.shuffle();
//     std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

//     return 0;
// }

struct Player {
    int score{ 0 };

    void getCard(const Card& card) {
        // std::cout << card << " = " << card.value() << std::endl;
        if (card.rank == Card::ace && score + 11 > 21) {
            score += 1;
        } else {
            score += card.value();
        }
    }
};

namespace Settings {
    int WIN_SCORE{ 21 }; // player (or dealer) busts if get more
    int MAX_DEALER_SCORE{ 17 }; // dealer stops flipping cards after reaching this score
}

bool ifPlayerWins(const Player& player, const Player& dealer) {
    if (dealer.score > 21) return true;
    if (player.score > 21) return false;
    if (player.score > dealer.score) return true;
    return false;
}

void playFirstRound(Player& player, Player& dealer, Deck& deck) {
    deck.shuffle(); 

    dealer.getCard(deck.dealCard());
    std::cout << "The dealer is showing: " << dealer.score << std::endl;

    player.getCard(deck.dealCard());
    player.getCard(deck.dealCard());
    std::cout << "You have score: " << player.score << std::endl;
}

bool getPlayerChoice(char hit = 'h', char stand = 's') {
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice{};
    while (true) {
        std::cin >> choice;
        switch (choice) {
            case 'h': return true;
            case 's': return false;
            default: {
                std::cout << "Invalid input! Try again\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
};

int playPlayer(Player& player, Deck& deck) {
    bool ifTakeNextCard{ true };
    while (ifTakeNextCard && player.score < Settings::WIN_SCORE) {
        ifTakeNextCard = getPlayerChoice();
        if (ifTakeNextCard) {
            Card card{ deck.dealCard() };
            player.getCard(card);
            std::cout << "You flip " << card;
            std::cout << ". Now you have score: " << player.score << std::endl;
        }
    }

    return player.score;
}

int playDealer(Player& dealer, Deck& deck) {
    while (true) {
        Card card{ deck.dealCard() };
        dealer.getCard(card);
        std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << '\n';

        if (dealer.score > 21) {
            std::cout << "The dealer went bust!\n";
            return true;
        }
        if (dealer.score > Settings::MAX_DEALER_SCORE) break;
    }
    return dealer.score;
}

bool playBlackjack() {
    Player dealer{ };
    Player player{ };
    Deck deck{ };

    playFirstRound(player, dealer, deck);

    int playerScore{ playPlayer(player, deck) };
    if (player.score > 21) return false;
    int dealerScore{ playDealer(dealer, deck) };

    return Settings::WIN_SCORE - playerScore < Settings::WIN_SCORE - dealerScore;
}


int main() {
    bool result{ playBlackjack() };
    result ? std::cout << "You win!\n" : std::cout << "You loose!\n";
}