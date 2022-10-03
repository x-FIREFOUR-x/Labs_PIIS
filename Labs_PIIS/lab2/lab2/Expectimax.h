#pragma once

#include "Algorithm.h"

using namespace std;
class Expectimax : public Algorithm
{
public:
	pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const override;

private:
};

