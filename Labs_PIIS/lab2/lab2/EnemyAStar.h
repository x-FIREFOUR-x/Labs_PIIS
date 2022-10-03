#pragma once

#include <iostream>

#include "AbstractEnemy.h"

using namespace std;
class EnemyAStar : public AbstractEnemy
{
public:
	EnemyAStar(pair<int, int> coordinates);
	void move(Maze maze, const Player& player, const vector<shared_ptr<AbstractEnemy>> enemys, const int index_cur_enemy) override;
	char symbol_view() override;
};

