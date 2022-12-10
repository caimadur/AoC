/* https://adventofcode.com/2022/day/9 */

#include <iostream>
#include <vector>


struct Knot {
    int x;
    int y;
    Knot() : x(0), y(0) {}
    Knot(Knot const & k) : x(k.x), y(k.y) {}
    Knot(const int & a, const int & b) : x(a), y(b) {}
};


static void add_unique(std::vector<Knot> & v, const Knot & k)
{
    // my computer is fast enough without hash table
    for (auto i : v)
    	if (i.x == k.x && i.y == k.y)
    	    return;
    v.emplace_back(k);
}


int main()
{
    Knot h,t;
    std::vector<Knot> visited;

    char direction;
    int steps;
    while(std::cin >> direction >> steps) {
    	for (auto i {0}; i < steps; ++i) {
    	    switch(direction) {
		case 'U':
		    ++h.x;
		    break;
		case 'D':
		    --h.x;
		    break;
		case 'R':
		    ++h.y;
		    break;
		case 'L':
		    --h.y;
		    break;
	    }
	    if (h.x - t.x > 1) {
	    	++t.x;
	    	t.y = h.y;
	    } else if (t.x - h.x > 1) {
	    	--t.x;
	    	t.y = h.y;
	    } else if (h.y - t.y > 1) {
	    	++t.y;
	    	t.x = h.x;
	    } else if (t.y - h.y > 1) {
	    	--t.y;
	    	t.x = h.x;
	    }
	    add_unique(visited, t);
	}
    }
    std::cout << visited.size() << std::endl;
}
