#include "Menu.h"
#include "ATSP.h"
#include "KSwap.h"
#include "BestNeighborFinder.h"
#include "Solution.h"
#include "ATSPSolver.h"
#include "Performance.h"
#include "StopCondition.h"
#include <iostream>;
#include <vector>
#include <iomanip>
#include <algorithm>



int main() {

	// initialize the problem
	ATSP problem;
	problem.read_file("ftv47.atsp");
	ATSPSolver solver;
	std::list<Solution> tabu_list;
	srand(time(NULL));
	NeighborLocator * locator = new KSwap();
	StopCondition stop_condition = StopCondition(200, 0);

	// initial solution
	std::vector<int> path;
	for (int i = 0; i < 48; i++)
	{
		path.push_back(i);
	}
	path.push_back(0);
	Solution solution = Solution(path);
	Solution best_candidate = solution;

	while (!stop_condition.check()) {
		// find best neighbor
		std::list<Solution> neighbors = locator->getNeighbors(best_candidate, 20);
		int best_candidate_value = INT_MAX;
		for (Solution candidate : neighbors)
		{
			int val = candidate.get_value(problem);
			if (val < best_candidate_value
				&& std::find(tabu_list.begin(), tabu_list.end(), candidate) == tabu_list.end())
			{
				best_candidate_value = val;
				best_candidate = candidate;
			}
		}

		// add best neighbor to tabu list
		tabu_list.push_back(best_candidate);
		if (tabu_list.size() > 20)
			tabu_list.pop_front();
		// check if best candidate is better than best solution
		if (best_candidate_value < solution.get_value(problem))
			solution = best_candidate;
	}
	// clean up
	delete locator;
	//menu_loop(problem);
	return 0;
}


