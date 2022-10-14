#pragma once

#include "Player.h"
#include "AbstractEnemy.h"


class Entities
{
public:
	Player player;
	vector<shared_ptr<AbstractEnemy>> enemys;

	Entities(const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys);
};

