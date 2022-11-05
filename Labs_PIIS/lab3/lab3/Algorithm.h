#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "Maze.h"

class AbstractEnemy;
class Player;
class Entities;

class Algorithm
{
protected:
	enum Side {
		ENEMYS_SIDE = -1,
		PLAYER_SIDE = 1
	};

protected:
	const int MAX_VALUE = 100000;
	const int MIN_VALUE = -100000;
	const int MAX_DEPTH;
	const int COEF_DISTANCE_ENEMYS;
	const int COEF_DISTANCE_END;

public:
	Algorithm(int max_depth, int coef_dist_enemys, int coef_dist_end);
	virtual pair<int, int> coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const = 0;

protected:
	int calculate_value(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;
	bool is_terminal(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const;

	vector<Player> get_states_player(const Maze& maze, const Player& player) const;
	vector<vector<shared_ptr<AbstractEnemy>>> get_states_enemys(const Maze& maze, const vector<shared_ptr<AbstractEnemy>>& enemys) const;
	vector<Entities> get_states_entities(const Side side, const Maze& maze, const Entities& entities) const;

private:
	vector<shared_ptr<AbstractEnemy>> get_states_enemy(const Maze& maze, const shared_ptr<AbstractEnemy>& enemy) const;

	vector<vector<shared_ptr<AbstractEnemy>>> combine_states_two_enemys(const vector<vector<shared_ptr<AbstractEnemy>>>& first,
																		const vector<shared_ptr<AbstractEnemy>>& second) const;
	
	vector<vector<shared_ptr<AbstractEnemy>>> combine_states_two_enemys(const vector<shared_ptr<AbstractEnemy>>& first,
																		const vector<shared_ptr<AbstractEnemy>>& second) const;

	bool is_unique_state(const vector<shared_ptr<AbstractEnemy>>& state_enemys) const;
};

