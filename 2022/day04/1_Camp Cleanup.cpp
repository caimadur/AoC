// https://adventofcode.com/2022/day/4

#include <iostream>


struct assignment {
    int lo;
    int hi;
};


int main()
{
    auto count {0};
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
    }
    std::cout << count << std::endl;
}
