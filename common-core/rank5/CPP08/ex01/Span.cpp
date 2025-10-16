#include "include/Span.hpp"

Span::Span(const unsigned int cap) : _capacity(cap) {}

Span::Span(const Span& other) : _set(other._set),  _capacity(other._capacity) {}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    _capacity = other._capacity;
    _set = other._set;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (_set.size() >= (unsigned long)_capacity)
		throw std::runtime_error("Span is full");
	_set.insert(value);
}

void Span::addVector(std::vector<int>& vct) {
	if (vct.size() + _set.size() > (unsigned long)_capacity)
		throw std::runtime_error("Not enough space in Span");

	_set.insert(vct.begin(), vct.end());
}

int Span::shortestSpan() {
	if (_set.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int shortest = 2147483647;
	std::multiset<int>::iterator prev = _set.begin();
	std::multiset<int>::iterator next = ++_set.begin();

	while (next != _set.end()) {
		int diff = *next - *prev;
		if (diff < shortest)
			shortest = diff;
		++prev;
		++next;
	}
	return shortest;
}


int	Span::longestSpan() {
	if (_set.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	return (*_set.rbegin() - *_set.begin());
}