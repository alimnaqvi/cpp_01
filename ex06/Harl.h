#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

enum class ComplainLevel {
    eDebug,
    eInfo,
    eWarning,
    eError,
    eOther,
};

class Harl {
  public:
    Harl();
    ~Harl();
    void filter( std::string level );
    // void complain( std::string level );
    typedef void ( Harl::*fcnPtr )();

  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
};

#endif
