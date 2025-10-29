#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stack>

class RPN {
	private:
		std::stack<int> st;

	public:
		//Canonical form
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		//Method
		void	addNb(int nb);
		void	doOperation(char c);
		int		getStackSize();
		int		getLVal();
};

#endif