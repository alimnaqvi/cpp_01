#include "Weapon.h"

Weapon::Weapon( std::string initType )
    : type( initType )
{}

Weapon::~Weapon() {}

const std::string& Weapon::getType() {
    return type;
}

void Weapon::setType( std::string newType ) {
    type = newType;
}
