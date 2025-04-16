#include "Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

ComplainLevel getComplainLevel( std::string level ) {
    if ( level == "DEBUG" )
        return ComplainLevel::eDebug;
    else if ( level == "INFO" )
        return ComplainLevel::eInfo;
    else if ( level == "WARNING" )
        return ComplainLevel::eWarning;
    else if ( level == "ERROR" )
        return ComplainLevel::eError;
    return ComplainLevel::eOther;
}

void Harl::filter( std::string level ) {
    ComplainLevel complainLevel{ getComplainLevel( level ) };
    switch ( complainLevel ) {
        case ComplainLevel::eDebug:
            debug();
        case ComplainLevel::eInfo:
            info();
        case ComplainLevel::eWarning:
            warning();
        case ComplainLevel::eError:
            error();
            return;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
    }
}

// void Harl::complain( std::string level ) {
//     std::string levels[]    = { "DEBUG", "INFO", "WARNING", "ERROR" };
//     fcnPtr      functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

//     for ( int i = 0; i < 4; ++i ) {
//         if ( levels[i] == level ) {
//             ( this->*functions[i] )();
//             break;
//         }
//     }
// }

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << '\n';
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup "
                 "burger. I really do!"
              << '\n';
    std::cout << '\n';
}

void Harl::info( void ) {
    std::cout << "[ INFO ]" << '\n';
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough "
                 "bacon in my burger! If you did, I wouldn't be asking for more!"
              << '\n';
    std::cout << '\n';
}
void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << '\n';
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, "
                 "whereas you started working here just last month."
              << '\n';
    std::cout << '\n';
}
void Harl::error( void ) {
    std::cout << "[ ERROR ]" << '\n';
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
    std::cout << '\n';
}
