#include <array>
#include <vector>
#include <string_view>
#include <iostream>
#include <limits>
#include <map>

#include "Random.h" // g++ q2.cpp -I ../../tools/  -std=c++17

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        max_type_number
    };
    constexpr std::array<Type, max_type_number> types{ healing, mana, speed, invisibility };
    constexpr std::array<int, max_type_number> prices{ 20, 30, 12, 50} ;
    constexpr std::array<std::string_view, max_type_number> names{ "healing", "mana", "speed", "invisibility"};

    static_assert(std::size(types) == max_type_number);
    static_assert(std::size(prices) == max_type_number);
    static_assert(std::size(names) == max_type_number);

    std::string_view getPotionName(Potion::Type type) {
        switch (type) {
            case (healing): return "potion of healing";
            case (mana): return "potion of mana";
            case (speed): return "potion of speed";
            case (invisibility): return "potion of invisibility";
            default: return "???";
        
        }
    }
}

using inventoryType = std::map<Potion::Type, int>;

inventoryType getEmptyInventory() {
    std::map<Potion::Type, int> inventory{ };
    for (Potion::Type type : Potion::types) {
        inventory[type] = 0;
    }
    return inventory;
}

void printInventory(const inventoryType& inventory) {
    std::cout << "Your inventory contains:\n";
    for (const auto& [type, number] : inventory) {
        std::cout << number << "x " << Potion::getPotionName(type) << std::endl;
    }
}

void shop() {
    using namespace std;
    cout << "Here is our selection for today:\n";
    for (const auto& type : Potion::types) {
        cout << type << ") " << Potion::names[type] << " costs " << Potion::prices[type] << " gold\n";
    }
}

class Player {
private:
    std::string_view m_name{ "???" };
    inventoryType m_inventory{ };
    int m_gold{ };


    static const int s_minStartingGold{ 80 };
    static const int s_maxStartingGold{ 120 };

public:
    Player(const std::string_view name) : 
        m_name{ name },
        m_inventory{ getEmptyInventory() },
        m_gold{ Random::get(s_minStartingGold, s_maxStartingGold) }
    {}

    std::string_view name() const {
        return m_name;
    }

    int gold() const {
        return m_gold;
    }

    int buy(Potion::Type type) {
        int price{ Potion::prices[type] };
        if (price > m_gold) {
            return -1;
        }
        m_inventory[type] += 1;
        m_gold -= price;
        return m_gold;
    }

    inventoryType inventory() {
        return m_inventory;
    }
};

template <typename T, std::size_t N>
constexpr bool checkInput(const std::string_view input, const std::array<T, N>& possibleInputs) {
    if (input.size() != 1) return false;
    char inputChar{ input[0] };

    for (const char& el : possibleInputs) {
        if (el == inputChar) return true;
    }
    return false;
}

using possibleUserInputsArray = std::array<char, Potion::max_type_number + 1>;
constexpr possibleUserInputsArray getPossibleUserInputs() {
    static_assert(Potion::max_type_number + 1 < 10 && "Only up to 10 values are supported so far");
    possibleUserInputsArray out{ 'q' };
    for (auto index{ 1 }; index < std::size(out); index++) out[index] = '0' + static_cast<char>(index - 1);

    return out;
}

Potion::Type getUserInput() {
    using namespace std;
    const auto possibleInputs{ getPossibleUserInputs() };

    string userInput{};
    std::getline(cin >> ws, userInput);
    while (!checkInput(userInput, possibleInputs)) {
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), ' ');
            continue;
        }
        cout << "Oops, wrong input. Choose from ";
        for (int i{ 0 }; i < Potion::max_type_number; i++ ) std::cout << i << ", ";
        std::cout << "or q for exit: ";
        getline(cin >> ws, userInput);
    }

    if (tolower(userInput[0]) == 'q') return Potion::max_type_number;
    return static_cast<Potion::Type>(userInput[0] - '0');
}

int main() {
    const std::string_view greetingStr{ "Welcome to Roscoe's potion emporium!"};
    const std::string_view goodbyeStr{ "Thanks for shopping at Roscoe's potion emporium!" };

    std::cout << greetingStr << std::endl;
    std::cout << "Enter your name: ";
    
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    Player player{ Player(name) };

    std::cout << "Hello, " << player.name() << ", you have " << player.gold() << " gold.\n";
    std::cout << std::endl;
    
    Potion::Type userChoice{ };
    while (true) {
        shop();
        Potion::Type userChoice{ getUserInput() };

        if (userChoice == Potion::max_type_number) break;

        int newGoldAmount{ player.buy(userChoice)};
        if (newGoldAmount >= 0) {
            std::cout << "You purchased a potion of " << Potion::names[userChoice] << ". ";
            std::cout << "You have " << newGoldAmount << " left.\n";
        } else {
            std::cout << "You cannot afford that\n";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    printInventory(player.inventory());
    std::cout << goodbyeStr << "\n";

    return 0;
}