// https://adventofcode.com/2022/day/3

#include <iostream>
#include <string>
#include <set>


int main()
{
    auto prioSum {0};

    std::string rucksack;
    while (std::cin >> rucksack) {
	std::set<int> comp1, comp2;
	for (size_t i = 0; i < rucksack.size()/2; ++i)
	    comp1.insert(rucksack[i]);
	for (size_t i = rucksack.size()/2; i < rucksack.size(); ++i)
	    comp2.insert(rucksack[i]);
	for (auto i : comp1)
	    if (comp2.count(i))
	    	prioSum += i < 'a' ? i - 'A' + 27 : i - 'a' + 1;
    }
    std::cout << prioSum << std::endl;
}
