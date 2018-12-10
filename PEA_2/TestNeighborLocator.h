#pragma once
#include "NeighborLocator.h"
#include <vector>
class TestNeighborLocator :
	public NeighborLocator
{
	int last_start = 0;
	int next_swap = 0;
public:
	TestNeighborLocator() { };
	~TestNeighborLocator() { };
	std::list<Solution> getNeighbors(const Solution& solution, int n);
};

