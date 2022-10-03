#pragma once

#include "Algorithm.h"

using namespace std;
class Expectimax : public Algorithm
{
public:
	Expectimax(int max_depth, int coef_dist_enemys, int coef_dist_end);
	pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
	pair<float, pair<int, int>> expectiMax(const int depth, const bool is_maximizing,
		const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;
};

