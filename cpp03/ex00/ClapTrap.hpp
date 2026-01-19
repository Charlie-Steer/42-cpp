#include "string"

class ClapTrap {
  private:
	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;

  public:
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
};
