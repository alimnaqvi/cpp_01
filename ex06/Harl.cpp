#include "Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::filter( std::string level ) {
    //
}

void Harl::complain( std::string level ) {
    std::string levels[]    = { "DEBUG", "INFO", "WARNING", "ERROR" };
    fcnPtr      functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for ( int i = 0; i < 4; ++i ) {
        if ( levels[i] == level ) {
            ( this->*functions[i] )();
            break;
        }
    }
}

void Harl::debug( void ) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup "
                 "burger. I really do!"
              << '\n';
}

void Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough "
                 "bacon in my burger! If you did, I wouldn't be asking for more!"
              << '\n';
}
void Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, "
                 "whereas you started working here just last month."
              << '\n';
}
void Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}
