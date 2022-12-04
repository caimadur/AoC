// https://adventofcode.com/2022/day/3#part2

#include <iostream>
#include <set>
#include <string>
#include <vector>


int main()
{
    auto prioSum {0};

    std::vector<std::string> elves {"","",""};
    while (std::cin >> elves[0] >> elves[1] >> elves[2]) {
	std::vector<std::set<int>> rucksacks;
	for (size_t i = 0; i < elves.size(); ++i) {
	    rucksacks.push_back({});
	    for (auto&& item : elves[i])
	    	rucksacks[i].insert(item);
	}
	for (auto&& item : rucksacks[0])
	    if (rucksacks[1].count(item) && rucksacks[2].count(item))
	    	prioSum += item < 'a' ? item - 'A' + 27 : item - 'a' + 1;
    }
    std::cout << prioSum << std::endl;
}
