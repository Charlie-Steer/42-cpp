#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
  private:
	std::string name;

  public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	void whoAmI() const;
	void attack();
};
