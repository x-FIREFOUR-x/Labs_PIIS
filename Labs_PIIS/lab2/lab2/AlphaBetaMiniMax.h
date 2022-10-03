#pragma once

#include "Algorithm.h"

using namespace std;
class AlphaBetaMiniMax: public Algorithm
{
public:
	pair<int, int> coordinate_move(const Maze& maze,const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
	pair<int, pair<int, int>> minimax(const int depth, const bool is_maximizing, int alpha, int beta,
									  const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;
};

