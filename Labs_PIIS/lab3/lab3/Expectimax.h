#pragma once

#include "Algorithm.h"

using namespace std;
class Expectimax : public Algorithm
{
	enum NodeState {
		MAX,
		MIN,
		CHANSE_MIN
	};

public:
	Expectimax(int max_depth, int coef_dist_enemys, int coef_dist_end);
	pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
	pair<float, pair<int, int>> expectiMax(const int depth, const NodeState nodeState,
		const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;

	vector<vector<shared_ptr<AbstractEnemy>>> get_combine_states_AstarEnemys(const vector<shared_ptr<AbstractEnemy>>& enemys, const Maze& maze) const;
	vector<vector<shared_ptr<AbstractEnemy>>> get_combine_states_RandomEnemys(const vector<shared_ptr<AbstractEnemy>>& enemys, const Maze& maze) const;

};

