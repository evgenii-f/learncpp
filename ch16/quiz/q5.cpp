#include <iostream>
#include "../../tools/Random.h"
#include "string_view"
#include "vector"
#include <algorithm>
#include <limits>

namespace WordList {
    using namespace std::string_view_literals;

    const std::vector wordList {"mystery"sv, "broccoli"sv , "account"sv, "almost"sv,
        "spaghetti"sv, "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv};

    std::string_view sampleWord(){
        auto index{ Random::get(0, wordList.size())};
        return wordList[index];
    }
}

namespace Settings {
    constexpr int maxNumberOfWrongGuesses{ 6 };
}

class Session {
private:
    std::string_view m_word{ WordList::sampleWord() };
    std::vector<bool> m_guesses{};
    std::vector<char> m_wrongGuesses{};
public:
    Session() : m_guesses(32, false) {}

    const std::string_view getWord() const {
        return m_word;
    }

    std::string getHiddenWord() const {
        std::string out(m_word.length(), '_');
        for (std::size_t i{ 0 }; i < m_word.length(); i++) {
            char ch{ m_word[i] };
            int index{ letterToIndex(ch) };
            if (m_guesses[index]) {
                out[i] = ch;
                // std::cout << "index of " << ch << " is " << index << " in the word " << m_word << "\n";
            }
        }
        return out;
    }

    bool ifAlreadyGuessed(char guess){
        return m_guesses[letterToIndex(guess)];
    }

    void makeGuess(char guess) {
        if (!ifAlreadyGuessed(guess) && isLetterWrong(guess)) {
            m_wrongGuesses.push_back(guess);
        }
        
        m_guesses[letterToIndex(guess)] = true;
    }

    int letterToIndex(char letter) const {
        return (letter % 32) - 1;
    }

    bool won() const {
        for (char ch : m_word){
            if (!m_guesses[letterToIndex(ch)]) {
                return false;
            }
        }
        return true;
    }

    int numberOfTriesLeft() const {
        return Settings::maxNumberOfWrongGuesses - m_wrongGuesses.size();
    }

private:
    bool isLetterWrong(char letter) const{
        for (char ch : m_word) {
            if (letter == ch) {
                return false;
            }
        }
        return true;
    }

};

char getUserGuess(){
    using namespace std;
    char input{};
    while (true){
        cout << "Enter your next letter: ";
        cin >> input;
        if (!cin) {
            cout << "That wasn't a valid input.  Try again.\n";
            
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
            break;
        } else {
            cout << "Invalid character. Please enter a letter from A to Z.\n";
        }
    }
    // we don't need locale here (azAz) but leave it as a good practice
    return std::tolower(input, std::locale());
}


int main() {
    Session session{ };

    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";
    std::cout << "\n";

    while (!session.won() && session.numberOfTriesLeft() > 0){
        // std::cout << "Your word is " << session.getWord()<< "\n";
        std::cout << "The word is " << session.getHiddenWord() << "\n\n";
        std::cout << "Number of tries left: " << session.numberOfTriesLeft() << "\n";
        char guess{ getUserGuess() };
        if (session.ifAlreadyGuessed(guess)) {
            std::cout << "You already guessed that.  Try again.\n";
            std::cout << std::endl;
            continue;
        }
        session.makeGuess(guess);
        // std::cout << "You entered: " << guess << "\n"
        std::cout << std::endl;
    }
    if (session.won()){
        std::cout << "Congratulations! You won the game!\n";
    } else {
        std::cout << "You lost :( Come back to play again!\n";
    }

    return 0;
}

