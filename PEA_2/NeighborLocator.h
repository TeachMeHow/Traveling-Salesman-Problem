#pragma once
#include "Solution.h"
class NeighborLocator
{
public:
	virtual ~NeighborLocator() { };
	// return n neighbors of solution
	virtual std::list<Solution> getNeighbors(const Solution& solution, int n) = 0;
};