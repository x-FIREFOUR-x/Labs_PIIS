#pragma once

#include "Algorithm.h"
#include "Entities.h"

class AlphaBetaNegaMax: public Algorithm
{
public:
	AlphaBetaNegaMax(int max_depth, int coef_dist_enemys, int coef_dist_end);
	pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
	pair<int, pair<int, int>> alpha_beta_negamax(const int depth, const Side side, int alpha, int beta,
									  const Maze& maze, const Entities& entities) const;
};

