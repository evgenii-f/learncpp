#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType {
    notype,
    ogre,
    dragon,
    orc, 
    giantSpider,
    slime
};

struct Monster {
    MonsterType type {MonsterType::notype};
    std::string_view name {"???"};
    int health {};
};

std::ostream& operator<<(std::ostream& out, MonsterType type) {
    switch (type){
        case MonsterType::ogre: {
            out << "Ogre";
            break;
        }
        case MonsterType::dragon: {
            out << "Dragon";
            break;
        }
        case MonsterType::orc: {
            out << "Orc";
            break;
        }
        case MonsterType::giantSpider: {
            out << "Giant Spyder";
            break;
        }
        case MonsterType::slime: {
            out << "Slime";
            break;
        }
        case MonsterType::notype:
        default: 
            out << "???";
    }
    return out;
}

void printMonster(const Monster& monster) {
    std::cout << "This " << monster.type << " is named " << monster.name;
    std::cout << " and has " << monster.health << " health." << "\n";
}

int main() {
    Monster orgTorg {MonsterType::ogre, "Torg", 126};
    Monster spiderPeter {MonsterType::giantSpider, "Peter", 65};
    Monster noname {};

    printMonster(orgTorg);
    printMonster(spiderPeter);
    printMonster(noname);

    return 0;
}