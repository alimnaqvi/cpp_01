#include "Zombie.h"

void testZombieHorde( int N, std::string name ) {
    try {
        Zombie* zombieArray = zombieHorde( N, name );
        for ( int i = 0; i < N; i++ ) {
            zombieArray[ i ].announce();
        }
        delete[] zombieArray;
    } catch ( const std::bad_alloc& e ) {
        std::cerr << "Memory allocation for " << name << " failed: " << e.what() << 'n';
    } catch ( const char* e ) {
        std::cerr << name << ": Input error: " << e << '\n';
    }
}

int main() {
    testZombieHorde( 5, "Chalmers" );
    testZombieHorde( 20, "Nagel" );
    testZombieHorde( 1, "Dennett" );
    testZombieHorde( 0, "The Cranberries" );

    return 0;
}
