// https://adventofcode.com/2022/day/2#part2

#include <iostream>

int main()
{
    char elf, me;
    auto score {0};

    while (std::cin >> elf >> me) {
	switch (elf) {
	    case 'A':
	    	if (me == 'X')
	    	    score += 3;
		else if (me == 'Y')
		    score += 1 + 3;
		else
		    score += 2 + 6;
		break;
	    case 'B':
	    	if (me == 'X')
	    	    score += 1;
		else if (me == 'Y')
		    score += 2 + 3;
		else
		    score += 3 + 6;
		break;
	    case 'C':
	    	if (me == 'X')
	    	    score += 2;
		else if (me == 'Y')
		    score += 3 + 3;
		else
		    score += 1 + 6;
	}
    }
    std::cout << score << std::endl;
}
