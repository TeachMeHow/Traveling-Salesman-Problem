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

	//std::vector<int> sample_path = { 1, 2, 3, 4, 5, 6, 7, 8, 1 };
	//Solution sample_solution = Solution(sample_path);
	//NeighborLocator* locator; 
	//TestNeighborLocator test_locator;
	//locator = &test_locator;
	//std::list<Solution> sample_neighbor_solutions = locator->getNeighbors(sample_solution, 10);
	//int neighbor_counter = 0;
	//for (Solution sol : sample_neighbor_solutions)
	//{
	//	std::cout << "Neigbor " << ++neighbor_counter << std::endl;
	//	for (int v : sample_solution.get_path())
	//	{
	//		std::cout << std::setw(3) << v;
	//	}
	//	std::cout << std::endl;
	//	for (int v : sol.get_path())
	//	{
	//		std::cout << std::setw(3) << v;
	//	}
	//	std::cout << "\n\n";
	//}

	// initialize the problem
	ATSP problem;
	problem.read_file("ftv47.atsp");
	int candence = 10, neighborhood_size = 10, best_value_overall = INT_MAX;
	int best_candence = INT_MAX;
	int best_neighborhood_size = INT_MAX;
	for (int ia = 0; ia < 24; ia++, candence += 7)
	{
		for (int ib = 0; ib < 24; ib++, neighborhood_size += 7)
		{



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
				int n = neighborhood_size;
				std::list<Solution> neighbors = locator->getNeighbors(best_candidate, n);
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
				if (tabu_list.size() > candence)
					tabu_list.pop_front();
				// check if best candidate is better than best solution
				if (best_candidate_value < solution.get_value(problem))
					solution = best_candidate;
			}
			//std::cout << "Best solution: " << solution.get_value(problem);
			if (solution.get_value(problem) < best_value_overall)
			{
				best_value_overall = solution.get_value(problem);
				best_candence = candence;
				best_neighborhood_size = neighborhood_size;
			}
			// clean up
			delete locator;
		}
	}
	std::cout << "Best cadence: " << best_candence << "\nBest neighborhood size: " << best_neighborhood_size;
	//menu_loop(problem);
	return 0;
}


