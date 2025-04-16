#include "Harl.h"

int main( int argc, char **argv ) {
    Harl harl;

    if ( argc != 2 ) {
        std::cout << "The program takes only one argument" << '\n';
        return 1;
    }

    harl.filter( argv[1] );

    return 0;
}
