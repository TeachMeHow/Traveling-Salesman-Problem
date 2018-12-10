#include "Menu.h"
#include "ATSP.h"
#include "TestNeighborLocator.h"
#include "BestNeighborFinder.h"
#include "Solution.h"
#include "ATSPSolver.h"
#include "Performance.h"
#include <iostream>;
#include <vector>
#include <iomanip>



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

	ATSP problem;
	problem.read_file("ftv47.atsp");
	ATSPSolver solver;
	// initial solution
	std::vector<int> path;
	for (int i = 0; i < 48; i++)
	{
		path.push_back(i);
	}
	path.push_back(0);
	Solution solution = Solution(path);
	//Solution best_solution = solution;
	//// find solution
	TestNeighborLocator locator;
	//std::list<Solution> tabu_list;
	//tabu_list.push_back(solution); 
	//BestNeighborFinder neigbor_finder;
	//// tabu search
	//for (size_t i = 0; i < 10; i++)
	//{
	//	// current solution is tabu
	//	// get neighbor solution and print
	//	std::list<Solution> neighbors = locator.getNeighbors(solution, 10);
	//	for (Solution sol : neighbors)
	//	{
	//		std::cout << sol.get_value(problem) << std::endl;
	//		std::vector<int> path = sol.get_path();
	//		for (int i = 0; i < 10; i++)
	//		{
	//			std::cout << path[i] << " -> ";
	//		}
	//		std::cout << std::endl;
	//	}
	//	// find best neigbor
	//	Solution best_neighbor = neigbor_finder.find(problem, neighbors, tabu_list);
	//	// if best neighbor is better than best found, replace best found
	//	if (best_neighbor.get_value(problem) < solution.get_value(problem))
	//		best_solution = best_neighbor;
	//	// best neighbor is new solution, add to tabu list
	//	solution = best_neighbor;
	//	tabu_list.push_back(solution);
	//	// print best neighbor/ current solution
	//	std::vector<int> bn_path = best_neighbor.get_path();
	//	std::cout << "\n\nBest neighbor " << best_neighbor.get_value(problem);
	//	for (auto it = bn_path.begin(); it != bn_path.begin() + 10; ++it)
	//	{
	//		std::cout << *it << " <- ";
	//	}
	//}
	solution = solver.tabu_search(problem, solution, &locator, 10, 20, 3000, 0);
	int val = solution.get_value(problem);
	//time_measurement();
	menu_loop(problem);
	return 0;
}


