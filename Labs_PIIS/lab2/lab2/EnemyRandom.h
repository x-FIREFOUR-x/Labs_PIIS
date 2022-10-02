#pragma once
#include <iostream>

#include "AbstractEnemy.h"

using namespace std;
class EnemyRandom: AbstractEnemy
{
public:
	EnemyRandom(pair<int,int> coordinates);
	void move(Maze maze, const Player& player, const vector<AbstractEnemy*> enemys, const int index_cur_enemy) override;
	char symbol_view() override;
};

