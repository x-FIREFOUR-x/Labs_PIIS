#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "Maze.h"
class AbstractEnemy;
class Player;

class Algorithm
{
protected:
	int MAX_VALUE = 1000;
	int MIN_VALUE = -1000;
	int MAX_DEPTH = 3;

public:
	virtual pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const = 0;

protected:
	vector<Player> get_states_player(const Maze& maze, const Player& player) const;
	vector<vector<shared_ptr<AbstractEnemy>>> get_states_enemys(const Maze& maze, const vector<shared_ptr<AbstractEnemy>>& enemys) const;

	int calculate_value(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;
	bool is_terminal(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;

private:
	vector<shared_ptr<AbstractEnemy>> get_states_enemy(const Maze& maze, const shared_ptr<AbstractEnemy>& enemy) const;
	vector<vector<shared_ptr<AbstractEnemy>>> combine_states_two_enemys(const vector<vector<shared_ptr<AbstractEnemy>>>& first, const vector<shared_ptr<AbstractEnemy>>& second) const;
	vector<vector<shared_ptr<AbstractEnemy>>> combine_states_two_enemys(const vector<shared_ptr<AbstractEnemy>>& first, const vector<shared_ptr<AbstractEnemy>>& second) const;

	bool is_unique_state(const vector<shared_ptr<AbstractEnemy>>& state_enemys) const;
};

