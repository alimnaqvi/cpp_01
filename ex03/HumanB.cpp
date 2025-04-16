#include "HumanB.h"

HumanB::HumanB( std::string initName )
    : name{ initName }
    , weapon{ nullptr }
{}

HumanB::~HumanB() {}

void HumanB::attack() {
    std::cout << name << " attacks with their " << weapon->getType() << '\n';
}

void HumanB::setWeapon( Weapon& newWeapon ) {
    weapon = &newWeapon;
}
