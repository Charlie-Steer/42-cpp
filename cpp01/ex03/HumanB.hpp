#include "Weapon.hpp"

class HumanB {
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(const std::string &name);
	void setWeapon(Weapon &weapon);
	void attack() const;
};
