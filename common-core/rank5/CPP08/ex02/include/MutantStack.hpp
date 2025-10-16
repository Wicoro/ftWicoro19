#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <stack>

template <typename T>
class MutantStack {
private:

	// Definir node en prive pour n'etre utiliser que dans la classe
	struct Node {
		T			val;
		struct Node	*under;
		struct Node	*above;

		Node(const T& v) : val(v), under(NULL), above(NULL) {}
	};

	struct Node *_topNode;
	size_t		 _size;

public:
	MutantStack();
	MutantStack(const MutantStack&);
	MutantStack& operator=(const MutantStack&);
	~MutantStack();

	void		push(const T& val);
	void		pop();
	T&			top();
	const T&	top() const;
	bool		empty() const;
	size_t		size() const;

	//Conversion constructor
	MutantStack(const std::stack<T>& s);
	operator std::stack<T>() const;

	//Iterator SUBCLASS
	class iterator {
	private:
		Node* current;

	public:
		iterator(Node* node) : current(node) {}

		T& operator*() { return current->val; } // Dereference
		T* operator->() { return &(current->val); } // Arrow operator

		iterator& operator++() {
			current = current->under;
			return *this;
		}

		iterator& operator--() {
			current = current->above;
			return *this;
		}

		bool operator!=(const iterator& other) const {
			return current != other.current;

	};

	//Method iterator
	iterator begin() { return iterator(_topNode); }
	iterator end() {
		Node *crt = _topNode;
		while (crt->under)
			crt = crt->under;
		return crt;
	}
};

#include "MutantStack.tpp"

#endif