#include <iostream>
#include <string>

using std::string;

int main()
{
    int max {0}, sum {0};
    for(std::string n; std::getline(std::cin, n);)
    	if (n.length() > 1)
    	    sum+=std::stoi(n);
	else {
	    if (sum > max)
	    	max = sum;
	    sum = 0;
	}
    if (sum > max)
    	max = sum;
    std::cout << max << std::endl;
}

