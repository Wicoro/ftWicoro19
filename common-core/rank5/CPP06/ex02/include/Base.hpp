#ifndef BASE_HPP
#define BASE_HPP

#include <string>

class Base {
	public:
		virtual ~Base();

		static Base	*generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);

		virtual std::string getType() const = 0;
};

#endif
