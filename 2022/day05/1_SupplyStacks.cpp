// https://adventofcode.com/2022/day/5

#include <iostream>
#include <vector>
#include <forward_list>
#include <string>


int main()
{
    std::forward_list<std::string> lines;
    do {
	lines.push_front("");
	std::getline(std::cin, lines.front());
    } while (lines.front().at(1) != '1');

    std::vector<std::forward_list<char>> stacks;
    for (size_t i = 0; i <= lines.front().size() / 4; ++i)
    	stacks.push_back({});
    lines.pop_front();
    
    while (! lines.empty()) {
	size_t col = 1;
	for (size_t i = 0; i <= lines.front().size() / 4; ++i) {
	    if (lines.front().at(col) != ' ')
	    	stacks[i].push_front(lines.front().at(col));
	    col += 4;
	}
	lines.pop_front();
    }
    
    std::string move, from, to;
    size_t n, old, nju;
    while (std::cin >> move >> n >> from >> old >> to >> nju)
    	for (size_t i = 0; i < n; ++i) {
    	    stacks[nju - 1].push_front(stacks[old - 1].front());
    	    stacks[old - 1].pop_front();
	}

    for (auto&& i : stacks)
    	if (! i.empty())
    	    std::cout << i.front();
    std::cout << std::endl;
}
