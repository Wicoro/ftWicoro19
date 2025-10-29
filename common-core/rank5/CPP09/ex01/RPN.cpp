#include "include/RPN.hpp"


//Canonical form
RPN::RPN() {}
RPN::RPN(const RPN& other) : st(other.st) {}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        st = other.st;
    }
    return *this;
}
RPN::~RPN() {}

//Method
void	RPN::addNb(int nb) {
	st.push(nb);
}

void	RPN::doOperation(char c) {
	if (st.size() < 2)
		throw std::runtime_error("Not enough number in stack");
	
	int	a;
	int	b;
	a = st.top();
	st.pop();
	b = st.top();
	st.pop();
	
	switch (c)
	{
		case '+':
			st.push(a + b);
			break;
		case '*':
			st.push(a * b);
			break;
		case '-':
			st.push(b - a);
			break;
		case '/':
			if (a == 0)
				throw std::runtime_error("Divided by 0");
			st.push(b / a);
			break;
		default:
			throw std::runtime_error("Unrecognized operator");
	}
}

int	RPN::getStackSize() {
	return st.size();
}

int RPN::getLVal() {
	return (st.top());
}