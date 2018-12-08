#pragma once
#include "NeighborLocator.h"
class TestNeighborLocator :
	public NeighborLocator
{
public:
	TestNeighborLocator() { };
	~TestNeighborLocator() { };
	std::list<Solution> getNeighbors(const Solution& solution, int n);
};

