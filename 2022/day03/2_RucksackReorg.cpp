// https://adventofcode.com/2022/day/3#part2

#include <iostream>
#include <set>
#include <string>


static void str2set(std::string &a, std::set<int> &s)
{
    for (auto&& i : a)
    	s.insert(i);
}


int main()
{
    auto prioSum {0};

    std::string elf1, elf2, elf3;
    while (std::cin >> elf1 >> elf2 >> elf3) {
	std::set<int> sack1, sack2, sack3;
	str2set(elf1, sack1);
	str2set(elf2, sack2);
	str2set(elf3, sack3);
	for (auto&& item : sack1)
	    if (sack2.count(item) && sack3.count(item))
	    	prioSum += item < 'a' ? item - 'A' + 27 : item - 'a' + 1;
    }
    std::cout << prioSum << std::endl;
}
