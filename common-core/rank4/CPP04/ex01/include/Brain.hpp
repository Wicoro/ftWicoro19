#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
private:
	std::string idea[100];
	int			last_idea;

public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	int addIdea(std::string str);
	void forgetIdea(int i);
	std::string getIdea(int i) const;
};

#endif