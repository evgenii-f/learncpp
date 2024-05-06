#include <iostream>

namespace MonsterType {
    enum MonsterType {
        orc,
        goblin,
        troll,
        ogre,
        skeleton
    };
}

int main() {
    MonsterType::MonsterType monster1 { MonsterType::orc };
    std::cout << "Monster 1 is " << monster1 << "\n";
    MonsterType::MonsterType monster2 { MonsterType::ogre };
    std::cout << "Monster 2 is " << monster2 << "\n";

    return 0;
}