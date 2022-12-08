/* https://adventofcode.com/2022/day/8 */

#include <iostream>
#include <vector>
#include <string>


static int visible_in_row(const std::vector<char> &line, const size_t &col)
{
    auto is_visible {1};
    for (size_t i {0}; i < col; ++i)
    	if (line.at(i) >= line.at(col)) {
    	    is_visible = 0;
    	    break;
	}
    if (is_visible)
    	return 1;
    is_visible = 1;
    for (size_t i {col + 1}; i < line.size(); ++i)
    	if (line.at(i) >= line.at(col)) {
    	    is_visible = 0;
    	    break;
	}
    return is_visible;
}

static int visible_in_column(const std::vector<std::vector<char>> &matrix,
	const size_t &row, const size_t &col)
{
    auto is_visible {1};
    for (size_t i {0}; i < row; ++i)
    	if (matrix.at(i).at(col) >= matrix.at(row).at(col)) {
    	    is_visible = 0;
    	    break;
	}
    if (is_visible)
    	return 1;
    is_visible = 1;
    for (size_t i {row + 1}; i < matrix.size(); ++i)
    	if (matrix.at(i).at(col) >= matrix.at(row).at(col)) {
    	    is_visible = 0;
    	    break;
	}
    return is_visible;
}

static auto scenic_score(const std::vector<std::vector<char>> &matrix,
	const size_t &row, const size_t &col)
{
    auto score {0}, distance {0};
    for (auto i {row - 1}; i != static_cast<size_t>(-1); --i) {
    	++distance;
    	if (matrix.at(i).at(col) >= matrix.at(row).at(col))
    	    break;
    }
    score = distance;
    distance = 0;
    for (auto i {row + 1}; i < matrix.size(); ++i) {
    	++distance;
    	if (matrix.at(i).at(col) >= matrix.at(row).at(col))
    	    break;
    }
    score *= distance;
    distance = 0;
    for (auto i {col - 1}; i != static_cast<size_t>(-1); --i) {
    	++distance;
    	if (matrix.at(row).at(i) >= matrix.at(row).at(col))
    	    break;
    }
    score *= distance;
    distance = 0;
    for (auto i {col + 1}; i < matrix.at(row).size(); ++i) {
    	++distance;
    	if (matrix.at(row).at(i) >= matrix.at(row).at(col))
    	    break;
    }
    return score * distance;
}


int main()
{
    std::vector<std::vector<char>> grid;
    std::string line;

    for (size_t row {0}; std::getline(std::cin, line); ++row) {
	grid.emplace_back();
	for (auto i : line)
	    grid.at(row).push_back(i);
    }
    auto visible {0}, score {0};
    for (size_t row {0}; row < grid.size(); ++row) {
    	for (size_t col {0}; col < grid.at(row).size(); ++col) {
	    std::cout << grid.at(row).at(col);
	    if (row == 0 || col == 0 || row == grid.size() - 1
	    	    || col == grid.at(row).size() - 1)
	    	++visible;
	    else if (visible_in_row(grid.at(row), col))
	    	++visible;
	    else if (visible_in_column(grid, row, col))
	    	++visible;
	    if (row != 0 && col != 0 && row != grid.size() - 1
	    	    && col != grid.at(row).size() - 1) {
	    	auto scene = scenic_score(grid, row, col);
	    	if (scene > score)
	    	    score = scene;
	    }
	}
	std::cout << ' ' << visible << std::endl;
    }
    std::cout << visible << " trees are visible from outside the grid."
    	<< std::endl;
    std::cout << "The highest scenic score is " << score << std::endl;
}
