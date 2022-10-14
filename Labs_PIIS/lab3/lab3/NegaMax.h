#pragma once

#include "Algorithm.h"
#include "Entities.h"

class NegaMax : public Algorithm
{
public:
	NegaMax(int max_depth, int coef_dist_enemys, int coef_dist_end);
	pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
	pair<int, pair<int, int>> negamax(const int depth, const Side side, const Maze& maze,
		const Entities& entities) const;
};

