#pragma once
#include <vector>
#include "ATSP.h"
class Solution
{
private:
	std::vector<int> path;
	int score;
public:
	Solution(std::vector<int> path, ATSP & graph);
	~Solution();
	// TODO path is copied = change to pointer/ ref?
	std::vector<int> get_path() const;
	int get_score() const;
	void set_path(std::vector<int> path, ATSP & graph);
};

