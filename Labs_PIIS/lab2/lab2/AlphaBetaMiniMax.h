#pragma once

#include "Algorithm.h"

#include <tuple>

using namespace std;
class AlphaBetaMiniMax: Algorithm
{
	int MAX_VALUE = 1000;
	int MIN_VALUE = -1000;
	int MAX_DEPTH = 3;

public:
	pair<int, int> coordinate_move(const Maze& maze, Player player, vector<AbstractEnemy*> enemys) override;

private:
	pair<int, pair<int,int>> minimax(int depth, bool is_maximizing, int alpha, int beta, const Maze& maze, Player player, vector<AbstractEnemy*> enemys);

	int calculate_value(const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys);
	bool is_terminal(const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys);
};

