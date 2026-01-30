#include "Brain.hpp"
#include <iostream>
#include <sstream>
#include <string>

Brain::Brain() {
	std::cout << "Brain default constructor.\n";
	for (int idea_index = 0; idea_index < IDEA_COUNT; idea_index++) {
		std::ostringstream oss;
		oss << "idea " << idea_index;
		ideas[idea_index] = oss.str();
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor.\n";

	for (int idea_index = 0; idea_index < IDEA_COUNT; idea_index++) {
		ideas[idea_index] = other.ideas[idea_index];
	}
}

Brain &Brain::operator=(const Brain &other) {
	if (this == &other)
		return *this;

	for (int idea_index = 0; idea_index < IDEA_COUNT; idea_index++) {
		ideas[idea_index] = other.ideas[idea_index];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor.\n";
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index < 0 || index >= IDEA_COUNT) {
		return;
	}
	ideas[index] = idea;
}

const std::string *Brain::getIdea(int index) const {
	if (index < 0 || index >= IDEA_COUNT) {
		return NULL;
	} else {
		return &ideas[index];
	}
}
