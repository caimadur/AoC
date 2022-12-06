// https://adventofcode.com/2022/day/6

#include <iostream>
#include <string>


static int first_unique(const std::string &buffer, const size_t &from, const size_t &to)
{
    for (size_t i = from + 1; i < to; ++i)
    	if (buffer.at(from) == buffer.at(i))
    	    return 0;
    return 1;
}

static size_t find_double(const std::string &buffer, size_t &from, const size_t &to)
{
    for (size_t i = from; i < to; ++i)
    	if (first_unique(buffer, i, to) == 0) {
    	    from = i;
    	    return 1;
	}
    return 0;
}

int main()
{
    constexpr size_t length = 14;
    std::string buffer;
    std::getline(std::cin, buffer);
    for (size_t i = 0; i <= buffer.size() - length; ++i) {
    	if (find_double(buffer, i, i + length) == 0) {
	    std::cout << i + length << std::endl;
	    return 0;
	}
    }
}
