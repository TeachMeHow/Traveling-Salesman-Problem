#pragma once
#include "ATSP.h"
#include <vector>
#include <list>
#include "TestNeighborLocator.h"
class ATSPSolver
{
	int stop_time = 0;

public:
	ATSPSolver();
	~ATSPSolver();
	void tabu_search(ATSP& atsp, std::vector<int>& solution, NeighborLocator* locator);
	//void simulated_anneal(ATSP& atsp, std::vector<int>& solution);
};

