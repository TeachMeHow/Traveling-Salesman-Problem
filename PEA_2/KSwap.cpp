#include "KSwap.h"



KSwap::KSwap()
{
}


KSwap::~KSwap()
{
}

std::list<Solution> KSwap::getNeighbors(const Solution & solution, int n)
{
	// extract path info
	std::vector<int> path = solution.get_path();
	int path_size = path.size();
	int k = 2;
	int first_swappable_position = 1;
	int last_swappable_position = path_size - 1;
	
	// neighbor list
	std::list<Solution> neighbors;

	// get n candidates
	int pos_1, pos_2;
	while (n-- > 0)
	{
		// find positions
		pos_1 = rand() % last_swappable_position + first_swappable_position;
		do { pos_2 = rand() % last_swappable_position + first_swappable_position; 
		} while (pos_2 == pos_1);

		// swap positions
		int buffer = path[pos_1];
		path[pos_1] = path[pos_2];
		path[pos_2] = buffer;

		// add candidate to neighbors
		neighbors.emplace_back(Solution(path)); 

		// swap back
		buffer = path[pos_1];
		path[pos_1] = path[pos_2];
		path[pos_2] = buffer;

	}
	return neighbors;
}
