#pragma once
#include <vector>
#include "ATSP.h"
#include <list>
class Solution
{
private:
	std::vector<int> path;
public:
	Solution();
	// Creates solution with path
	Solution(std::vector<int> path);
	Solution(const Solution & obj);
	~Solution();
	// TODO path is copied = change to pointer/ ref?
	std::vector<int> get_path() const;
	// returns total distance of path, following the graph
	int get_value(const ATSP & graph) const;
	// number of vertices in the path
	int get_path_length() const { return path.size() - 1; }
	// set new solution path
	void set_path(std::vector<int> path); 
	// comparator
	friend bool operator==(const Solution& lhs, const Solution& rhs){ return lhs.path == rhs.path; }
};

