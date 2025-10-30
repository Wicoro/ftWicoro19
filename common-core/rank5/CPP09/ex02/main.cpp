#include "include/Merge_Insert_Vector.hpp"
#include "include/Merge_Insert_Deque.hpp"
#include <ctime>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error : Invalid arg count" << std::endl;
		return (1);
	}
	MergeInsertVector miv;
	try {
		miv.fillMain(av[1]);
	} catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
		return (1);
	}

	std::cout << "Before: ";
	for (size_t i = 0 ; i < miv.getMain().size() ; i++) {
		std::cout << (miv.getMain())[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
    
	std::clock_t startV = std::clock();
	miv.sort();
	std::clock_t endV = std::clock();
	double elapsed_ms_vector = static_cast<double>(endV - startV) / CLOCKS_PER_SEC * 1000000.0;


	std::cout << "After: ";
	miv.checkSort();

	MergeInsertDeque mid;
	try {
		mid.fillMain(av[1]);
	} catch (std::exception e) {
		std::cerr << "Error :" << e.what() << std::endl;
	}
	std::clock_t startD = std::clock();
	mid.sort();
	std::clock_t endD = std::clock();
	double elapsed_ms_deque = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000000.0;

	mid.checkSort();

	std::cout << "Time to process a range of " << miv.getMain().size() << " element(s) with std::vector : "  << elapsed_ms_vector << " µs" << std::endl <<std::endl;
	std::cout << "Time to process a range of " << miv.getMain().size() << " element(s) with std::deque : "  << elapsed_ms_deque << " µs" << std::endl;
}