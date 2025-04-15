#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <iostream>
#include <string>

class HumanA {
  public:
    HumanA(std::string initName, Weapon& initWeapon);
    ~HumanA();
    void attack();

  private:
    std::string name;
    Weapon*      weapon;
};

#endif
