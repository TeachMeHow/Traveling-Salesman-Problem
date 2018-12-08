#include "Solution.h"






Solution::Solution(std::vector<int> path, ATSP & graph)
{
	set_path(path, graph);
}

Solution::~Solution()
{
}

std::vector<int> Solution::get_path() const
{
	return path;
}

int Solution::get_score() const
{
	return score;
}

void Solution::set_path(std::vector<int> path, ATSP & graph)
{
	this->path = path;
	score = 0;
	for (auto it = path.cbegin() + 1; it != path.cend(); ++it)
	{
		score += graph.get_distance(*(it - 1), *it);
	}
}
