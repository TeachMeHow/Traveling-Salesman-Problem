#pragma once
#include "NeighborLocator.h"
class KSwap :
	public NeighborLocator
{
public:
	KSwap();
	~KSwap();
	std::list<Solution> getNeighbors(const Solution& solution, int n);
};

