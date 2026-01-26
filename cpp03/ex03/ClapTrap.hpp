#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
  protected:
	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;
	void print_health();
	ClapTrap(const std::string &name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage);

  public:
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	virtual ~ClapTrap();
};

#endif
