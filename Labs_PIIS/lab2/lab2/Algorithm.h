#pragma once
#include <iostream>
#include <vector>

#include "Maze.h"
#include "Player.h"
#include "AbstractEnemy.h"

class Algorithm
{
public:
	virtual pair<int, int> coordinate_move(const Maze& maze, Player player, vector<AbstractEnemy*> enemys) = 0;

	vector<Player> get_states_player(const Maze& maze, const Player& player);

	vector<vector<AbstractEnemy*>> get_states_enemys(const Maze& maze, const vector<AbstractEnemy*>& enemys);

private:
	vector<AbstractEnemy*> get_states_enemy(const Maze& maze, const AbstractEnemy* enemy);
	vector<vector<AbstractEnemy*>> combine_states_two_enemys(const vector<vector<AbstractEnemy*>>& first, const vector<AbstractEnemy*>& second);
	vector<vector<AbstractEnemy*>> combine_states_two_enemys(const vector<AbstractEnemy*>& first, const vector<AbstractEnemy*>& second);

	bool is_unique_state(const vector<AbstractEnemy*>& state_enemys);
};

