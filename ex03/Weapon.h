#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
  public:
    Weapon(std::string initType);
    ~Weapon();
    const std::string& getType();
    void               setType(std::string newType);

  private:
    std::string type;
};


#endif
