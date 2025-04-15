#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <iostream>
#include <string>
#include <cstdlib>

class HumanB {
  public:
    HumanB( std::string initName );
    ~HumanB();
    void attack();
    void setWeapon( Weapon& newWeapon );

  private:
    std::string name;
    Weapon*     weapon;
};

#endif
