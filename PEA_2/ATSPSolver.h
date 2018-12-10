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
	Solution tabu_search(ATSP& atsp, 
		Solution starting_solution,
		NeighborLocator* locator, 
		int tabu_list_size,
		int neighborhood_size,
		int ms_time_limit, 
		int iteration_limit);
	Solution greedy(ATSP& atsp);
	//void simulated_anneal(ATSP& atsp, std::vector<int>& solution);
};

