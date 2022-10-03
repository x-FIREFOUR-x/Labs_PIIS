#pragma once
#include <iostream>

#include "AbstractEnemy.h"
#include "EnemyAStar.h"
#include "EnemyRandom.h"
#include "Maze.h"
#include "Player.h"

static class CreaterEnemy
{
public:
	static vector<shared_ptr<AbstractEnemy>> createEnemys(int amount_enemyR, int amount_enemyA, const Maze& maze, const Player& player);

private:
	static pair<int, int> randCoordinates(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys);
	static bool not_collision_other_enemys(pair<int, int>& coor_new_enemy, const vector<shared_ptr<AbstractEnemy>>& enemys);
};

