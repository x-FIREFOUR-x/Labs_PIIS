#pragma once
#include <iostream>
#include <vector>

#include "Maze.h"
#include "Player.h"
#include "AbstractEnemy.h"

class Algorithm
{
public:
	virtual pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys) const = 0;

protected:
	vector<Player> get_states_player(const Maze& maze, const Player& player) const;

	vector<vector<AbstractEnemy*>> get_states_enemys(const Maze& maze, const vector<AbstractEnemy*>& enemys) const;

private:
	vector<AbstractEnemy*> get_states_enemy(const Maze& maze, const AbstractEnemy* enemy) const;
	vector<vector<AbstractEnemy*>> combine_states_two_enemys(const vector<vector<AbstractEnemy*>>& first, const vector<AbstractEnemy*>& second) const;
	vector<vector<AbstractEnemy*>> combine_states_two_enemys(const vector<AbstractEnemy*>& first, const vector<AbstractEnemy*>& second) const;

	bool is_unique_state(const vector<AbstractEnemy*>& state_enemys) const;
};

