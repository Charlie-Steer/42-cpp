#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define IDEA_COUNT 100

class Brain {
  private:
	std::string ideas[IDEA_COUNT];

  public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void setIdea(int index, const std::string &idea);
	const std::string *getIdea(int index) const;
};

#endif
