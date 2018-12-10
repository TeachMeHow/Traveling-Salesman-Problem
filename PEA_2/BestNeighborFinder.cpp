#include "BestNeighborFinder.h"



BestNeighborFinder::BestNeighborFinder()
{
}


BestNeighborFinder::~BestNeighborFinder()
{
}

Solution BestNeighborFinder::find(const ATSP & graph, std::list<Solution>& neighbor_solutions, std::list<Solution>& tabu_list)
{
	Solution best_neighbor;
	std::vector<Solution> v{ std::begin(neighbor_solutions), std::end(neighbor_solutions) };
	v.erase(std::remove_if(v.begin(), v.end() - 1,
		[tabu_list](Solution sol) {
		for (Solution tabu_solution : tabu_list)
		{
			return sol == tabu_solution;
		}
	}
	)
	);
	best_neighbor = *neighbor_solutions.begin();
	for (Solution solution : neighbor_solutions) 
	{
		if (solution.get_value(graph) < best_neighbor.get_value(graph))
		{
			best_neighbor = solution;
		}
	}
	
	return best_neighbor;
}
