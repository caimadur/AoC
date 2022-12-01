#include <iostream>
#include <string>
#include <vector>

class Cals {
    std::vector<int> top;

    public:
    Cals(): top {0, 0, 0} {};
    void insert(int c)
    {
    	for(auto&& t : top)
    	    if (c > t) {
    	    	auto tmp = t;
    	    	t = c;
    	    	c = tmp;
	    }
    }
    int get_max() { return top[0]; }
    int get_total()
    {
    	int total {0};
    	for (auto i : top)
    	    total += i;
    	return total;
    }
};

int main()
{
    int sum {0};
    Cals calories;
    for(std::string n; std::getline(std::cin, n);)
    	if (n.length() > 1)
    	    sum+=std::stoi(n);
	else {
	    calories.insert(sum);
	    sum = 0;
	}
    calories.insert(sum);
    std::cout << "Most Calories: " << calories.get_max() << std::endl;
    std::cout << "Top three: " << calories.get_total() << std::endl;
}

