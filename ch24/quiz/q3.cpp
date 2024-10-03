// We’re going to write a simple game where you fight monsters. The goal of the game 
// is to collect as much gold as you can before you die or get to level 20.

// Our program is going to consist of 3 classes: a Creature class, a Player class, 
// and a Monster class. Player and Monster both inherit from Creature.

// a) First create the Creature class. Creatures have 5 attributes: 
//     A name (std::string), 
//     a symbol (a char), 
//     an amount of health (int), 
//     the amount of damage they do per attack (int), and 
//     the amount of gold they are carrying (int). 
// Implement these as class members. 
// Write a full set of getters (a get function for each member). 
// Add three other functions: 
//     void reduceHealth(int) reduces the Creature’s health by an integer amount. 
//     bool isDead() returns true when the Creature’s health is 0 or less. 
//     void addGold(int) adds gold to the Creature.

// The following program should run and print:
// The orc has 3 health and is carrying 15 gold.
#include <iostream>
#include <string>
#include <string_view>
#include <limits.h>
#include "../../tools/Random.h"
#include <memory>
// g++ q3.cpp -I ../../tools/  -std=c++17 

class Creature{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_attack{};
    int m_gold{};
public:
    Creature(
        const std::string_view name = "???",
        char symbol = '?',
        int health = 1,
        int attack = 1,
        int gold = 0    
    ) : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_attack{ attack }, m_gold{ gold } {
    }

    const std::string& getName() const{ return m_name; }
    char getSymbol() const{ return m_symbol; }
    int getHealth() const{ return m_health; }
    int getAttack() const{ return m_attack; }
    int getGold() const{ return m_gold; }

    void reduceHealth(int dHealth){ m_health -= dHealth; }
    void addGold(int dGold){ m_gold += dGold; }
    bool isDead() const{ return m_health <= 0; }
};

// int main()
// {
// 	Creature o{ "orc", 'o', 4, 2, 10 };
// 	o.addGold(5);
// 	o.reduceHealth(1);
// 	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

// 	return 0;
// }

// b) Now we’re going to create the Player class. 
// The Player class inherits from Creature. 
// Player has one additional member, the player’s level, which starts at 1. 
// The player has a custom name (entered by the user), uses symbol ‘@’, 
//     has 10 health, does 1 damage to start, and has no gold. 

// Write a function called levelUp() that increases the player’s level and damage by 1. 
// Also write a getter for the level member. 
// Finally, write a function called hasWon() that returns true if the player has reached level 20.

// Write a new main() function that asks the user for their name and produces the output as follows:

// Enter your name: Alex
// Welcome, Alex.
// You have 10 health and are carrying 0 gold.


class Player : public Creature {
private:
    int m_level{};

public:
    Player(const std::string_view name) 
        : Creature(name, '@', 10, 1, 0), m_level{ 1 } {
    }

    void levelUp() { 
        ++m_level;
        ++m_attack;
    }
    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }
};

// int main() {
//     Player* p{ new Player("Alex") };
//     std::cout << "Welcome, " << p -> getName() << std::endl;
//     std::cout <<  "You have " << p->getHealth() << " and are carrying " << p->getGold() << " gold\n";

//     return 0;
// }

// c) Next up is the Monster class. Monster also inherits from Creature. Monsters have no non-inherited member variables.

// First, write an empty Monster class inheriting from Creature, and then add an enum
//  inside the Monster class named Type that contains enumerators for the 3 monsters 
//  that we’ll have in this game: dragon, orc, and slime 
//  (you’ll also want a max_types enumerator, as that will come in handy in a bit).

// d) Each Monster type will have a different name, symbol, starting health, gold, and damage. 
// Here is a table of stats for each monster Type (given)

// Next step is to write a Monster constructor, so we can create monsters. 
// The Monster constructor should take a Type enum as a parameter, and then create a
// Monster with the appropriate stats for that kind of monster.

// There are a number of different ways to implement this (some better, some worse). 
// However in this case, because all of our monster attributes are predefined (not 
// random or customized per creature), we can use a lookup table. 
// Our lookup table will be a C-style array of Creature, where indexing the array 
// with a Type will return the appropriate Creature for that Type.

// Since this Creature table is specific to Monster, we can define it inside the Monster 
// class as static inline Creature monsterData[] { }, initialized with our Creature elements.

// Our Monster constructor is then easy: we can call the Creature copy constructor and 
// pass it the appropriate Creature from our monsterData table.

