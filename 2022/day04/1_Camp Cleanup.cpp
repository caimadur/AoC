// https://adventofcode.com/2022/day/4

#include <iostream>


struct assignment {
    int lo;
    int hi;
};


int main()
{
    auto count {0}, overlaps {0};
    struct assignment alice, bob;
    char any;

    while (std::cin >> alice.lo >> any >> alice.hi >> any
    	    >> bob.lo >> any >> bob.hi) {
	if (alice.lo == bob.lo || alice.hi == bob.hi)
	    ++count;
	else if (alice.lo < bob.lo && alice.hi > bob.hi)
	    ++count;
	else if (alice.lo > bob.lo && alice.hi < bob.hi)
	    ++count;
	else if (bob.lo < alice.lo && alice.lo <= bob.hi)
	    ++overlaps;
	else if (bob.lo <= alice.hi && alice.hi < bob.hi)
	    ++overlaps;
    }
    std::cout << "In how many assignment pairs does one range fully contain the other? "
    	<< count << std::endl
    	<< "In how many assignment pairs do the ranges overlap? "
    	<< count + overlaps << std::endl;
}
