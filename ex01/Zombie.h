#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <new>
#include <string>
#include <cassert>
#include <iostream>

class Zombie {
  public:
    Zombie();
    Zombie( const std::string& initName );
    ~Zombie();
    void setName( const std::string& initName );
    void announce( void );

  private:
    std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
