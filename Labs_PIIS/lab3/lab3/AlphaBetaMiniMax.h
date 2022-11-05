#pragma once

#include "Algorithm.h"

using namespace std;
class AlphaBetaMiniMax: public Algorithm
{

public:
	AlphaBetaMiniMax(int max_depth, int coef_dist_enemys, int coef_dist_end);
	pair<int, int> coordinate_move(const Maze& maze,const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
	pair<int, pair<int, int>> minimax(const int depth, const bool is_maximizing, int alpha, int beta,
									  const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;
};

