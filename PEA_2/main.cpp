#include "Menu.h"
#include "ATSP.h"
#include "TestNeighborLocator.h"
#include "Solution.h"
#include "ATSPSolver.h"
#include "Performance.h"
#include <iostream>;
#include <vector>
#include <iomanip>
int main() {

	std::vector<int> sample_path = { 1, 2, 3, 4, 5, 6, 7, 8, 1 };
	Solution sample_solution = Solution(sample_path);
	NeighborLocator* locator; 
	TestNeighborLocator test_locator;
	locator = &test_locator;
	std::list<Solution> sample_neighbor_solutions = locator->getNeighbors(sample_solution, 10);
	int neighbor_counter = 0;
	for (Solution sol : sample_neighbor_solutions)
	{
		std::cout << "Neigbor " << ++neighbor_counter << std::endl;
		for (int v : sample_solution.get_path())
		{
			std::cout << std::setw(3) << v;
		}
		std::cout << std::endl;
		for (int v : sol.get_path())
		{
			std::cout << std::setw(3) << v;
		}
		std::cout << "\n\n";
	}
	ATSP problem;
	//time_measurement();
	menu_loop(problem);
	return 0;
}


