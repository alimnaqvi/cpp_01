#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl {
  public:
    Harl();
    ~Harl();
    void complain( std::string level );
    typedef void ( Harl::*fcnPtr )();

  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
};

#endif
