#pragma once
#include "Solution.h"
#include <algorithm>
class BestNeighborFinder
{
public:
	BestNeighborFinder();
	~BestNeighborFinder();
	Solution find(const ATSP & graph, std::list<Solution> & neighbor_solutions, std::list<Solution> & tabu_list);
};

