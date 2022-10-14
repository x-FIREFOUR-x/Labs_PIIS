#pragma once

#include "Algorithm.h"

class MiniMax : public Algorithm
{

public:
	MiniMax(int max_depth, int coef_dist_enemys, int coef_dist_end);
	pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
	pair<int, pair<int, int>> minimax(const int depth, const bool is_maximizing, const Maze& maze,
									  const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;
};

