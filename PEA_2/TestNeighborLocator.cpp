#include "TestNeighborLocator.h"

std::list<Solution> TestNeighborLocator::getNeighbors(const Solution& solution, int n)
{
	std::vector<int> neighbor_path = solution.get_path();
	std::list<Solution> solution_list = std::list<Solution>();
	auto start = neighbor_path.begin() + 1;
	const auto end = neighbor_path.end() - 1;
	auto current = start + 1;
	while (n > 0)
	{
		// change node in solution
		if (current == end)
		{
			if (start < end - 2)
			{
				++start;
				current = start + 1;
			}
			// no more nodes to swap
			else return std::list<Solution>();
		}
		// swap two elements
		int buffer = *start;
		*start = *current;
		*current = buffer;

		// create solution from path
		Solution new_solution = Solution(neighbor_path);
		// add solution to list
		solution_list.push_back(new_solution);
		// reverse swap and increment
		buffer = *start;
		*start = *current;
		*current = buffer;
		++current;
		// decrement
		--n;
	}
	return solution_list;
}