class Monster: public Creature {
public:
    enum Type{
        dragon,
        orc,
        slime,
        max_types
    };
private:
    static inline Creature monsterData[] {
        Creature("dragon", 'D', 20, 4, 100),
        Creature("orc", 'o', 4, 2, 25),
        Creature("slime", 's', 1, 1, 10),
    };

    static_assert(std::size(monsterData) == max_types);

public:
    Monster(const Type& type) : Creature(monsterData[type]) {
    }

    static Monster getRandomMonster() {
        Type type{ static_cast<Type>(Random::get(0, Type::max_types-1)) };
        return Monster(type);
    }

    friend std::ostream& operator<<(std::ostream& out, const Monster& monster);
};

std::ostream& operator<<(std::ostream& out, const Monster& monster) {
    out << monster.getName() << "(" << monster.getSymbol() << ")";
    return out; 
}

// The following program should compile and print:
// A orc (o) was created.

// #include <iostream>
// #include <string>

// int main()
// {
// 	Monster m{ Monster::Type::orc };
// 	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

// 	return 0;
// }


// e) Finally, add a static function to Monster named getRandomMonster(). 
// This function should pick a random number from 0 to max_types-1 and return a monster (by value) with that Type 
// (you’ll need to static_cast the int to a Type to pass it to the Monster constructor).

// The following main function should run:


// int main()
// {
// 	for (int i{ 0 }; i < 10; ++i)
// 	{
// 		Monster m{ Monster::getRandomMonster() };
// 		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
// 	}

// 	return 0;
// }

std::string getPlayerName(){
    std::cout << "Enter your name: ";
    std::string name {};
    std::cin >> name;
    return name;
};

int getGold(const Monster& monster);
void fightMonster(Player& player, Monster& monster);

class Game {
private:
    Player& m_player;
    bool m_isOver{};

public:
    Game(Player& player) : m_player{ player }, m_isOver{ false } {
        std::cout << "Welcome, " << m_player.getName() << std::endl;
    }

    bool makeTurn() {
        Monster monster{ Monster::getRandomMonster() };
        std::cout << "You have encountered " << monster << std::endl;
        while (monster.getHealth() > 0  && m_player.getHealth() > 0) {
            bool isToFight{ this -> isToFight() };

            if (!isToFight) {
                bool successFlee{ tryToEscape() };
                if (successFlee)
                    return true;
            }

            fightMonsterOneTime(monster);
        
        }
        if (m_player.getHealth() > 0)
            rewardPlayer(monster);
        return m_player.getHealth() > 0;
    }

    void fightMonsterOneTime(Monster& monster) {
        int playerAttack{ m_player.getAttack() };
        monster.reduceHealth(playerAttack);
        std::cout << "You hit the " << monster.getName() << " for " << playerAttack 
                    << " damage.\n";
        if (monster.getHealth() <= 0) {
            std::cout << "You killed the " << monster.getName() << "\n";

        }
        else {
            int monsterAttack{ monster.getAttack() };
            m_player.reduceHealth( monsterAttack );
            std::cout << "The " << monster.getName() <<  " hit you for " << monsterAttack
                << " damage. Now you have " << m_player.getHealth() << " health.\n";
        }
    }

    void printDeathStats() {
        std::cout << "You died at level " << m_player.getLevel() <<  " and with "
            << m_player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }

    void rewardPlayer(const Monster& monster) {
        m_player.levelUp();
        std::cout << "You are now level " << m_player.getLevel() << std::endl;
        m_player.addGold(monster.getGold());
        std::cout << "You found " << m_player.getGold() << " gold.\n";
    }
    
    static bool isToFight() {
        while (true) {
            char choice{};
            std::cout << "(R)un or (F)ight: ";
            std::cin >> choice;
            choice = static_cast<char>(tolower(choice));
            if (choice == 'f' || choice == 'r')
                return choice == 'f';
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    static bool tryToEscape() {
        bool successFlee{ Random::get(0, 1) == 0 };
        if (successFlee) {
            std::cout << "You successfully fled.\n";
        } else {
            std::cout << "You failed to flee.\n";
        }
        return successFlee;
    }
};

int main() {
    std::unique_ptr<Player> player = std::make_unique<Player>("Ruru");
    auto game{ std::make_unique<Game>(*player) };

    while( game->makeTurn() )
        ;
    
    game->printDeathStats();
    
    return 0;
}