#include "iostream"
#include "string"
#include "Random.h"

class Monster {
public:
    enum Type {
        dragon, 
        goblin, 
        ogre, 
        orc, 
        skeleton, 
        troll, 
        vampire,
        zombie,
        maxMonsterTypes
    };

private:
    Type m_type {};
    std::string m_name {"???"};
    std::string m_roar {"???"};
    int m_hitPoints {};

public:
    Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
    : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {}

    static const std::string_view getTypeString(Type type) {
        switch (type) {
            case Type::dragon: return "dragon";
            case Type::goblin: return "goblin";
            case Type::ogre: return "ogre";
            case Type::orc: return "orc";
            case Type::skeleton: return "skeleton";
            case Type::troll: return "troll";
            case Type::vampire: return "vampire";
            case Type::zombie: return "zombie";
            default: return "???";

        }
    }

    void print() const {
        std::cout << m_name << " the " << this->getTypeString(m_type);
        if (m_hitPoints <= 0) {
            std::cout << " is dead.\n";
        } else {
            std::cout << " has " << m_hitPoints << " and says " << m_roar <<"\n";
        }
    }
};

namespace MonsterGenerator {
    std::string_view getName(int nameIndex) {
        switch (nameIndex) {
            case 0: return "John";
            case 1: return "Dohn";
            case 2: return "Ron";
            case 3: return "Nikolay";
            case 4: return "Kolya";
            case 5: return "Pavel";
            default: return "???";
        }
    }

    std::string_view getRoar(int roarIndex) {
        switch (roarIndex) {
            case 0: return "*rattle*";
            case 1: return "*aaaa!*";
            case 2: return "*hru-hru!!!*";
            case 3: return "*goNikolaygo!*";
            case 4: return "*Pika-Pika!*";
            case 5: return "*PvlPvlll*";
            default: return "*???*";
        }
    }

    Monster generate() {
        return Monster{ 
            static_cast<Monster::Type>(Random::get(0, Monster::Type::maxMonsterTypes - 1)),
            getName(Random::get(0, 5)),
            getRoar(Random::get(0, 5)),
            Random::get(0, 100)
        };
    }

}
int main()
{
	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
    // Bones the skeleton has 4 hit points and says *rattle*.
	skeleton.print();

	Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
    // Nibblez the vampire is dead.
	vampire.print();

    Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}