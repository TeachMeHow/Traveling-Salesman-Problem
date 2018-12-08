#pragma once
#include "ATSP.h"
#include <vector>
class ATSPSolver
{
	int stop_time = 0;
public:
	ATSPSolver();
	~ATSPSolver();
	void tabu_search(ATSP& atsp, std::vector<int>& solution);
	void simulated_anneal(ATSP& atsp, std::vector<int>& solution);
};

