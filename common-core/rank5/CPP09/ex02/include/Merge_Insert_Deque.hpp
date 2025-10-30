#ifndef MERGE_INSERT_DEQUE_HPP
#define MERGE_INSERT_DEQUE_HPP

#include <exception>
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <list>

class MergeInsertDeque {
	private:
		std::deque<int>	main;
		std::deque<int>	pend;
		std::deque<int>	rest;
	public:
		MergeInsertDeque();
		MergeInsertDeque(const MergeInsertDeque& other);
		MergeInsertDeque& operator=(const MergeInsertDeque& other);
		~MergeInsertDeque();

		void	fillMain(std::string str);
		void	sort();
		void	checkSort();
};

#endif