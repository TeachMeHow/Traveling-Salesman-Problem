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
	srand(time(NULL));

	NeighborLocator * locator = new KSwap();

	Solution initial_solution;
	std::vector<int> initial_solution_path = std::vector<int>();
	for (int v = 0; v < problem.get_size(); v++)
	{
		initial_solution_path.push_back(v);
	}
	initial_solution_path.push_back(0);
	initial_solution = Solution(initial_solution_path);
	int cadence = 20;
	int neighborhood_size = 20;
	int time_limit_ms = 20 * 1000;
	int iteration_limit = 0;

	int best_cadence = 0;
	int best_ns = 0;
	int best_solution = INT_MAX;
	/*for (int i = 106 - 20; i < 106 + 20; i += 40 / 12)
	{
		for (int j = 154 - 20; j < 154 + 40; j += 40 / 12)
		{*/
			cadence = 50;
			neighborhood_size = 50;
			int solution = solver.tabu_search(problem, initial_solution, locator, cadence, neighborhood_size, time_limit_ms, iteration_limit).get_value(problem);
			if (solution < best_solution)
			{
				best_solution = solution;
				best_cadence = cadence;
				best_ns = neighborhood_size;
			}
	//	}
	//}

	std::cout << "Best Cadence: " << best_cadence << "\nBest NS: " << best_ns << "\nBest solution: " << best_solution;
			std::cout << "Best solution: " << best_solution;
	std::cin.ignore();
	// clean up
	delete locator;
	//menu_loop(problem);
	return 0;
}


