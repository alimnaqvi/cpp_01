#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <new>
#include <string>
#include <iostream>

class Zombie {
  public:
    Zombie();
    Zombie( const std::string& initName );
    ~Zombie();
    void announce( void );

  private:
    std::string name;
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
