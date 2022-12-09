/* https://adventofcode.com/2022/day/9 */

#include <iostream>
#include <vector>
#include <set>


struct Knot {
    int x;
    int y;
    Knot() : x(0), y(0) {}
    Knot(Knot const & k) : x(k.x), y(k.y) {}
    Knot(const int & a, const int & b) : x(a), y(b) {}

    bool operator==(const Knot &k) const {
    	return this->x == k.x && this->y == k.y;
    }

    bool operator!=(const Knot & k) const {
    	return !(*this == k);
    }

    bool operator<(const Knot & k) const {
    	return this->x < k.x || (this->x == k.x && this->y < k.y);
    }

    bool operator>(const Knot & k) const {
    	return this->x > k.x || (this->x == k.x && this->y > k.y);
    }
};


int main()
{
    constexpr size_t tail {9};
    std::vector<Knot> rope;
    std::set<Knot> visited1, visited2;
    for (size_t i {0}; i <= tail; ++i)
    	rope.emplace_back();

    char direction;
    int steps;
    while(std::cin >> direction >> steps) {
    	for (auto step {0}; step < steps; ++step) {
    	    switch(direction) {
		case 'U':
		    ++rope.at(0).x;
		    break;
		case 'D':
		    --rope.at(0).x;
		    break;
		case 'R':
		    ++rope.at(0).y;
		    break;
		case 'L':
		    --rope.at(0).y;
		    break;
	    }
	    for (size_t i {0}; i <= rope.size() - 2; ++i) {
	    	auto j {i + 1};
		if (rope.at(i).x - rope.at(j).x > 1) {
		    ++rope.at(j).x;
		    if (rope.at(i).y != rope.at(j).y)
			rope.at(i).y > rope.at(j).y ? ++rope.at(j).y : --rope.at(j).y;
		} else if (rope.at(j).x - rope.at(i).x > 1) {
		    --rope.at(j).x;
		    if (rope.at(i).y != rope.at(j).y)
			rope.at(i).y > rope.at(j).y ? ++rope.at(j).y : --rope.at(j).y;
		} else if (rope.at(i).y - rope.at(j).y > 1) {
		    ++rope.at(j).y;
		    if (rope.at(i).x != rope.at(j).x)
			rope.at(i).x > rope.at(j).x ? ++rope.at(j).x : --rope.at(j).x;
		} else if (rope.at(j).y - rope.at(i).y > 1) {
		    --rope.at(j).y;
		    if (rope.at(i).x != rope.at(j).x)
			rope.at(i).x > rope.at(j).x ? ++rope.at(j).x : --rope.at(j).x;
		}
	    }
	    visited1.emplace(rope.at(1));
	    visited2.emplace(rope.at(tail));
	}
    }
    std::cout << "short rope: " << visited1.size() << std::endl;
    std::cout << "long rope: " << visited2.size() << std::endl;
}
