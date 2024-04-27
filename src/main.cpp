#include <iostream>
#include <string>
#include "kit.h"
#define STR(text) #text
#define PRINT_TASK(SRT) \
	std::cout << STR(28.4 Practical Work.Task 3.\nSimulation of the work of the\n\
	kitchen of an online restaurant\n-- -- -- -- -- -- -- -- -- -- -- -- -\n)

int main()
{
	Kitchen s;
	s.Clear();
	PRINT_TASK(STR);
	s.startSimulation();
	return 0;
}
