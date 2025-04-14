#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name ) {
    if ( N < 1 ) {
        throw "Number of zombies (N) cannot be smaller than 1.";
    }

    Zombie* zombieArray = new Zombie[N];

    for ( int i = 0; i < N; i++ ) {
        zombieArray[i].setName( name );
    }

    return zombieArray;
}
