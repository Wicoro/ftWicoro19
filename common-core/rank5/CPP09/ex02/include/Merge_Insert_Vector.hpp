#ifndef MERGE_INSERT_VECTOR_HPP
#define MERGE_INSERT_VECTOR_HPP

#include <exception>
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <list>

class MergeInsertVector {
	private:
		std::vector<int>	main;
		std::vector<int>	pend;
		std::vector<int>	rest;
	public:
		MergeInsertVector();
		MergeInsertVector(const MergeInsertVector& other);
		MergeInsertVector& operator=(const MergeInsertVector& other);
		~MergeInsertVector();

		void				fillMain(std::string str);
		void				sort();
		void				checkSort();
		std::vector<int>&	getMain();
};

#endif