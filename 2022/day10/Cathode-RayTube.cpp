/* https://adventofcode.com/2022/day/10 */

#include <iostream>
#include <string>
#include <vector>


constexpr size_t width {40}, height {6}; // height not needed

static auto strength(size_t & c, const int & reg)
{
    int strength = static_cast<int>(c) * reg;
    c += 40;
    return strength;
}

static auto draw_screen(std::vector<std::string> & screen, const size_t & cycle, const int & X)
{
    auto row {cycle / width};
    auto pixel {cycle % width};
    if (row == screen.size())
    	screen.emplace_back("");
    screen.at(row).push_back(static_cast<int>(pixel) >= X - 1 && static_cast<int>(pixel) <= X + 1 ? '#' : ' ');
}


int main()
{
    int X {1}, signal_strength {0};
    size_t  check {20}, cycle {0};
    std::string instruction;
    std::vector<std::string> screen;
    draw_screen(screen, cycle, X);

    while (std::cin >> instruction) {
    	if (instruction == "noop") {
    	    draw_screen(screen, ++cycle, X);
	    if (cycle == check)
		signal_strength += strength(check, X);
	}
	else { // instruction == addx
	    draw_screen(screen, ++cycle, X);
	    ++cycle;
	    if (cycle >= check)
	    	signal_strength += strength(check, X);
	    int value;
	    std::cin >> value;
	    X += value;
	    draw_screen(screen, cycle, X);
	}
    }
    std::cout << "Signal strengdh is: " << signal_strength << std::endl;
    for (auto line : screen)
    	std::cout << line << std::endl;
}
