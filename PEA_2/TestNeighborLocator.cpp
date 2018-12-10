#include "TestNeighborLocator.h"

std::list<Solution> TestNeighborLocator::getNeighbors(const Solution& solution, int n)
{
	std::vector<int> path = solution.get_path(); 
	std::vector<int>::iterator start;
	std::vector<int>::iterator position;
	std::list<Solution> neighbors;
	if (1 + last_start < path.size() - 1)
	{
		start = path.begin() + 1 + last_start;
	}
	else
		start = path.begin() + 1;
	
	if (1 + last_start + next_swap >= path.size() - 1 )
	{
		next_swap = 0;
	}
	position = start + 1 + next_swap;

	while (n-- > 0)
	{
		next_swap++;
		//swap start, position
		int buffer = *start;
		*start = *position;
		*position = buffer;

		neighbors.emplace_back(Solution(path));

		buffer = *start;
		*start = *position;
		*position = buffer;

		// if position is last element, return to incremented start
		if (position++ == path.end() - 1)
		{
			last_start++;
			if (start++ == path.end() - 2)
				start = path.begin();
			position = start + 1;
			next_swap = 1;
		}
		
	}


	return neighbors;
}
