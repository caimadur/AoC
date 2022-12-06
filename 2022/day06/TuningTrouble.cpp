// https://adventofcode.com/2022/day/6

#include <iostream>
#include <string>


int main()
{
    std::string buffer;
    std::getline(std::cin, buffer);
    for (size_t i = 0; i <= buffer.size() - 4; ++i)
    	if (buffer[i] != buffer[i + 1] && buffer[i] != buffer[i + 2] && buffer[i] != buffer[i + 3] &&
    		 buffer[i + 1] != buffer[i + 2] && buffer[i + 1] != buffer[i + 3] &&
    		 buffer[i + 2] != buffer[i + 3]) {
	    std::cout << i + 4 << std::endl;
	    break;
	}
}
