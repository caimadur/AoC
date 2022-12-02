// https://adventofcode.com/2022/day/2

#include <iostream>

int main()
{
    char elf, me;
    auto score {0};

    while (std::cin >> elf >> me) {
	switch (me) {
	    case 'X': // Rock
		score += 1;
		if (elf == 'C')
		    score += 6;
		else if (elf == 'A')
		    score += 3;
		break;
	    case 'Y':  // Paper
		score += 2;
		if (elf == 'A')
		    score += 6;
		else if (elf == 'B')
		    score += 3;
		break;
	    case 'Z': // Scissors
		score += 3;
		if (elf == 'B')
		    score += 6;
		else if (elf == 'C')
		    score += 3;
	}
    }
    std::cout << score << std::endl;
}
