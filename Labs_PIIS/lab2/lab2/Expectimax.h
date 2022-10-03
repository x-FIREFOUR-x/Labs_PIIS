#pragma once

#include "Algorithm.h"

using namespace std;
class Expectimax : Algorithm
{
public:
	pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys) const override;

private:
};

