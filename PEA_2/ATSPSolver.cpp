#include "ATSPSolver.h"
#include "StopCondition.h"
#include "BestNeighborFinder.h"



ATSPSolver::ATSPSolver()
{
}


ATSPSolver::~ATSPSolver()
{
}

Solution ATSPSolver::tabu_search(ATSP & atsp,
	Solution starting_solution,
	NeighborLocator * locator,
	int tabu_list_size,
	int neighborhood_size,
	int ms_time_limit, 
	int iteration_limit)
{
	Solution best_solution = starting_solution;
	int best_value = best_solution.get_value(atsp);
	Solution current_solution = best_solution;
	std::list<Solution> tabu_list;
	std::list<Solution> neighbor_solutions;
	StopCondition condition = StopCondition(ms_time_limit, iteration_limit);
	BestNeighborFinder finder;

	while (!condition.check())
	{
		neighbor_solutions = locator->getNeighbors(current_solution, neighborhood_size);
		int value = current_solution.get_value(atsp);
		for (Solution candidate : neighbor_solutions)
		{
			int candidate_value = candidate.get_value(atsp);
			if (candidate_value < value && std::find(tabu_list.begin(), tabu_list.end(), candidate) == tabu_list.end())
			{
				value = candidate_value;
				current_solution = candidate;
			}
		}
		tabu_list.push_back(current_solution);
		if (tabu_list.size() > tabu_list_size)
			tabu_list.pop_front();
		if (value < best_value)
		{
			best_value = value;
			best_solution = current_solution;
		}
	}
	
	return best_solution;
}

Solution ATSPSolver::greedy(ATSP & atsp)
{
	std::vector<int> vertices;
	for (int i = 0; i < atsp.get_size(); i++)
	{
		vertices.push_back(i);
	}
	std::vector<int> solution;

	int v = vertices.front();

	while(!vertices.empty())
	{
		solution.push_back(v);
		vertices.erase(std::find(vertices.begin(), vertices.end(), v));

		int min_distance = INT_MAX;
		for (int next_vertice : vertices)
		{

			int distance = atsp.get_distance(v, next_vertice);
			if (distance < min_distance)
			{
				min_distance = distance;
				v = next_vertice;
			}
		}

	}
	solution.push_back(solution.front());
	return Solution();
}
