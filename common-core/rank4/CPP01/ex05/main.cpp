#include "Harl.hpp"

int main() {
	Harl h;

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("RANDOM");

	Harl h2 = h;
	Harl h3;
	h3 = h;

	return 0;
}