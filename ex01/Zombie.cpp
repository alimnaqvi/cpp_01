#include "Zombie.h"

Zombie::Zombie()
    : name( "noName" )
{}

Zombie::Zombie( const std::string& initName )
    : name( initName )
{}

Zombie::~Zombie() {
    std::cout << name << " destroyed." << '\n';
}

void Zombie::setName( const std::string& initName ) {
    name = initName;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << '\n';
}
