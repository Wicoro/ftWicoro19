#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <iterator>

class Span {
	private:
		std::multiset<int>	_set;
		unsigned int		_capacity;
	public:
		Span(const unsigned int cap);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int i);
		int		shortestSpan();
		int		longestSpan();
		void	addVector(std::vector<int>& vct);
		template <typename T>
		void	addRange(T begin, T end);
};

template <typename T>
void Span::addRange(T begin, T end) {
    if (std::distance(begin, end) + _set.size() > (size_t)_capacity)
        throw std::runtime_error("Not enough space in Span");
    _set.insert(begin, end);
}


#endif