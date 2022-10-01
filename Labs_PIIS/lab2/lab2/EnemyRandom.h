#pragma once
#include <iostream>

#include "AbstractEnemy.h"

using namespace std;
class EnemyRandom: AbstractEnemy
{
public:
	EnemyRandom(pair<int,int> coordinates);
	void move(const Maze& maze, const Player& player) override;
	char symbol_view() override;
};

