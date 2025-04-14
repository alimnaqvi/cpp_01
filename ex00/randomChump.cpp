#include "Zombie.h"

void randomChump( std::string name ) {
    try {
        Zombie* zombiePtr( newZombie( name ) );
        zombiePtr->announce();
        delete zombiePtr;
    } catch ( const std::bad_alloc& e ) {
        std::cerr << "Memory allocation for " << name << " failed: " << e.what() << 'n';
    }
}
