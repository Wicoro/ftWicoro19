#include "include/Merge_Insert_Deque.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>

MergeInsertDeque::MergeInsertDeque() {};
MergeInsertDeque::MergeInsertDeque(const MergeInsertDeque& other): main(other.main), pend(other.pend) {}
MergeInsertDeque& MergeInsertDeque::operator=(const MergeInsertDeque& other) {
	if (this != &other) {
		main = other.main;
		pend = other.pend;
	}
    return *this;
}
MergeInsertDeque::~MergeInsertDeque() {}

static bool lstContain(std::deque<int> &main, int nb) {
	for (size_t i = 0 ; i < main.size(); ++i) {
		if (main[i] == nb)
			return true;
	}
	return false;
}

void	MergeInsertDeque::fillMain(std::string str) {
	std::istringstream iss(str);
    std::string token;
	while (iss >> token) {
		int	nb = 0;
		std::stringstream ss(token);
    	ss >> nb;
		if (lstContain(main, nb)) {
			throw std::runtime_error(std::string("Duplicate number : ") + token);
		}
		main.push_back(nb);
	}
}

static int	pairDivision(std::deque<int> &main, int lvl) {
	int e_size = 1 << lvl;
	if (e_size > (int) main.size() / 2)
		return lvl;
	for (int i = 0 ; i + 1 <= (int) main.size() / (e_size * 2) ; ++i) {
		int j = e_size - 1 + ((e_size * 2) * i);
		int	k = (e_size * 2) - 1 + ((e_size * 2) * i);
		if (main[j] > main[k]) {
			std::swap(main[j], main[k]);
			for (int l = e_size - 1 ; l > 0 ; l--)
				std::swap(main[j - l], main[k - l]);
		}
	}
	return (pairDivision(main, lvl + 1));
}

static void addVectorToVector(std::deque<int> &src, std::deque<int> &dst, int lvl, int i) {
	int e_size = 1 << lvl;
	for (int index = i ; index < i + e_size ; ++index)
		dst.push_back(src[index]);
}

static void	pendSplitter(std::deque<int> &main, std::deque<int> &pend, std::deque<int> &rest, int lvl) {
	int	e_size = 1 << lvl;
	std::deque<int> cpy = main;
	main.clear();
	pend.clear();
	rest.clear();

	//add b1
	addVectorToVector(cpy, main, lvl, 0);
	//ax
	for (int i = e_size ; i + e_size <= (int)cpy.size() ; i += 2 * e_size) {
		addVectorToVector(cpy, main, lvl, i);
	}
	//bx
	for (int i = e_size * 2; i + e_size <= (int)cpy.size(); i += 2 * e_size) {
		addVectorToVector(cpy, pend, lvl, i);
	}
	//rest
	for (int i = (cpy.size() / e_size) * e_size ; i < (int) cpy.size() ; ++i) {
		rest.push_back(cpy[i]);
	}
}

static std::deque<int> getJacobSequence(int limit) {
	std::deque<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while (true) {
		int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		if (next > limit)
			break;
		jacob.push_back(next);
	}
	return jacob;
}

static void	mergeRest(std::deque<int> &main, std::deque<int> &rest) {
	size_t	size = rest.size();
	for (size_t i = 0 ; i < size ; i++) {
		main.push_back(rest[i]);
	}
}

static void addDequetoVectorSort(std::deque<int> &dst, std::deque<int> &dstRef, std::deque<int> &src, int id, int lvl) {
	int e_size = 1 << lvl;
	int	dstRefMaxVal;
	if (((id + 2) * e_size) + e_size - 1 > (int) dstRef.size())
		dstRefMaxVal = dst.back();
	else 
		dstRefMaxVal = dstRef[((id + 2) * e_size) + e_size - 1];
	for (size_t i = e_size - 1 ; i < dst.size() ; i += e_size) {
		if (dst[i] > src[id * e_size + e_size - 1]) {
			for (int j = 0 ; j < e_size ; j++) {
				dst.insert(dst.begin() + i + j - e_size + 1, src[id * e_size + j]);
			}
			break ;
		}
		if (dst[i] == dstRefMaxVal) {
			for (int j = 0 ; j < e_size ; j++) {
				dst.push_back(src[id * e_size + j]);
			}
			break ;
		}
	}
}

static void pendMerger(std::deque<int> &main, std::deque<int> &pend, std::deque<int> &rest, int lvl) {
	if (pend.empty())
		return (mergeRest(main, rest));
	int e_size = 1 << lvl;
	std::deque<int> jac = getJacobSequence(pend.size() / e_size);

	std::deque<int> mainRef = main;
	if ((int) pend.size() == e_size) {
		addDequetoVectorSort(main, mainRef, pend, 0,  lvl);
		mergeRest(main, rest);
		return ;
	}
	for (int i = 1 ; i < (int) jac.size() ; ++i) {
		int	jacNb = jac[i];
		for (int j = 0 ; j < jac[i] - jac[i -1] ; j++) {
			addDequetoVectorSort(main, mainRef, pend, jacNb - 2 - j, lvl);
		}
	}
	for (int i = (int) pend.size() - 1; i >= (jac.back() - 2) * e_size + e_size; i -= e_size) {
		addDequetoVectorSort(main, mainRef, pend, (i + 1 - e_size) / e_size,  lvl);
	}

	mergeRest(main, rest);
}


void	MergeInsertDeque::sort() {
	int lvl = pairDivision(main, 0) - 1;

	for (int lvl_loop = lvl ; lvl_loop >= 0 ; --lvl_loop) {
		pendSplitter(main, pend, rest, lvl_loop);
		pendMerger(main, pend, rest, lvl_loop);
	}
}

void	MergeInsertDeque::checkSort() {
	for (size_t i = 1 ; i < main.size() ; i++) {
		if (main[i] < main[i - 1]) {
			std::cout << "Sorting deque BAD !" << std::endl;
			return ;
		}
	}
	//std::cout << "Sorting deque GOOD !" << std::endl;
}